# Индекс: Форматы
Последнее обновление: 2026-06-05

Справочник по форматам файлов Majesty 2, встречающимся в модах.

## ⭐ Карта файлов
- [[карта-игровых-файлов]] — **где какой конфиг игры лежит** (полная карта: сущности, gameData, set, interface, localization + внешние `spells.xml`/`rpg_params.xml`/`caravans.set`/`potions.set`). Стартовая точка «куда смотреть».

## Конфиги во вложенных скобках `{}`
- [[set-конфиги]] — общий синтаксис формата `.set`/`.def`: вложенные `{}`, `;` комментарии, `{ключ значение}`, `{version ...}`. **Читать первой** перед остальными.
- [[def-сущности]] — `.def`: описание entity (здание/юнит/предмет), экстендеры, раскрытые инклюды с маркерами `;#line`, важные блоки (Health, building, Upgrades, spawner_extender, EntityPrimeCost)
- [[shops-set]] — `set/trading/shops.set`: меню постройки в замке (здания, цена, лимиты, апгрейды, изобретения, наём героев, оружие/броня)
- [[global-spawn-settings]] — `gameData/spawn/global_spawn_settings.set`: программы спавна существ (raw, count, spawn time, max count, Prerequsities)

## Миссии
- [[mission-mi]] — формат файла миссии `.mi`: спавн логов (`helper/spawn_program_collection`, типы `task`, флаг First wave), стартовые деньги (`{"kingdoms"}`), доступность построек. Спавн/деньги кампании задаются ЗДЕСЬ (per-mission), а не глобально.

## Интерфейс
- [[интерфейс-меню-xml]] — `interface/dynamic/menu/*.xml`: меню зданий, кнопки действий (Build/Recruit/Invent/Upgrade), `userdata`, `texture`
- [[game-window-xml]] — `interface/enGUIne/Skins/.../game_window.xml`: окно игры; здесь живёт панель скорости (`COUNTER_game_speed`)
- [[texture-units-xml]] — `interface/enGUIne/texture_units.xml`: реестр текстур UI (имя → файл `.dds` + смещение `i_tuv`)

## Данные и тексты
- [[rpg-params-xml]] — `gameData/units/rpg_params.xml`: **базовые характеристики** (сила/ловкость/ум/выносливость, 0–20) и статы ВСЕХ юнитов; секции `<Heroes>`/`<Citizens>`/`<Monsters>`/`<Buildings>`
- [[unit-decour-xml]] — `gameData/units/unit_decour.xml`: **статы оружия/брони** (DPS `f_dps_*`, защита `f_defence_*`, бонусы характеристик) + визуальная экипировка
- [[inventions-graphml]] — `gameData/inventions/inventions.graphml`: дерево изобретений в формате yEd (узлы-изобретения, рёбра-зависимости)
- [[loctable-xml]] — `localization/M2_mod.loctable.xml`: локализация в формате Excel XML (ключи `#KEY` → текст)
- [[бинарные-ассеты]] — `.mdl`/`.mesh`/`.anm`/`.dds`/`.material`/`.tuv`: модели, анимации, текстуры (не редактируются текстом)
