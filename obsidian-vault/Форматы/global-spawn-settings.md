---
tags: [format, set, spawn, gameData]
created: 2026-06-05
updated: 2026-06-05
---
# `global_spawn_settings.set` — программы спавна

## Описание
`gameData/spawn/global_spawn_settings.set` — реестр **программ спавна**:
именованных правил «кого, сколько, как часто и при каких условиях»
порождать на карте. На программы по имени ссылается
`spawner_extender.global_spawn_progs` в [[def-сущности|.def]] зданий
(башни, логова). Формат — [[set-конфиги|вложенные `{}`]].

## Структура одной программы
```
{"guard_in_tower_spawner"
    {"spawn type" units}        ; units | buildings
    {raw guard}                 ; какую сущность спавнить (id юнита/здания)
    {Nationality Same}          ; Same | Enemy
    {level 0}
    {"AI task" {task none}}      ; поведение после спавна
    {postspawn} {postspawn_i 1}
    {gold 0}
    {count "1 1"}               ; диапазон количества за один спавн (min max)
    {"spawn time" 15}           ; период спавна, сек
    {"max count" 1}             ; потолок одновременно живых от этой программы
}
```

## Условный спавн (`Prerequsities`)
Программа может срабатывать только при выполнении условия:
```
{"guard_in_tower_spawner2"
    {Prerequsities_list building_level}
    {Prerequsities
        {building_level {Operation ">="} {Level 2}}
    }
    {raw guard} ...
}
```
Это **ключевой приём «второго стражника»**: вторая программа = клон первой
с условием `building_level >= 2`. Пока башня 1-го уровня — работает только
первая программа; со 2-го включается вторая, давая второго лучника (см.
[[второй-стражник]], [[система-спавна]]).

Другие виды предусловий, встречающиеся в файле:
- `{Prerequsities {city_value {Min_city_summ} {Max_city_summ}}}` — по
  «ценности» города.
- `{Prerequsities {dead_heroes {Min_dead_heroes} {Max_dead_heroes}}}` —
  по числу павших героев (например, спавн кладбища `grave_yard`).
- `{"First wave"}` — флаг первой волны.

## Спавн зданий и AI-задачи
- `{"spawn type" buildings}` спавнит здания (кладбище `graveyard`).
- В `AI task` бывают маршруты/агрессия (`berserk_agressive`, waypoint
  `monster_way`) для атакующих волн.

## Кто правит файл
- [[второй-стражник]] — добавляет `*_spawner2` с условием уровня.
- [[мини-сборка]] — большой файл (~3000 строк) со спавном всех монстров
  логов.

## Связанные заметки
- [[система-спавна]] — игровая механика
- [[def-сущности]] — `spawner_extender`, который ссылается сюда
- [[set-конфиги]]
