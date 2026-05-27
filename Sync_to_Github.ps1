# ================================================================
# Sync_to_Github.ps1
# Local-first GitHub sync for nugget-fwlib, with optional automatic
# XC8 ASM Revelator release publishing.
#
# Normal sync:
#   .\Sync_to_Github.ps1 "Your commit message here"
#
# Publish the local 3.6 Revelator release into both repos:
#   .\Sync_to_Github.ps1 -PublishRevelatorRelease -CommitMessage "Publish Revelator v3.6"
#
# Dry-run style local update without pushing:
#   .\Sync_to_Github.ps1 -PublishRevelatorRelease -CommitMessage "Publish Revelator v3.6" -NoPush
# ================================================================

param(
    [Parameter(Position = 0)]
    [string]$CommitMessage,

    [switch]$PublishRevelatorRelease,

    [string]$ReleaseDir = (Join-Path $PSScriptRoot "..\3.6"),

    [string]$Xc8RepoDir = (Join-Path $PSScriptRoot "..\xc8-asm-revelator"),

    [switch]$NoPush
)

$ErrorActionPreference = "Stop"

function Resolve-ExistingPath {
    param(
        [Parameter(Mandatory = $true)][string]$Path,
        [Parameter(Mandatory = $true)][string]$Label
    )

    if (-not (Test-Path -LiteralPath $Path)) {
        throw "$Label not found: $Path"
    }

    return (Resolve-Path -LiteralPath $Path).Path
}

function Invoke-Git {
    param([Parameter(ValueFromRemainingArguments = $true)][string[]]$GitArgs)
    & git @GitArgs
    if ($LASTEXITCODE -ne 0) {
        throw "git $($GitArgs -join ' ') failed with exit code $LASTEXITCODE"
    }
}

function Assert-CleanRepo {
    param([string]$RepoDir)

    Push-Location $RepoDir
    try {
        $dirty = git status --porcelain
        if ($dirty) {
            throw "Repository has uncommitted changes before publishing: $RepoDir"
        }
    }
    finally {
        Pop-Location
    }
}

function Update-ReadmeBlock {
    param(
        [string]$ReadmePath,
        [string]$StartMarker,
        [string]$EndMarker,
        [string]$Block
    )

    $text = Get-Content -LiteralPath $ReadmePath -Raw
    $pattern = "(?s)$([regex]::Escape($StartMarker)).*?$([regex]::Escape($EndMarker))"
    $replacement = "$StartMarker`r`n$Block`r`n$EndMarker"

    if ($text -match $pattern) {
        $text = [regex]::Replace($text, $pattern, $replacement)
    }
    else {
        $unmarkedPattern = "(?s)## Revelator 3\.6 analysis\s+The current assembly review artifacts are generated with XC8 ASM Revelator v3\.6:\s+.*?- \[xc8_asm_revelator_v3_6_gcbasic\.py\]\(xc8_asm_revelator_v3_6_gcbasic\.py\)"
        if ($text -match $unmarkedPattern) {
            $text = [regex]::Replace($text, $unmarkedPattern, $replacement)
            Set-Content -LiteralPath $ReadmePath -Value $text -NoNewline
            return
        }

        $insertAfter = "The Nugget CLI Monitor is the marquee application for ``nugget-fwlib``."
        $text = $text -replace [regex]::Escape($insertAfter), "$insertAfter`r`n`r`n$replacement"
    }

    Set-Content -LiteralPath $ReadmePath -Value $text -NoNewline
}

function Test-PythonFile {
    param([string]$Path)

    & python -m py_compile $Path
    if ($LASTEXITCODE -ne 0) {
        throw "Python syntax validation failed: $Path"
    }
}

function Test-JsonFile {
    param([string]$Path)

    & python -m json.tool $Path | Out-Null
    if ($LASTEXITCODE -ne 0) {
        throw "JSON validation failed: $Path"
    }
}

