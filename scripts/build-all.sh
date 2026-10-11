#!/usr/bin/env bash
# Полная сборка русской версии из исходного ISO: scripts/build-all.sh [выходной.iso]
# Нужны: source/Diabolik-MoreBlood-JPN.iso и установленные инструменты (bash scripts/setup-tools.sh).
set -euo pipefail
cd "$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
iso=source/Diabolik-MoreBlood-JPN.iso
out="${1:-outputs/Diabolik-MoreBlood-RU.iso}"
py=.venv/bin/python
[[ -f "$iso" ]] || { echo "Нет $iso: положите туда исходный японский ISO (см. docs/SETUP.md)"; exit 1; }
for t in vendor/pgd_tool vendor/decrypt-prx "$py"; do [[ -e "$t" ]] || { echo "Нет $t: запустите bash scripts/setup-tools.sh"; exit 1; }; done
sevenzip=$(command -v 7zz || command -v 7z || ls vendor/7zip/7zz 2>/dev/null || true)
[[ -n "$sevenzip" ]] || { echo "Нужен 7-Zip (7z или 7zz)"; exit 1; }
mkdir -p build/extracted outputs analysis
if [[ ! -f build/extracted/INSTALL.CPK ]]; then
  "$sevenzip" x -y "$iso" -obuild/extracted >/dev/null
  vendor/pgd_tool decrypt build/extracted/PSP_GAME/INSDIR/INSTALL.DNS build/extracted/INSTALL.CPK
  $py tools/cpk.py build/extracted/INSTALL.CPK build/extracted/resources >/dev/null
fi
[[ -f analysis/EBOOT.decrypted.bin ]] || vendor/decrypt-prx build/extracted/PSP_GAME/SYSDIR/EBOOT.BIN analysis/EBOOT.decrypted.bin
[[ -f translation/corpus/records.json ]] || $py tools/prepare_corpus.py
if [[ ! -d analysis/scenes ]]; then
  $py tools/analyze_game_text.py >/dev/null
fi
$py -W ignore tools/build_scene.py --crisp
$py -W ignore tools/build_game.py "$out"
echo "Готово: $out"
