# ================================================================
# sync_to_github.ps1
# Local-first GitHub sync for nugget-fwlib
#
# Use:
#   .\sync_to_github.ps1 "Your commit message here"
#
# Strategy:
#   1. Show current status
#   2. Pull/rebase latest GitHub changes
#   3. Add all local changes
#   4. Commit them
#   5. Push to GitHub
# ================================================================

$ErrorActionPreference = "Stop"

if ($args.Count -lt 1) {
    Write-Host ""
    Write-Host "SYNC FAILED" -ForegroundColor Red
    Write-Host "Usage:" -ForegroundColor Yellow
    Write-Host '  .\sync_to_github.ps1 "commit message"'
    Write-Host ""
    exit 1
}

$CommitMessage = $args[0]

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
git pull --rebase origin main

Write-Host ""
Write-Host "Adding local changes..." -ForegroundColor Cyan
git add -A

Write-Host ""
Write-Host "Status after git add:" -ForegroundColor Cyan
git status

# Check whether there is anything to commit.
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
git commit -m "$CommitMessage"

Write-Host ""
Write-Host "Pushing to GitHub..." -ForegroundColor Cyan
git push origin main

Write-Host ""
Write-Host "============================================================" -ForegroundColor Green
Write-Host "                 SYNC COMPLETE OK" -ForegroundColor Green
Write-Host "============================================================" -ForegroundColor Green
Write-Host " Local work is committed and pushed to GitHub." -ForegroundColor Green
Write-Host "============================================================" -ForegroundColor Green
Write-Host ""