function Commit-And-Push {
    param(
        [string]$RepoDir,
        [string]$Message,
        [switch]$SkipPush
    )

    Push-Location $RepoDir
    try {
        Invoke-Git status --short
        Invoke-Git add -A

        $pending = git status --porcelain
        if (-not $pending) {
            Write-Host "No changes to commit in $RepoDir" -ForegroundColor Yellow
            return
        }

        Invoke-Git commit -m $Message

        if (-not $SkipPush) {
            Invoke-Git push origin main
        }
    }
    finally {
        Pop-Location
    }
}

function Publish-RevelatorRelease {
    param(
        [string]$ReleasePath,
        [string]$NuggetRepoPath,
        [string]$Xc8RepoPath,
        [string]$Message,
        [switch]$SkipPush
    )

    $release = Resolve-ExistingPath $ReleasePath "Release directory"
    $nuggetRepo = Resolve-ExistingPath $NuggetRepoPath "nugget-fwlib repository"
    $xc8Repo = Resolve-ExistingPath $Xc8RepoPath "xc8-asm-revelator repository"

    $files = @{
        Tool = "xc8_asm_revelator_v3_6_gcbasic.py"
        Manual = "XC8_ASM_Revelator_v3_6_GCBASIC_Operators_Manual.md"
        Report = "nugget_cli_monitor_revelator_v3_6.md"
        Triage = "nugget_cli_monitor_triage_v3_6.md"
        Json = "nugget_cli_monitor_revelator_v3_6.json"
    }

    foreach ($file in $files.Values) {
        Resolve-ExistingPath (Join-Path $release $file) "Required release file" | Out-Null
    }

    Write-Host "Checking repositories are clean before publishing..." -ForegroundColor Cyan
    Assert-CleanRepo $xc8Repo
    Assert-CleanRepo $nuggetRepo

    Write-Host "Pulling latest repositories..." -ForegroundColor Cyan
    Push-Location $xc8Repo
    try { Invoke-Git pull --rebase origin main } finally { Pop-Location }
    Push-Location $nuggetRepo
    try { Invoke-Git pull --rebase origin main } finally { Pop-Location }

    Assert-CleanRepo $xc8Repo
    Assert-CleanRepo $nuggetRepo

    Write-Host "Copying XC8 ASM Revelator v3.6 files..." -ForegroundColor Cyan
    Copy-Item -LiteralPath (Join-Path $release $files.Tool) -Destination (Join-Path $xc8Repo "xc8_asm_revelator.py") -Force
    Copy-Item -LiteralPath (Join-Path $release $files.Manual) -Destination (Join-Path $xc8Repo "docs\operators_guide.md") -Force

    $xc8Readme = Join-Path $xc8Repo "README.md"
    $xc8Text = Get-Content -LiteralPath $xc8Readme -Raw
    if ($xc8Text -notmatch "Current release:\s+\*\*v3\.6\*\*") {
        $xc8Text = $xc8Text -replace "(# XC8 ASM Revelator\s*)", "`$1`r`nCurrent release: **v3.6**.`r`n"
    }
    $xc8Text = $xc8Text -replace "See \[docs/operators_guide\.md\]\(docs/operators_guide\.md\) for .*?operator\s+guide", "See [docs/operators_guide.md](docs/operators_guide.md) for the v3.6 operator guide"
    Set-Content -LiteralPath $xc8Readme -Value $xc8Text -NoNewline

    Write-Host "Copying Nugget CLI Monitor Revelator v3.6 artifacts..." -ForegroundColor Cyan
    $monitorDir = Join-Path $nuggetRepo "apps\nugget_cli_monitor"
    Copy-Item -LiteralPath (Join-Path $release $files.Tool) -Destination (Join-Path $monitorDir $files.Tool) -Force
    Copy-Item -LiteralPath (Join-Path $release $files.Report) -Destination (Join-Path $monitorDir $files.Report) -Force
    Copy-Item -LiteralPath (Join-Path $release $files.Report) -Destination (Join-Path $monitorDir "nugget_cli_monitor.lst.programmer_review.md") -Force
    Copy-Item -LiteralPath (Join-Path $release $files.Triage) -Destination (Join-Path $monitorDir $files.Triage) -Force
    Copy-Item -LiteralPath (Join-Path $release $files.Json) -Destination (Join-Path $monitorDir $files.Json) -Force

    $oldTool = Join-Path $monitorDir "xc8_assembly_revelator_v4_0.py"
    if (Test-Path -LiteralPath $oldTool) {
        Remove-Item -LiteralPath $oldTool -Force
    }

    $block = @"
## Revelator 3.6 analysis

The current assembly review artifacts are generated with XC8 ASM Revelator v3.6:

- [nugget_cli_monitor_revelator_v3_6.md](nugget_cli_monitor_revelator_v3_6.md)
- [nugget_cli_monitor_triage_v3_6.md](nugget_cli_monitor_triage_v3_6.md)
- [nugget_cli_monitor_revelator_v3_6.json](nugget_cli_monitor_revelator_v3_6.json)
- [xc8_asm_revelator_v3_6_gcbasic.py](xc8_asm_revelator_v3_6_gcbasic.py)
"@
    Update-ReadmeBlock `
        -ReadmePath (Join-Path $monitorDir "README.md") `
        -StartMarker "<!-- REVELATOR_RELEASE_START -->" `
        -EndMarker "<!-- REVELATOR_RELEASE_END -->" `
        -Block $block.Trim()

    Write-Host "Validating release files..." -ForegroundColor Cyan
    Test-PythonFile (Join-Path $xc8Repo "xc8_asm_revelator.py")
    Test-PythonFile (Join-Path $monitorDir $files.Tool)
    Test-JsonFile (Join-Path $monitorDir $files.Json)

    Commit-And-Push -RepoDir $xc8Repo -Message $Message -SkipPush:$SkipPush
    Commit-And-Push -RepoDir $nuggetRepo -Message $Message -SkipPush:$SkipPush
}

