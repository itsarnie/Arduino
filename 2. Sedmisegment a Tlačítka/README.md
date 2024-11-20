# Sedmisegmentový displej

Tato kapitola vás naučí, jak ovládat **sedmisegmentový displej** pomocí Arduino desky. Vysvětlíme si princip fungování displeje, jeho zapojení a jak můžete měnit zobrazená čísla i směr počítání pomocí tlačítka.  

👉 [Vyzkoušejte simulaci na Wokwi](https://wokwi.com/projects/415064837782774785)

---

## Co je sedmisegmentový displej?  
Sedmisegmentový displej je zařízení složené ze sedmi LED diod uspořádaných do tvaru číslice "8". Rozsvěcením jednotlivých segmentů (označených jako **a, b, c, d, e, f, g**) lze zobrazit číslice 0–9 nebo jednoduché znaky.  

Každý segment je připojen k samostatnému pinu na Arduino desce. K dispozici jsou dva hlavní typy displejů:
- **Společná katoda**: Katody (záporné póly) všech segmentů jsou spojeny a připojeny k zemi.  
- **Společná anoda**: Anody (kladné póly) všech segmentů jsou spojeny a připojeny k napětí.  

V této kapitole používáme displej se **společnou katodou**.

---

## Hardware – Co budete potřebovat?  
1. **Arduino deska**  
2. **Sedmisegmentový displej**  
3. **Rezistory (220 Ω)** – Pro ochranu LED segmentů před poškozením.  
4. **Tlačítko** – Pro přepínání směru počítání.  
5. Propojovací vodiče a nepájivé pole.  

### Zapojení  
- **Segmenty displeje** (a–g) → Piny Arduino 2 až 8.  
- **Společná katoda** → Pin Arduino 9 (nastaven jako LOW).  
- **Tlačítko** → Pin Arduino 10 (s vestavěným pull-up rezistorem).  

| Arduino Pin | Funkce         |
|-------------|----------------|
| 2–8         | Segmenty a–g   |
| 9           | Společná katoda |
| 10          | Tlačítko       |

---

## Jak program funguje?  

### 1. **Binární vzory pro číslice**  
Každé číslo na displeji je tvořeno kombinací zapnutých a vypnutých segmentů. Tyto vzory ukládáme do pole `digitPatterns[]`.  
Například:  
- **0** = `0b00111111` → Rozsvítí segmenty: a, b, c, d, e, f.  
- **1** = `0b00000110` → Rozsvítí segmenty: b, c.  

### 2. **Funkce pro zobrazení čísla**  
Funkce `displayNumber()` rozsvěcuje segmenty podle zvoleného čísla. Používá pole `digitPatterns[]` pro určení, které segmenty zapnout.  

```cpp
void displayNumber(int num) {
  byte pattern = digitPatterns[num];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(pattern, i));
  }
}
```

### 3. **Debounce tlačítka**  
Tlačítko je vybaveno ochranou proti zákmitům. Zákmit je rychlá změna stavu tlačítka při stisknutí.  
Debounce řešíme sledováním času poslední změny tlačítka a čekáním, dokud není stav stabilní.  

### 4. **Směr počítání**  
Proměnná `countingDown` určuje směr počítání:  
- **true**: Počítání dolů.  
- **false**: Počítání nahoru.  

Každou sekundu (pomocí funkce `millis()`) se hodnota čísla aktualizuje a zobrazí na displeji.

---

## Klíčové koncepty a příkazy  

### Digitální výstupy  
K ovládání segmentů displeje používáme funkci `digitalWrite(pin, value)`.  
👉 [Více o digitalWrite](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)

### Sledování času  
Funkce `millis()` měří dobu od spuštění programu v milisekundách. Využíváme ji k řízení časových intervalů.  
👉 [Více o millis](https://www.arduino.cc/reference/en/language/functions/time/millis/)

### Vstupy  
Pro čtení stavu tlačítka používáme `digitalRead(pin)`.  
👉 [Více o digitalRead](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/)

---

## Úkoly pro vás  
1. **Změna startovní hodnoty**: Nastavte, aby počítání začínalo od čísla 5 místo 9.  
2. **Přidání funkcionality**: Vytvořte druhé tlačítko, které restartuje počítání na nulu.  
3. **Rozšíření vzorů**: Zkuste vytvořit vzory pro písmena, jako například `A`, `b` nebo `C`.  

---

## Shrnutí  
V této kapitole jste se naučili, jak:  
- Připojit a ovládat sedmisegmentový displej.  
- Použít binární vzory k zobrazování čísel.  
- Implementovat debounce pro tlačítko.  
- Řídit směr počítání pomocí jednoduché logiky.  

Díky těmto dovednostem můžete vytvořit vlastní projekty zahrnující displeje a interaktivní ovládání. 🎉