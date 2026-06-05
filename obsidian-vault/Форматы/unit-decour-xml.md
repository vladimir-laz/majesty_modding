---
tags: [format, xml, stats, weapons, armor, unit-decour]
created: 2026-06-05
updated: 2026-06-05
---
# `unit_decour.xml` — параметры оружия/брони и внешний вид

## Описание
`gameData/units/unit_decour.xml` — **числовые параметры предметов** (урон,
защита, бонусы к характеристикам) и **визуальная экипировка** юнитов. Это
главный файл, где лежат **боевые статы снаряжения** (DPS оружия, защита
брони). XML, кодировка windows-1251 (кириллица в комментариях бьётся — это
нормально). Встречается в [[4-кузница-у-монстров]].

## Что где
Корень `<UnitDecour>`. Основные секции:
- `<WeaponGroup>` → `<Weapon>` — **оружие** и его статы.
- `<Units>` → `<Unit>` → `<Upgrades>` → `<Item>` — **визуальные части
  экипировки** (шлемы, наплечники), привязанные к точкам модели по уровням.

## Блок оружия (`<Weapon>`)
```xml
<Weapon>
  <s_name>hero_archer_bow_02</s_name>      <!-- id предмета -->
  <f_cost>30</f_cost>                       <!-- цена -->
  <f_timeDiff>1</f_timeDiff>                <!-- модиф. скорости атаки -->
  <s_soundtype>arrow_light</s_soundtype>
  <s_missile>human_arrow</s_missile>        <!-- снаряд (для дальнобойных) -->
  <s_fx1>weapon_glow_staff_dp</s_fx1>       <!-- эффект свечения -->
  <s_gui_name>img_sell_und_bow_1</s_gui_name>     <!-- иконка -->
  <s_gui_name_loc>und_bow_1</s_gui_name_loc>      <!-- ключ названия -->
  <Params>
    <f_dps_range>8.1</f_dps_range>          <!-- ← статы предмета -->
  </Params>
</Weapon>
```

## Поля `<Params>` (бонусы предмета)
Все по умолчанию 0 (для `f_frequencyFactor` — 1):
| Поле | Что даёт |
|---|---|
| `f_dps_hth` | урон ближнего боя (melee DPS) |
| `f_dps_range` | урон дальнего боя |
| `f_dps_magic` | магический урон |
| `f_defence_hth` / `f_defence_range` / `f_defence_magic` | защита от соответствующего урона |
| `f_strength` / `f_agility` / `f_intellect` / `f_stamina` | характеристики |
| `f_maxHealth` / `f_maxMana` | макс. здоровье/мана |
| `f_movement` | скорость передвижения |
| `f_frequencyFactor` | частота атак (множитель, база 1) |

Это **бонусы от предмета**, складывающиеся с базой героя (от RPG-класса,
см. [[статы-героев]]).

## Связь с другими файлами
- Предмет, описанный здесь по `s_name`, привязан к герою через
  `m2inventory` в его [[def-сущности|.def]] (`weapon_name`).
- Доступность предмета в кузнице и его уровень — через изобретение в
  [[inventions-graphml]] и запись в [[shops-set]] (`{weapon ...}`/`{armour ...}`).
- Иконка `s_gui_name` — в [[texture-units-xml]]; название `s_gui_name_loc` —
  в [[loctable-xml]].

## Связанные заметки
- [[статы-героев]] — полная карта, где какой стат
- [[изменить-урон-и-броню]] — рецепт правки
- [[изобретения-кузница]] · [[4-кузница-у-монстров]]
