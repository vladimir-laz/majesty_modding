---
tags: [format, xml, localization, loctable]
created: 2026-06-05
updated: 2026-06-05
---
# `M2_mod.loctable.xml` — локализация

## Описание
`localization/M2_mod.loctable.xml` — таблица **строк локализации**
(названия, описания, подсказки, тексты квестов/миссий). Хранится в формате
**Excel 2003 XML (SpreadsheetML)** — то есть это XML-таблица, открывается
Excel'ем. Кодировка UTF-8, кириллица.

## Структура
```xml
<?mso-application progid="Excel.Sheet"?>
<Workbook xmlns="urn:schemas-microsoft-com:office:spreadsheet" ...>
  <Worksheet ss:Name="Knights">
    <Table>
      <Row>
        <Cell><Data ss:Type="String">#HERO_KNIGHT_NAME</Data></Cell>
        <Cell><Data ss:Type="String">Рыцарь</Data></Cell>
      </Row>
      ...
    </Table>
  </Worksheet>
</Workbook>
```
- Один **лист** (`Worksheet`) = группа строк (например `Knights`).
- Каждая **строка** (`Row`): первая ячейка — **ключ** `#KEY`, вторая —
  текст. Бывают доп. колонки под разные языки.

## Ключи (`#KEY`)
На ключи ссылаются `.def`, меню и `shops.set`. Примеры:
- Рыцарь ([[рыцарь]]): `#HERO_KNIGHT_NAME`, `#HERO_KNIGHT_DESC`,
  `#KNIGHT_IMP_ATTACK_NAME`, `#KNIGHT_SWORDMASTER_BUFF_NAME`,
  `#KNIGHT_GOUGE_NAME`, `#STATE_SWORDMASTER_KNIGHT_*`.
- Сборка ([[мини-сборка]]): `#mod_single_01_name`, `#mod_single_01_desc`,
  `#mod_sg01_Quest1_text` (миссии/квесты).

## Роль в моддинге
Любой новый видимый текст (имя героя, описание умения, подсказка) заводят
ключом в loctable и подставляют ключ в данные. Файл достался от
оригинальной игры (автор в свойствах — «Павел Кондрашов», InoCo), моды
дописывают свои листы/строки.

## Связанные заметки
- [[интерфейс-меню-xml]] · [[shops-set]] · [[def-сущности]] — кто ссылается на ключи
- [[процесс-моддинга]]
