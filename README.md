# Diabolik Lovers More Blood (PSP) — русский перевод

Русская локализация японской версии для PSP: диалоги, интерфейс, картинки, шрифт. Переводчик: Randommist.

В репозитории только перевод и скрипты сборки. Игры в нём нет: нужен ваш собственный японский ISO.

## Сборка

```bash
bash scripts/setup-tools.sh                              # один раз: Python-окружение, шрифт, pgd_tool, decrypt-prx
cp /путь/к/игре.iso source/Diabolik-MoreBlood-JPN.iso
bash scripts/build-all.sh                                # → outputs/Diabolik-MoreBlood-RU.iso
```

Подробности и зависимости — [docs/SETUP.md](docs/SETUP.md). Исходный ISO скрипты не меняют.

## Структура

```
translation/
  scenes/             по одному JSON на сцену: scene-NNN.json (плюс первые черновые блоки first, road, school и др.)
  images/             русские PNG (ru/) и jobs.json — картинки интерфейса
  opening.json        строки вступления
tools/                скрипты сборки (см. tools/README.md)
scripts/              setup-tools.sh, build-all.sh
docs/                 SETUP.md (сборка), QUALITY.md (правила перевода)
```

Локально создаются (в Git не попадают): `source/` (ваш ISO), `vendor/` (инструменты), `build/`, `analysis/` (промежуточные файлы), `translation/corpus/` (японский корпус из вашего ISO), `outputs/` (готовые ISO).

## Формат перевода

Запись в `scenes/scene-NNN.json`: `scene` + `index` + `action` + `ja` (оригинал для сверки) + `speaker` + `ru`. Ключ — `scene` + `index`, а не глобальный `id`. Правила качества: [docs/QUALITY.md](docs/QUALITY.md).

## Запуск

Откройте ISO в [PPSSPP](https://www.ppsspp.org/download/). На реальной PSP образ работает только с кастомной прошивкой (ARK, PRO, ME): `EBOOT.BIN` в образе без подписи Sony. `INSTALL.DNS` перешифрован `pgd_tool` с параметрами оригинала; на железе это не проверялось.
