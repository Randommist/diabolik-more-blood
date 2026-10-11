# Сборка русской версии из исходного ISO

Нужен собственный образ японской версии PSP-игры (в репозитории его нет). Всё остальное — перевод, картинки, шрифт, инструменты — лежит в репозитории.

## 1. Зависимости

Git, Python 3.10+ с venv, C/C++-компилятор и make, 7-Zip (`7z` или `7zz` в PATH или `vendor/7zip/7zz`).

```bash
# Debian/Ubuntu
sudo apt install git python3 python3-venv build-essential p7zip-full
# macOS
brew install git python 7zip
```

## 2. Клонирование и инструменты

```bash
git clone <адрес репозитория> diabolik-more-blood
cd diabolik-more-blood
bash scripts/setup-tools.sh
```

Скрипт создаёт `.venv` (Pillow, capstone, pyelftools), скачивает шрифт DejaVu 2.37, собирает `vendor/pgd_tool` (шифрование INSTALL.DNS) и `vendor/decrypt-prx` (расшифровка EBOOT.BIN). Нужна сеть; всё это остаётся в `vendor/` и в Git не попадает.

## 3. Образ игры

Положите неизменённый ISO в `source/Diabolik-MoreBlood-JPN.iso`. Исходный файл скрипты не меняют.

## 4. Сборка

```bash
bash scripts/build-all.sh                  # → outputs/Diabolik-MoreBlood-RU.iso
bash scripts/build-all.sh путь/к/файлу.iso # другой выходной файл
```

Шаги: извлечение ISO и INSTALL.CPK, расшифровка EBOOT, подготовка корпуса, генерация шрифта, затем `tools/build_game.py` собирает сценарии, 60 картинок (`translation/images`), клавиатуру, названия мест, строки EBOOT и пишет ISO. Сборка детерминирована: из одного исходного ISO получается один и тот же результат.

## 5. Запуск

Откройте ISO в [PPSSPP](https://www.ppsspp.org/download/) . На реальной PSP образ работает только с кастомной прошивкой (ARK, PRO, ME): EBOOT в образе без подписи Sony.

## 6. Работа над переводом

Правьте `translation/scenes/scene-NNN.json`, пересоберите ISO. Правила — [QUALITY.md](QUALITY.md); картинки — [../translation/images/README.md](../translation/images/README.md).
