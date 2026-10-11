#!/usr/bin/env bash
set -euo pipefail
project_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$project_dir"
py=$(command -v python3.14 python3.13 python3.12 python3.11 python3.10 python3 | head -1)
"$py" -m venv .venv
.venv/bin/python -m pip install -r requirements.txt
mkdir -p vendor source build/extracted outputs
if [[ ! -d vendor/kirk_engine/.git ]]; then
  git clone https://github.com/tpunix/kirk_engine.git vendor/kirk_engine
fi
git -C vendor/kirk_engine checkout --detach ee09e86b743d1c147579ff21f46dd0874303daf3
cc -O2 -Ivendor/kirk_engine/kirk -Ivendor/kirk_engine/common \
  tools/pgd_tool.c vendor/kirk_engine/npdrm/pgd.c \
  vendor/kirk_engine/kirk/kirk_engine.c vendor/kirk_engine/kirk/crypto.c \
  vendor/kirk_engine/kirk/amctrl.c vendor/kirk_engine/kirk/bn.c \
  vendor/kirk_engine/kirk/ec.c -o vendor/pgd_tool
# DejaVu Sans Mono Bold: the font used for the Cyrillic glyphs
if [[ ! -f vendor/fonts/dejavu-fonts-ttf-2.37/ttf/DejaVuSansMono-Bold.ttf ]]; then
  mkdir -p vendor/fonts
  curl -fsSL https://github.com/dejavu-fonts/dejavu-fonts/releases/download/version_2_37/dejavu-fonts-ttf-2.37.tar.bz2 | tar -xj -C vendor/fonts
fi
# EBOOT.BIN decryptor: PPSSPP's PrxDecrypter (GPL) + libkirk, pinned tag, built with our main.cpp
pp=vendor/ppsspp-analysis
if [[ ! -x vendor/decrypt-prx ]]; then
  mkdir -p "$pp"/Core/ELF "$pp"/ext/libkirk "$pp"/Common
  base=https://raw.githubusercontent.com/hrydgard/ppsspp/v1.19.3
  curl -fsSL "$base/Core/ELF/PrxDecrypter.cpp" -o "$pp/PrxDecrypter.cpp"
  curl -fsSL "$base/Core/ELF/PrxDecrypter.h" -o "$pp/Core/ELF/PrxDecrypter.h"
  curl -fsSL "$base/LICENSE.TXT" -o "$pp/LICENSE.TXT"
  for f in AES.c AES.h SHA1.c SHA1.h bn.c ec.c kirk_engine.c kirk_engine.h kirk_common.h; do
    curl -fsSL "$base/ext/libkirk/$f" -o "$pp/ext/libkirk/$f"
  done
  cp tools/prx/main.cpp "$pp/main.cpp"; cp tools/prx/Common/*.h "$pp/Common/"
  ( cd "$pp" && cc -O2 -c ext/libkirk/AES.c ext/libkirk/SHA1.c ext/libkirk/bn.c ext/libkirk/ec.c ext/libkirk/kirk_engine.c -I. \
    && c++ -std=c++17 -O2 -I. main.cpp PrxDecrypter.cpp AES.o SHA1.o bn.o ec.o kirk_engine.o -o ../decrypt-prx )
fi
printf '%s\n' 'Ready: .venv, vendor/pgd_tool, vendor/decrypt-prx. Install PPSSPP separately; see SETUP.md.'
