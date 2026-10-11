Расшифровка `EBOOT.BIN` (~PSP → ELF). Здесь только наш `main.cpp` и заглушки заголовков `Common/*.h`.
Код дешифровки (`PrxDecrypter.cpp`, `ext/libkirk`) принадлежит проекту PPSSPP (GPL): `scripts/setup-tools.sh` скачивает его с GitHub
(тег v1.19.3) и собирает `vendor/decrypt-prx`. В Git эти файлы не попадают.
