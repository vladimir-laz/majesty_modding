---
tags: [format, xml, interface, textures]
created: 2026-06-05
updated: 2026-06-05
---
# `texture_units.xml` — реестр текстур UI

## Описание
`interface/enGUIne/texture_units.xml` — таблица именованных текстур
интерфейса. Связывает **логическое имя** текстуры (на которое ссылаются
кнопки в [[интерфейс-меню-xml|меню]]) с **файлом** `.dds` и смещением
внутри атласа. Кодировка обычно windows-1251.

## Структура
```xml
<Textures ...>
  <Texture>
    <s_name>IMG_perk_fireweapon</s_name>  <!-- имя для ссылок -->
    <s_file>m2_gui</s_file>                <!-- файл-атлас .dds (без расш.) -->
    <i_tuv>460</i_tuv>                     <!-- индекс/смещение в атласе (.tuv) -->
    <s_mirror>MF_NONE</s_mirror>
    <b_stretch>false</b_stretch>
    <b_filtering>false</b_filtering>
  </Texture>
  ...
</Textures>
```

- `s_name` — имя, по которому текстуру зовут (`texture="BUT_hire_Knight"`).
- `s_file` — имя файла-атласа `.dds` (несколько иконок в одном файле).
- `i_tuv` — индекс координат в сопутствующем `.tuv` (UV-разметка атласа).

## Роль в моддинге
Чтобы у новой кнопки была иконка, нужно: (1) объявить `<Texture>` с новым
`s_name`; (2) положить `.dds`-атлас (и при необходимости `.tuv`). Так
сделаны кнопки модов:
- [[элитные-башни]] — `m2_buttons_2.dds`, `texture_units.xml`.
- [[мини-сборка]] — `m2_buttons_logovo.dds` + `m2_buttons_logovo.tuv` для
  иконок логов.
- [[4-кузница-у-монстров]] — `m2_buttons_mks2.dds`.

## Связанные заметки
- [[интерфейс-меню-xml]] — кто ссылается на текстуры
- [[бинарные-ассеты]] — про `.dds`/`.tuv`
