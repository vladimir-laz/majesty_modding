---
tags: [format, def, entity, extenders, includes]
created: 2026-06-05
updated: 2026-06-05
---
# Формат `.def` — описание сущности (entity)

## Описание
`.def` описывает игровую **сущность**: здание (`entity/buildings/`), юнита
(`entity/units/`), предмет (`entity/items/`). Синтаксис — [[set-конфиги|вложенные `{}`]].
Корень всегда `{entity ... }`. Сущность собрана из **экстендеров** —
именованных блоков-компонентов, каждый отвечает за свою подсистему.

## Раскрытые инклюды (`;#line`)
Исходно `.def` собирается из множества `(include "...inc")`. В поставке
файлы уже **препроцессены**: инклюды раскрыты, а границы помечены
комментариями:

```
;#line 8: 	(include "/properties/buildings/extenders/level.inc")
;#line 8: properties/buildings/extenders/level.inc BEGIN
{"Level"
	{MaxLevel 1}
	{CurrentLevel 1}
}
;#line 8: properties/buildings/extenders/level.inc END
```

Это даёт две вещи: (1) видно, **откуда** взят каждый блок (общий
`/properties/...` или локальный `entity/.../extenders/...`); (2) видно, что
именно правил мод — локальные `extenders/*.inc` рядом с `.def` (как
`mks_smithy/extenders/upgrades.inc`) часто и есть точка изменения.

## Ключевые экстендеры зданий
| Блок | Что задаёт |
|---|---|
| `{"Level" {MaxLevel} {CurrentLevel}}` | уровни здания |
| `{"Health" {value_new {rpg_building}}}` | здоровье (берётся из RPG-профиля) |
| `{"building" {building_value} {stamp} {CashMachine/CastleCashMachine ...}}` | экономика, налоговая «касса», визуальный штамп |
| `{"Upgrades" {available {...}}}` | улучшения: `{health N}`, `{cost "money" N}`, `{add_action}`, `{remove_action}` |
| `{"spawner_extender" {global_spawn_progs "..."}}` | какие программы спавна запускает (см. [[система-спавна]]) |
| `{"EntityPrimeCost" {Cost N}}` | базовая стоимость в экономике |
| `{"guard_point" {ZoneRadius} {GuardRadius}}` | радиусы охраны (для башен) |
| `{"safety_emitter" {power} {radius}}` | «излучатель безопасности» (успокаивает жителей) |
| `{"m2sensor" {ViewRadius} {Visors {EnemyVisor}}}` | дальность обнаружения врагов |
| `{"FogVisor" {radius}}` | радиус снятия тумана войны |
| `{"EntityClasses" "candest" "tower_guard" ...}` | классы/теги сущности |
| `{"ActionManager" {actions {action {name}}}}` | доступные действия (атаки) |
| `{"m2inventory" {allItems {"Weapon" {weapon_name}}}}` | стартовый инвентарь |
| `{"structure" {place "dummyNN" "object..."}}` | привязка частей 3D-модели к dummy-точкам |

## Важные наблюдения
- **`Upgrades` меняют действия:** улучшение башни делает
  `{add_action "tower_guard_imp_attack"}` + `{remove_action "tower_guard_attack"}`
  — то есть апгрейд = смена атаки на более сильную.
- **`spawner_extender` — точка для «второго стражника»:** список программ
  в `global_spawn_progs` через пробел; добавление второй программы = второй
  спавн (см. [[второй-стражник]]).
- **`{xform scale N}`** — масштаб модели здания.

## Где смотреть примеры
- Башня: `Второй стражник/.../tower_guard/tower_guard.def`.
- Логово: `мини-сборка/.../logovo_dragon/logovo_dragon.def`.
- Кузница: `4 кузница.../mks_smithy/mks_smithy.def`.

## Связанные заметки
- [[set-конфиги]] — базовый синтаксис
- [[система-спавна]] — `spawner_extender` + программы спавна
- [[башни-и-оборона]] · [[логова-монстров]] — где эти `.def` применяются