if (-not $CommitMessage) {
    Write-Host ""
    Write-Host "SYNC FAILED" -ForegroundColor Red
    Write-Host "Usage:" -ForegroundColor Yellow
    Write-Host '  .\Sync_to_Github.ps1 "commit message"'
    Write-Host '  .\Sync_to_Github.ps1 -PublishRevelatorRelease -CommitMessage "Publish Revelator v3.6"'
    Write-Host ""
    exit 1
}

if ($PublishRevelatorRelease) {
    Publish-RevelatorRelease `
        -ReleasePath $ReleaseDir `
        -NuggetRepoPath $PSScriptRoot `
        -Xc8RepoPath $Xc8RepoDir `
        -Message $CommitMessage `
        -SkipPush:$NoPush
    exit 0
}

Write-Host ""
Write-Host "============================================================"
Write-Host " Nugget FWLIB Local-to-GitHub Sync"
Write-Host "============================================================"
Write-Host "Commit message: $CommitMessage"
Write-Host "============================================================"
Write-Host ""

Write-Host "Checking current Git status..." -ForegroundColor Cyan
git status

Write-Host ""
Write-Host "Pulling latest GitHub changes with rebase..." -ForegroundColor Cyan
Invoke-Git pull --rebase origin main

Write-Host ""
Write-Host "Adding local changes..." -ForegroundColor Cyan
Invoke-Git add -A

Write-Host ""
Write-Host "Status after git add:" -ForegroundColor Cyan
git status

$Pending = git status --porcelain

if (-not $Pending) {
    Write-Host ""
    Write-Host "NO LOCAL CHANGES TO COMMIT" -ForegroundColor Yellow
    Write-Host "Repository is already clean after pull/rebase."
    Write-Host ""
    exit 0
}

Write-Host ""
Write-Host "Committing..." -ForegroundColor Cyan
Invoke-Git commit -m "$CommitMessage"

if (-not $NoPush) {
    Write-Host ""
    Write-Host "Pushing to GitHub..." -ForegroundColor Cyan
    Invoke-Git push origin main
}

Write-Host ""
Write-Host "============================================================" -ForegroundColor Green
Write-Host "                 SYNC COMPLETE OK" -ForegroundColor Green
Write-Host "============================================================" -ForegroundColor Green
Write-Host " Local work is committed and pushed to GitHub." -ForegroundColor Green
Write-Host "============================================================" -ForegroundColor Green
Write-Host ""
