---
tags: [format, xml, rpg, stats, attributes, heroes]
created: 2026-06-05
updated: 2026-06-05
---
# `rpg_params.xml` — базовые характеристики и статы юнитов

## Описание
`gameData/units/rpg_params.xml` (папка **`units`**, мн.ч. — та же, где
[[unit-decour-xml|unit_decour.xml]]) — базовые **характеристики и боевые
статы** ВСЕХ юнитов: героев, горожан, монстров, зданий. Именно здесь
**сила/ловкость/ум/выносливость** героя (0–20). Кодировка windows-1251, есть
схема `rpg_params.xsd` рядом. В базовой игре лежит в `resource.pak`
(в версии Collection155 — распакованно в `resource/gameData/units/`, см.
[[ссылки-и-источники]]).

## Структура
```xml
<RPGParams ...>
  <Heroes>
    <Params>
      <s_type>hero_warrior</s_type>   <!-- id класса -->
      <f_strength>14</f_strength>      <!-- сила -->
      <f_agility>6</f_agility>         <!-- ловкость -->
      <f_intellect>5</f_intellect>     <!-- ум -->
      <f_stamina>15</f_stamina>        <!-- выносливость -->
      <f_maxHealth>12</f_maxHealth>
      <f_maxMana>6</f_maxMana>         <!-- у магов/жрецов -->
      <f_dps_hth>5</f_dps_hth>         <!-- базовый урон ближнего -->
      <f_defence_hth/range/magic>0</...>
      <Distance>...</Distance>         <!-- параметры дистанции боя -->
      <Angle>...</Angle>
      <AIParams><SearchAdventureTask>...</SearchAdventureTask></AIParams>
    </Params>
    ...
  </Heroes>
  <Citizens>...</Citizens>
  <Monsters>...</Monsters>
  <Buildings>...</Buildings>
</RPGParams>
```

## Секции (важно!)
- `<Heroes>` — **классы героев** (31 шт): базовые (`hero_warrior`,
  `hero_cleric`, `hero_hunter`, `hero_rogue`, `hero_mage`, `hero_blademaster`,
  `hero_paladin`, `hero_priest`, `hero_darkpriest`, `hero_marksman`,
  `hero_beastmaster`, `hero_elf`, `hero_dwarf`, `hero_ice_mage`,
  `hero_death_knight`), монстро-герои (`mks_hero_*`), элитные (`hero_high_*`).
- `<Citizens>`, `<Monsters>`, `<Buildings>` — НЕ герои; не трогать, если
  правишь только героев.

## Тонкость значений
Базовые классы пишут целыми (`14`), а `mks_hero_*`/`hero_high_*` — дробными
(`14.0`). При массовой замене regex'ом учитывай **и целые, и дробные**
(`[\d.]+`), иначе обработается лишь часть.

## Что менять
- Характеристики: `f_strength` / `f_agility` / `f_intellect` / `f_stamina`
  (потолок 20).
- HP/мана: `f_maxHealth`, `f_maxMana`. Базовый урон: `f_dps_hth`/`_range`/`_magic`.
- Меняем только ЗНАЧЕНИЯ (структуру не трогаем) → существующая `.xsd` валидна.

## Связанные заметки
- [[максимальные-характеристики-героев]] — рецепт «всем 20»
- [[статы-героев]] · [[unit-decour-xml]] (бонусы от предметов) · [[карта-игровых-файлов]]
