# tools — скрипты сборки

`scripts/build-all.sh` вызывает их по порядку.

| Файл | Что делает |
| --- | --- |
| `cpk.py` | Распаковка INSTALL.CPK. |
| `extract_images.py`, `tim2.py` | Извлечение картинок из ISO и чтение формата TIM2. |
| `stcm.py` | Разбор сценариев STCM2L. |
| `prepare_corpus.py` | Японский корпус `translation/corpus/` из ресурсов ISO. |
| `analyze_game_text.py`, `engine_layout.py` | Анализ сценариев и EBOOT, метрики окон текста. |
| `build_scene.py` | Генерация русского шрифта (glyph-таблицы) и вступления. |
| `glyphs.py` | Кодировка русских букв и знаков в коды шрифта. |
| `reflow.py` | Перенос строк по ширине окна. |
| `script_patch.py` | Перестройка сценария с пересчётом указателей. |
| `patch_keyboard.py`, `patch_default_name.py`, `patch_places.py`, `patch_strings.py` | Клавиатура ввода имени, имя по умолчанию, названия мест, строки меню и окон в EBOOT. |
| `build_images.py`, `png_to_tim2.py` | PNG → TIM2 и подстановка в INSTALL.CPK. |
| `patch_iso.py` | Запись изменённых файлов в ISO. |
| `build_game.py` | Главный сборщик, собирает всё и пишет ISO. |
| `pgd_tool.c`, `prx/` | Шифрование INSTALL.DNS и расшифровка EBOOT; собираются `scripts/setup-tools.sh`. |
