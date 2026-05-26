# ================================================================
# flash_reaction_game_snap.ps1
# Program Nugget FWLIB Reaction Game to PIC16F18424 using SNAP
#
# Confirmed working command:
#   ipecmd.exe -TPPK4 -TS021038102RYN013580 -P16F18424 -F".\030_reaction_game.hex" -M -Y -OL
#
# Important lesson captured:
#   -TPPK4 selects the SNAP/PICkit4-class programmer family for IPECMD.
#   -TS021038102RYN013580 selects the exact SNAP serial number.
#   Do NOT use -TPSNAP.
#   Do NOT use -S021038102RYN013580.
#   In IPECMD, -S means SQTP file and can cause: SQTP File not found.
# ================================================================

$ErrorActionPreference = "Stop"

$IpeCmd  = "C:\Program Files\Microchip\MPLABX\v6.30\mplab_platform\mplab_ipe\ipecmd.exe"
$HexFile = ".\030_reaction_game.hex"

if (-not (Test-Path $IpeCmd)) {
    Write-Host ""
    Write-Host "IPE COMMAND NOT FOUND" -ForegroundColor Red
    Write-Host $IpeCmd -ForegroundColor Red
    exit 1
}

if (-not (Test-Path $HexFile)) {
    Write-Host ""
    Write-Host "HEX FILE NOT FOUND" -ForegroundColor Red
    Write-Host $HexFile -ForegroundColor Red
    exit 1
}

$ResolvedHex = (Resolve-Path $HexFile).Path

# Build arguments explicitly.
# This avoids PowerShell backtick/line-continuation mistakes.
$ArgsList = @(
    "-TPPK4",
    "-TS021038102RYN013580",
    "-P16F18424",
    "-F$HexFile",
    "-M",
    "-Y",
    "-OL"
)

Write-Host ""
Write-Host "============================================================"
Write-Host " Nugget FWLIB Reaction Game Flash Script"
Write-Host "============================================================"
Write-Host "Device:        PIC16F18424"
Write-Host "Programmer:    SNAP using -TPPK4"
Write-Host "SNAP S/N:      021038102RYN013580"
Write-Host "HEX file:      $ResolvedHex"
Write-Host "IPE command:   $IpeCmd"
Write-Host "============================================================"
Write-Host ""

Write-Host "COMMAND TO BE RUN:"
Write-Host "`"$IpeCmd`" $($ArgsList -join ' ')" -ForegroundColor Cyan
Write-Host ""

& $IpeCmd @ArgsList

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "============================================================" -ForegroundColor Green
    Write-Host "                 FLASH COMPLETE OK" -ForegroundColor Green
    Write-Host "============================================================" -ForegroundColor Green
    Write-Host " PIC16F18424 programmed and verified successfully." -ForegroundColor Green
    Write-Host " Reaction Game is now loaded on the REDBOARD." -ForegroundColor Green
    Write-Host "============================================================" -ForegroundColor Green
    Write-Host ""
} else {
    Write-Host ""
    Write-Host "============================================================" -ForegroundColor Red
    Write-Host "                    FLASH FAILED" -ForegroundColor Red
    Write-Host "============================================================" -ForegroundColor Red
    Write-Host " Exit code: $LASTEXITCODE" -ForegroundColor Red
    Write-Host ""
    Write-Host "The command printed above must show exactly:" -ForegroundColor Red
    Write-Host "  -TPPK4 -TS021038102RYN013580 -P16F18424 -F.\030_reaction_game.hex -M -Y -OL"
    Write-Host ""
    Write-Host "If you see -S021038102RYN013580 anywhere in the printed command, the wrong script is being run."
    Write-Host "============================================================" -ForegroundColor Red
    Write-Host ""
    exit $LASTEXITCODE
}
