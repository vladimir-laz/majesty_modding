---
tags: [format, constants, gameplay, balance, con]
created: 2026-06-05
updated: 2026-06-05
---
# `m2GameConst.con` — глобальные игровые константы

## Описание
`interface/cs/m2GameConst.con` — файл **глобальных игровых констант** (баланс,
экономика, ИИ, рандомизатор). Формат — `имя  значение  ; комментарий`
(не `{}`!). Кодировка windows-1251. Один из самых полезных файлов для баланса:
многое, что «зашито», на деле здесь. Маленький (~126 строк).

## Ключевые константы
| Константа | База | Что |
|---|---|---|
| **`m2LevelUpSpeed`** | 6 | **скорость набора опыта героями** (больше = быстрее лвлап). [[опыт-героев]] |
| `m2LongDay` | 45 | длительность игрового дня (сек) |
| `m2Repair_Speed` / `m2MagicRepair_Speed` | 45 / 15 | скорость ремонта/постройки стен (в сборках ×2 → 90/30) |
| `m2BuildingCostChangeCoefficient` | 2.0 | множитель роста цены зданий |
| `m2UpgradeCostCoefficient_1/2` | 1 / 0.2 | формула цены улучшения зданий |
| `m2ResurrectCostCoefficient_1/2` | 1 / 0.5 | формула цены воскрешения героя |
| `m2LordCostCoefficient_1/2` | 1 / 0.5 | формула цены найма лорда |
| `m2HealEntity_PercentHealth` | 90 | при каком % HP лечить в здании |
| `m2UndergoTreatmentTask_PercentHealth` | 1 | порог ухода героя на лечение |
| `m2TargetManager_maxHeroLevel` | 20 | макс. уровень героя для ИИ-таргетинга |
| `m2DefaultUpgradedUnitTreasures` | 600 | золото у прокачанного юнита |
| `m2Building_CanBeAttacked` | 12.0 | % HP, ниже которого здание можно атаковать |
| `m2ProtectFlag_GuardRadius` | 18 | радиус флага «защита» |
| `m2FearFlag_EmissionPower` / `_EmissionRadius` | 0.1 / 20 | **сила и радиус флага страха** (отпугивает героев). У героев per-flag коэффициента страха НЕТ — сила только тут. В сборках ×20 = 2.0 / радиус 30 |
| `m2FearFlag_ActivePeriod` / `m2ProtectFlag_*` | 10 / … | время жизни флагов, радиус флага защиты |

## Рандомизатор логов/сундуков (флаг `randomizable`)
Параметры той самой рандомизации позиций (см. [[ссылки-и-источники]]):
`m2RandomizerNearRadius 30` / `m2RandomizerFarRadius 60`,
`m2SuperRandomizerMinValue/MaxValue 0/5`, `m2SuperRandomizer*Radius`,
`m2ZonesRandomizer*Radius`. Золото случайного сундука: `m2ChestRandomGold 200`
+ вероятности лута `m2RandomChest*Possibility`.

## ⚠️ Это исправляет прежний вывод
Ранее считалось, что скорость опыта «зашита в движок» — **неверно**: она в
`m2LevelUpSpeed`. (Скорость **строительства** зданий тут тоже не нашлась —
вероятно, действительно движок.)

## Связанные заметки
- [[опыт-героев]] · [[карта-игровых-файлов]] · [[ссылки-и-источники]]
