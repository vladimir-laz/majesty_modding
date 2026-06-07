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

## ⚠️ unit_actions.xml — ПОЛНЫЙ файл
Как и rpg_params: класть ПОЛНУЮ версию (из `resource/` — там все mks_/boss_/
expansion способности). Править нужный `<Action>` брейс/тег-волком, не задевая
другие. Проверка: баланс тегов `<Action>`/`<Target>`.

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
