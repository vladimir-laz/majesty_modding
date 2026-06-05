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

## Тонкости
- Атрибуты `f_strength` и т.п. — только у героев; HP/защита есть у зданий.
- `guild`/`tower` в `s_type` встречаются только у зданий → можно править по
  подстроке имени, монстров/героев не заденет.
- Защита у `tower_dwarf` = 50 — использовали как образец.

## Связанные заметки
- [[rpg-params-xml]] · [[карта-игровых-файлов]] · [[башни-и-оборона]]
