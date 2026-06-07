---
tags: [recipe, how-to, abilities, aoe, buildings, actions]
created: 2026-06-06
updated: 2026-06-06
---
# Рецепт: убрать урон по зданиям у AoE-способности

## Где
`gameData/units/unit_actions.xml` — определения способностей (`<Action>`).
Кого бьёт способность — в блоке `<Target><Group>`:
```xml
<Target>
    <Group>
        <s_type>enemy_unit</s_type>
        <s_type>enemy_building</s_type>   <!-- ЭТО даёт урон по зданиям -->
    </Group>
</Target>
```
Убрать строку `<s_type>enemy_building</s_type>` → способность перестаёт задевать
здания (бьёт только юнитов). Площадь задаётся `<f_aoe_radius>`.

## ⚠️ ГРАБЛЯ: unit_actions.xml — брать ПОЛНЫЙ из `majesty_rpg/`
Как и rpg_params: при оверрайде файл должен быть ПОЛНЫМ. В `resource/` он
**НЕПОЛНЫЙ** (606 действий, нет напр. `basic_magic_not_ranged_attack`) → краш
**`Action "..." not found!`**. Полная версия — **`majesty_rpg/unit_actions.xml`**
(767 действий). Брать ЕЁ как базу, править нужный `<Action>` тег-волком, не задевая
другие. Проверка: баланс тегов `<Action>`/`<Target>` + наличие
`basic_magic_not_ranged_attack`.

## AoE-способности, бьющие по зданиям (нашли)
Базовые атаки `*_basic_attack` бьют здания штатно (так герои сносят логова — НЕ
трогаем). Проблемные ПЛОЩАДНЫЕ (могут случайно крошить здания):
- `hunter_aoe_attack_1` (рейнджер/охотник, AoE 7) — **убрали building**
- `mks_hero_werewolf_whirlwind_attack` (оборотень, вихрь, AoE 7) — **убрали building**
- (волки `summon_wolf_aoe_attack`/`greater_wolf_aoe_attack` — здания НЕ бьют)
- прочие AoE с building: mage_firestorm, blademaster_whirlwind, marksman_sunburst,
  dragon_aoe, и т.д. (не трогали — по запросу только рейнджер+оборотень).

## Связанные заметки
- [[unit-decour-xml]] · [[статы-героев]] · [[карта-игровых-файлов]]
