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

## ⚠️ ГРАБЛИ: дробные HP (`2000.0`) — regex `\d+` их пропускает!
Часть зданий хранит HP как **дробь**: `<f_maxHealth>2000.0</f_maxHealth>`.
Монстрские гильдии (`guild_werewolf`, `guild_minotaur`, `guild_ratman_paladin`,
ВСЕ `mks_guild_*`) и `unique_tower_goblin` — именно такие. Если множить regex'ом
`<f_maxHealth>(\d+)</f_maxHealth>` — они **молча не изменятся** (видно как «у
гильдии оборотней HP не повышен»). Использовать `([\d.]+)` и сохранять формат
(дробь→дробь). Идемпотентно безопаснее **пересчитывать от базы** (`build = base*f`),
а не множить текущее значение. В сборках доведено: 10 монстрских/дробных гильдий
×2 (+защита 50, где не было) и `unique_tower_goblin` ×3.

## Тонкости
- Атрибуты `f_strength` и т.п. — только у героев; HP/защита есть у зданий.
- `guild`/`tower` в `s_type` встречаются только у зданий → можно править по
  подстроке имени, монстров/героев не заденет.
- Защита у `tower_dwarf` = 50 — использовали как образец.

## Связанные заметки
- [[rpg-params-xml]] · [[карта-игровых-файлов]] · [[башни-и-оборона]]
