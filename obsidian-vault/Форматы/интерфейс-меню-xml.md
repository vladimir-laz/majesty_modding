---
tags: [format, xml, interface, menu, buttons]
created: 2026-06-05
updated: 2026-06-05
---
# Меню зданий — `interface/dynamic/menu/*.xml`

## Описание
XML-файлы, описывающие **панель кнопок** в окне выбранного здания (что
видит игрок, кликнув на замок, гильдию, логово, кузницу). Кодировка UTF-8.
Корень — `<controlGroups>` → `<controlGroup id="...">` → строки `<Row>` →
кнопки `<Button_N>`.

## Структура
```xml
<controlGroup id="guild_warrior_main">
  <controlsLayout>
    <rectangularLayout columns="4" offset="3" />
  </controlsLayout>
  <Row>
    <Button_1 action="RecruitHeroAction" stateAction="CheckRecruitAction">
      <appearance texture="BUT_hire_Warrior" autoTexture="TEX_MASK"
                  autoHint="false" propertyBlock="action_but"
                  userdata="hero_warrior" />
    </Button_1>
    ...
  </Row>
</controlGroup>
```

## Ключевые атрибуты кнопки
- `action="..."` — что делает кнопка. Частые действия:
  - `RecruitHeroAction` — нанять героя.
  - `BuildAction` — построить здание.
  - `BuildUpgradeAction` — улучшить здание.
  - `BuildSpellAction` — применить заклинание/приказ.
  - `InventAction` — исследовать изобретение/умение.
- `stateAction="Check...Action"` — проверка доступности (когда кнопка
  активна/серая).
- `<appearance texture="BUT_*" userdata="..." />`:
  - `texture` — имя текстуры из [[texture-units-xml]] (`BUT_hire_Knight`).
  - `userdata` — **что именно** делает кнопка: id сущности/изобретения
    (`hero_knight`, `knight_gouge`, `unique_tower_guard`). Связывает кнопку
    с записью в [[shops-set]].

## Как добавить кнопку (паттерн рыцаря)
В `guild_warrior_menu.xml` рядом с `Button_1 (hero_warrior)` добавлен
`Button_2` с `userdata="hero_knight"` и текстурой `BUT_hire_Knight`, а
третий `<Row>` целиком отдан под умения рыцаря (`knight_imp_attack`,
`knight_resistance_buff`, `knight_swordmaster_buff`, `knight_gouge`). См.
[[рыцарь]].

## Связь слоёв
Кнопка (меню) → `userdata` → запись в [[shops-set]] (цена/условия) →
`Entity`/`invention` → [[def-сущности]] (что это за объект). Текстура
кнопки → [[texture-units-xml]] → `.dds`.

## Файлы-примеры
- `castle_menu.xml`, `mks_castle_menu.xml` — меню замка (правят
  [[элитные-башни]], [[мини-сборка]]).
- `guild_warrior_menu.xml` — гильдия воинов ([[рыцарь]], [[мини-сборка]]).
- `mks_smithy_menu.xml` — кузница ([[4-кузница-у-монстров]]).
- `logovo_*_menu.xml` — логова ([[мини-сборка]]).

## Связанные заметки
- [[texture-units-xml]] · [[shops-set]] · [[loctable-xml]]
- [[меню-постройки-и-апгрейды]]
