---
tags: [format, perks, buffs, states, regen, xml]
created: 2026-06-06
updated: 2026-06-06
---
# `perks.xml` — перки, баффы и состояния (states)

## Описание
`gameData/units/perks.xml` — определения **перков/состояний** (buff/debuff):
реген, яд, оглушение, иммунитеты, бонусы к защите/атаке. На них ссылаются
заклинания ([[spells-xml]]), эликсиры/артефакты (`unit_elixirs.xml`,
`unit_artefacts.xml`), действия и врождённые пассивы юнитов.

## Структура перка
```xml
<Perk>
    <s_name>имя_перка</s_name>          <!-- по нему ссылаются -->
    <f_liveTime>135</f_liveTime>        <!-- сек; ОТСУТСТВУЕТ = ПЕРМАНЕНТНЫЙ -->
    <f_period>2</f_period>              <!-- период тика (сек) для периодических -->
    <Blocks>
        <s_type>HealthChange</s_type>  <!-- тип эффекта -->
        <f_value>10</f_value>          <!-- +лечит / -урон за тик -->
    </Blocks>
    <Blocks>
        <s_type>FX</s_type>            <!-- визуал -->
        <s_headFX>...</s_headFX>
    </Blocks>
</Perk>
```
Типы блоков (`s_type`): `HealthChange` (реген/урон во времени), `MagicResistance`,
`MissileSkill`, `Imunity2Specials/Knockback/Perks` (иммунитеты), `MagicResistance` и т.д.

## Реген: готовые перманентные перки (без f_liveTime)
| Перк | Реген | Заметка |
|---|---|---|
| `artefact_of_regeneration` | +2 HP/сек (`f_period 1`) | **«амулет регенерации»** — умеренный |
| `perk_regeneration` / `ogre_regeneration` | +2 / 2 сек | мягкий |
| `state_werewolf_regeneration` | +350 / 2 сек | боссовский, СЛИШКОМ сильный |

## Как навесить перк на юнита ПЕРМАНЕНТНО
В **дефе** юнита (инлайн из `extenders/default_perks.inc`):
```
{"RPGModule"
    {perks
        {perkinstance "artefact_of_regeneration"}
    }
}
```
У героев/боссов так заданы врождённые пассивы (`perk_boss`,
`state_ratman_protection`). Применили крестьянам ([[крестьяне]]).

## Связанные заметки
- [[крестьяне]] · [[def-сущности]] · [[rpg-params-xml]] · [[карта-игровых-файлов]]
