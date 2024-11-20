# Semafor  

Tato kapitola vás provede vytvořením funkčního **semaforu** pomocí Arduino desky. Naučíte se ovládat více LED diod, používat časové zpoždění pro simulaci provozu a seznámíte se se základními funkcemi pro digitální výstupy.  

👉 [Vyzkoušejte simulaci na Wokwi](https://wokwi.com/projects/#####) *(odkaz nahraďte skutečnou simulací, pokud máte projekt na Wokwi)*  

---

## Co je semafor?  
Semafor je zařízení, které řídí dopravu pomocí světelných signálů. Obvykle má:  
- **Tři barvy pro vozidla**: červená, žlutá a zelená.  
- **Dvě barvy pro chodce**: červená a zelená.  

V této kapitole si vytvoříte obousměrný semafor s přechodem pro chodce. Oba směry budou řízeny nezávisle.  

---

## Hardware – Co budete potřebovat?  
1. **Arduino deska**  
2. **LED diody**:  
   - 2× červená, 2× žlutá, 2× zelená pro vozidla.  
   - 2× červená, 2× zelená pro chodce.  
3. **Rezistory (220 Ω)** – Pro ochranu LED diod.  
4. Propojovací vodiče a nepájivé pole.

---

## Schéma zapojení

Zapojte komponenty podle níže uvedeného schématu:

| Pin Arduina | Barva LED | Funkce                  |
|-------------|-----------|-------------------------|
| 8           | Červená   | Semafor 1 (STOP)       |
| 9           | Žlutá     | Semafor 1 (PŘIPRAVIT)  |
| 10          | Zelená    | Semafor 1 (JEĎ)        |
| 11          | Červená   | Semafor 2 (STOP)       |
| 12          | Žlutá     | Semafor 2 (PŘIPRAVIT)  |
| 13          | Zelená    | Semafor 2 (JEĎ)        |
| 4           | Červená   | Chodci 1 (STOP)        |
| 5           | Zelená    | Chodci 1 (VOLNO)       |
| 6           | Červená   | Chodci 2 (STOP)        |
| 7           | Zelená    | Chodci 2 (VOLNO)       |

> ⚠️ **Důležité:** Mezi každou LED diodu a zem (GND) vložte rezistor, aby nedošlo k jejímu poškození.  

---

## Jak program funguje?  

### 1. **Digitální výstupy pro LED**  
LED diody jsou ovládány pomocí funkce `digitalWrite(pin, value)`.  
- **HIGH** – LED se rozsvítí.  
- **LOW** – LED zhasne.  

👉 [Více o digitalWrite](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)

### 2. **Časové zpoždění**  
Pro simulaci reálného provozu semaforu používáme funkci `delay(ms)`, která pozastaví běh programu na daný počet milisekund.  
👉 [Více o delay](https://www.arduino.cc/reference/en/language/functions/time/delay/)

Každý stav (červená, žlutá, zelená) má svůj časový interval:  
- **Červená**: 5 sekund (5000 ms).  
- **Žlutá**: 2 sekundy (2000 ms).  
- **Zelená**: 4 sekundy (4000 ms).  

### 3. **Řízení semaforu**  
Kód postupně:  
1. Zapne červenou pro jeden směr a zelenou pro druhý směr.  
2. Přepne na žlutou, aby upozornil na změnu.  
3. Zapne zelenou a opačně pro chodce.  

Tento proces se opakuje ve smyčce `loop()`.

---

## Klíčové koncepty a příkazy  

### Nastavení pinů  
Piny jsou v `setup()` nastaveny jako výstupy pomocí funkce `pinMode(pin, mode)`.  
👉 [Více o pinMode](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/)

### Digitální výstupy  
Funkce `digitalWrite(pin, value)` ovládá stav LED diod.  
👉 [Více o digitalWrite](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)

### Řízení času  
Funkce `delay(ms)` pozastaví běh programu na zadaný počet milisekund.  
👉 [Více o delay](https://www.arduino.cc/reference/en/language/functions/time/delay/)

---

## Úkoly pro vás  
1. **Změna časů**: Upravte časové intervaly tak, aby červená trvala 3 sekundy a zelená 6 sekund.  
2. **Přidání funkce**: Přidejte tlačítko, které zastaví oba směry a rozsvítí zelenou pro chodce.  
3. **Experiment s barvami**: Použijte LED diody jiných barev nebo kombinaci RGB LED.  

---

## Shrnutí  
V této kapitole jste se naučili:  
- Ovládat více LED diod pomocí digitálních výstupů.  
- Použít časová zpoždění k simulaci reálných světelných cyklů.  
- Implementovat základní logiku řízení semaforu.  

Díky těmto základům můžete rozšířit svůj projekt o další prvky, jako jsou tlačítka, senzory nebo LCD displej. 🎉