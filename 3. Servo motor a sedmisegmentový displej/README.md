# Servo Motor a Sedmisegmentový Displej

Tato kapitola vás seznámí s ovládáním **servomotoru** a **sedmisegmentového displeje** pomocí Arduino. Naučíte se používat tlačítka k nastavení úhlu servomotoru a zobrazování aktuální hodnoty na displeji.

👉 [Vyzkoušejte simulaci na Wokwi](https://wokwi.com/projects/415066080989515777)

---

## Co je servomotor a sedmisegmentový displej?

**Servomotor** je zařízení, které se používá k přesnému řízení úhlu. Otočí se do určité pozice, která je nastavena na základě hodnoty, kterou mu pošleme.

**Sedmisegmentový displej** je elektronický displej složený z 7 segmentů, které se rozsvěcují nebo zhasínají a tvoří různé číslice a znaky. V našem případě ho používáme k zobrazení hodnoty, kterou nastavíme pro servomotor.

---

## Hardware – Co budete potřebovat?

1. **Arduino deska**
2. **Servomotor**
3. **Sedmisegmentový displej** (4 číslice)
4. **Tlačítka pro ovládání úhlu servomotoru**
5. **Rezistory (220 Ω)** – pro ochranu LED segmentů displeje
6. **Propojovací vodiče a nepájivé pole**

---

## Schéma zapojení

Zapojte komponenty podle tohoto schématu:

| Pin Arduina | Komponenta            | Funkce                |
|-------------|-----------------------|-----------------------|
| 9           | Servomotor            | Ovládání úhlu        |
| 2           | Tlačítko (zvýšení)    | Zvýšení úhlu         |
| 3           | Tlačítko (snížení)    | Snížení úhlu         |
| 4           | Tlačítko (reset)      | Reset na 90°         |
| 5-8         | Sedmisegmentový displej| Zobrazení úhlu       |

> ⚠️ **Důležité**: Mezi piny tlačítek a GND vložte rezistory, pokvaď nemáte bouncing na tlačítku.

---

## Jak program funguje?

### 1. **Ovládání servomotoru**

Servomotor ovládáme pomocí funkce `servo.write(angle)`, kde `angle` je úhel, na který se má servo otočit. Tento úhel můžeme měnit pomocí tlačítek, které umožní zvyšovat nebo snižovat hodnotu.

👉 [Více o servo knihovně](https://www.arduino.cc/reference/en/libraries/servo/)

### 2. **Sedmisegmentový displej**

Sedmisegmentový displej zobrazuje číslice pomocí funkce `sevseg.setNumber()`, která na displeji zobrazí číslici nebo čísla v určeném formátu. Tento displej je ovládán pomocí 7 segmentů, přičemž každý segment může být zapnutý nebo vypnutý.

👉 [Více o SevSeg knihovně](https://github.com/Quindor/SevSeg)

### 3. **Tlačítka**

Tlačítka slouží k ovládání hodnoty úhlu servomotoru. Každé tlačítko má specifickou funkci:
- Tlačítko pro **zvýšení úhlu**.
- Tlačítko pro **snížení úhlu**.
- Tlačítko pro **resetování** úhlu na 90°.

### 4. **Debouncing tlačítek**

Aby nedošlo k vícečetnému zpracování jednoho stisku tlačítka (takzvaný *bouncing*), používáme časovou ochranu s funkce `delay()` a kontrolujeme, kdy bylo tlačítko skutečně stisknuto.

---

## Klíčové koncepty a příkazy

### Ovládání servomotoru
Servomotor se ovládá pomocí knihovny `Servo`. Funkce `servo.write(angle)` určuje, na jaký úhel se servo otočí.
👉 [Více o Servo knihovně](https://www.arduino.cc/reference/en/libraries/servo/)

### Ovládání sedmisegmentového displeje
Displej se ovládá pomocí knihovny `SevSeg` a funkcí jako `setNumber()`, která zobrazí číslici na displeji.
👉 [Více o SevSeg knihovně](https://github.com/Quindor/SevSeg)

### Použití tlačítek
Tlačítka jsou čtena pomocí funkce `digitalRead(pin)`, která vrátí stav tlačítka (HIGH nebo LOW).
👉 [Více o digitalRead](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/)

---

## Úkoly pro vás

1. **Úprava úhlů**: Upravte hodnoty kroků, o které se servo otočí při každém stisku tlačítka.
2. **Přidání tlačítka pro zobrazení jiných informací**: Přidejte tlačítko, které změní zobrazený úhel na jiný formát (např. zobrazení jiných údajů na displeji).
3. **Experimentování s barvami**: Zkuste přidat RGB LED pro zobrazení různých barevných indikátorů podle úhlu servomotoru.

---

## Shrnutí

V této kapitole jste se naučili:
- Ovládat servomotor pomocí tlačítek pro změnu úhlu.
- Používat sedmisegmentový displej k zobrazení aktuální hodnoty úhlu.
- Jak implementovat debouncing tlačítek pro správné ovládání.
  
Díky těmto dovednostem můžete snadno přidat více interaktivity do vašich projektů s Arduinem. 🎉