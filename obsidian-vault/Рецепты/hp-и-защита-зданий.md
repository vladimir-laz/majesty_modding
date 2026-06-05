---
tags: [recipe, how-to, buildings, health, defence, rpg]
created: 2026-06-05
updated: 2026-06-05
---
# Рецепт: HP и защита зданий (гильдии, башни)

## Где
HP и защита зданий — в [[rpg-params-xml|rpg_params.xml]], секция `<Buildings>`,
по `s_type`:
```
<s_type>guild_warrior</s_type>
<f_maxHealth>800</f_maxHealth>
<f_defence_hth>50</f_defence_hth>      ; есть не у всех (у tower_dwarf есть, у tower_guard нет)
<f_defence_range>50</f_defence_range>
<f_defence_magic>50</f_defence_magic>
```
⚠️ `rpg_params.xml` должен быть ПОЛНЫМ (см. грабли в [[rpg-params-xml]]) —
брать полный из `majesty_rpg`, а не базовую копию.

## Что делали в сборках
- **HP гильдий ×2** (все `s_type` с `guild`): напр. guild_warrior 800→1600.
- **HP башен ×3** (все с `tower`): tower_guard 800→2400, tower_dwarf 1000→3000.
- **Добавлена защита** `f_defence_hth/range/magic = 50` гильдиям, у которых её
  не было (вставка после `<f_maxHealth>`). У кого была — не трогали.

## ⚠️ Прибавка HP за АПГРЕЙД — отдельно, в `.def` здания!
`rpg_params.f_maxHealth` = только **базовое** HP (уровень 1). При апгрейде
здания (`Max upgrade` в [[shops-set]]) HP **добавляется** из блока `{"Upgrades"}`
внутри **`.def`** здания (инлайнится из `extenders/upgrades.inc`):
```
{"Health" {value_new {rpg_building}}}        ; база -> из rpg_params
{"Upgrades" {available
    {{health 500} {building_value 0.35} {cost "money" 200}}   ; +500 HP за 1-й апгрейд
    {{health 500} ... }                                       ; +500 HP за 2-й апгрейд
}}
```
Итоговое HP макс. уровня = `f_maxHealth + sum(health прибавок)`. Если поднять
только rpg_params, **апгрейженное здание почти не станет крепче** — надо
домножить и `{health N}`.
- Игра грузит **расплющенный `.def`** (includes уже вшиты, видны метки
  `;#line ... BEGIN/END`) → править/оверрайдить нужно сам `.def` в
  `resource.mod/entity/buildings/<ent>/<ent>.def`, НЕ `.inc` (их движок не читает).
- Множить `{health N}` ТЕМ ЖЕ множителем, что и базу (гильдии ×2, башни ×3) —
  тогда здание усилено одинаково на всех уровнях. Брейс-волком вырезать блок
  `{"Upgrades"}` и `re.sub(r'\{health (\d+)\}', ...)` только внутри него.
- Не у всех зданий есть прибавки: часть `guild_*` имеют пустой `Upgrades`,
  `_pp2`-варианты/`guild_death_knight`/`guild_ice_magea` — без блока вовсе.
  В сборках обновлено 12 зданий с реальными `{health N}` (guild_warrior/cleric/
  dwarf/elf/hunter/mage/rogue/fire_mage/goblin_*, tower_guard, unique_tower_guard).

## Тонкости
- Атрибуты `f_strength` и т.п. — только у героев; HP/защита есть у зданий.
- `guild`/`tower` в `s_type` встречаются только у зданий → можно править по
  подстроке имени, монстров/героев не заденет.
- Защита у `tower_dwarf` = 50 — использовали как образец.

## Связанные заметки
- [[rpg-params-xml]] · [[карта-игровых-файлов]] · [[башни-и-оборона]]
