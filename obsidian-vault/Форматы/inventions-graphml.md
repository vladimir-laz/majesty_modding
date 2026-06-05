---
tags: [format, graphml, inventions, research, yed, smithy]
created: 2026-06-05
updated: 2026-06-05
---
# `inventions.graphml` — дерево изобретений

## Описание
`gameData/inventions/inventions.graphml` — **дерево исследований/изобретений**
(оружие, броня, заклинания, улучшения), задаётся в формате **GraphML** из
редактора **yEd** (yFiles). Узлы = изобретения, рёбра = зависимости (что
надо исследовать раньше). Это XML, в отличие от остальных конфигов на `{}`.

## Структура
```xml
<graphml ...>
  <key for="node" id="d0" yfiles.type="nodegraphics"/>
  <key attr.name="description" for="node" id="d1"/>
  <key for="edge" id="d2" yfiles.type="edgegraphics"/>
  ...
  <node id="n0">
    <data key="d0"><y:UMLClassNode>
      <y:NodeLabel ...>Swords_1</y:NodeLabel>   <!-- имя изобретения -->
      <y:UML><y:AttributeLabel>Cost money=250;
Building=smithy;
Time = 15;
Building Level=1;</y:AttributeLabel></y:UML>
    </y:UMLClassNode></data>
  </node>
  <edge source="nX" target="nY">...</edge>      <!-- зависимость -->
</graphml>
```

## Как читать узел
Изобретение = `y:UMLClassNode`:
- `y:NodeLabel` — **имя** (`Swords_1`, `mks_swords_4`).
- `y:AttributeLabel` — параметры в виде строк `ключ=значение;`:
  - `Cost money=N` — цена исследования.
  - `Building=smithy` — в каком здании исследуется.
  - `Time = N` — время исследования.
  - `Building Level=N` — требуемый уровень здания.
- Цвет `y:Fill` группирует ветки визуально.

Рёбра (`<edge>`) задают **порядок**: `Swords_1 → Swords_2 → ... →
Swords_4`.

## Роль в моддинге
Чтобы добавить новый уровень снаряжения, в граф добавляют узел
изобретения (`mks_swords_4`, `mks_bows_4`, `mks_staffs_4`, `mks_plate_4`,
`mks_leather_4`, `mks_cloth_4`) и ребро от предыдущего уровня, а затем
ссылаются на это изобретение из [[shops-set|shops.set]] у соответствующего
оружия/брони. Так устроен [[4-кузница-у-монстров]].

## Связанные заметки
- [[изобретения-кузница]] — игровая механика
- [[shops-set]] — где изобретение привязывается к предмету
- [[4-кузница-у-монстров]]
