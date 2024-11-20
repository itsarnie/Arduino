#include <Servo.h>      // Knihovna pro ovládání servomotoru
#include <SevSeg.h>      // Knihovna pro ovládání sedmisegmentového displeje

Servo servo;                  // Vytvoření objektu pro servomotor
SevSeg sevseg;                 // Vytvoření objektu pro sedmisegmentový displej

// Nastavení proměnných pro ovládání servomotoru a tlačítek
int servoPin = 9;              // Pin pro připojení servomotoru
int maxAngle = 180;            // Maximální úhel, do kterého může servo otočit
int minAngle = 0;              // Minimální úhel, do kterého může servo otočit
int step = 5;                  // Krok, o který se servo otočí při každém stisknutí tlačítka
int angle = 90;                // Počáteční úhel servomotoru (nastaveno na 90 stupňů)

// Nastavení pinů pro tlačítka
int buttonUpPin = 2;           // Pin pro tlačítko pro zvyšování úhlu
int buttonDownPin = 3;         // Pin pro tlačítko pro snižování úhlu
int buttonResetPin = 4;        // Pin pro tlačítko pro reset na úhel 90°

void setup() {
  servo.attach(servoPin);  // Připojení servomotoru na pin definovaný v servoPin
  
  // Nastavení pinů tlačítek jako vstupy s interními pull-up rezistory
  pinMode(buttonUpPin, INPUT_PULLUP);   // Tlačítko pro zvyšování úhlu
  pinMode(buttonDownPin, INPUT_PULLUP); // Tlačítko pro snižování úhlu
  pinMode(buttonResetPin, INPUT_PULLUP);// Tlačítko pro reset na 90°

  // Konfigurace sedmisegmentového displeje
  byte numDigits = 4;                           // Počet číslic na displeji
  byte digitPins[] = {5, 6, 7, 8};              // Piny pro připojení číslic na displeji
  byte segmentPins[] = {10, 11, 12, 13, A0, A1, A2}; // Piny pro připojení segmentů displeje

  // Inicializace sedmisegmentového displeje
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);                    // Nastavení jasu displeje na 90%

  // Nastavení počátečního úhlu servomotoru a zobrazení úhlu na displeji
  servo.write(angle);                          // Nastavení serva na počáteční úhel 90°
  sevseg.setNumber(angle, 0);                  // Zobrazení počátečního úhlu na displeji
}

void loop() {
  // Kontrola, zda bylo stisknuto tlačítko pro zvýšení úhlu
  if (digitalRead(buttonUpPin) == LOW) {
    angle = min(angle + step, maxAngle);      // Zvýšení úhlu o 5°, ale ne přesahující maximální úhel
    servo.write(angle);                       // Otočení serva na nový úhel
    sevseg.setNumber(angle, 0);                // Aktualizace displeje pro zobrazení nového úhlu
    delay(200);                               // Krátká pauza, aby se stisknutí tlačítka nezpracovalo vícekrát
  }

  // Kontrola, zda bylo stisknuto tlačítko pro snížení úhlu
  if (digitalRead(buttonDownPin) == LOW) {
    angle = max(angle - step, minAngle);      // Snížení úhlu o 5°, ale ne pod minimální úhel
    servo.write(angle);                       // Otočení serva na nový úhel
    sevseg.setNumber(angle, 0);                // Aktualizace displeje pro zobrazení nového úhlu
    delay(200);                               // Krátká pauza, aby se stisknutí tlačítka nezpracovalo vícekrát
  }

  // Kontrola, zda bylo stisknuto tlačítko pro reset na úhel 90°
  if (digitalRead(buttonResetPin) == LOW) {
    angle = 90;                               // Nastavení úhlu na 90°
    servo.write(angle);                       // Otočení serva na 90°
    sevseg.setNumber(angle, 0);                // Aktualizace displeje pro zobrazení úhlu 90°
    delay(200);                               // Krátká pauza, aby se stisknutí tlačítka nezpracovalo vícekrát
  }

  sevseg.refreshDisplay();                     // Aktualizace displeje (pokud došlo k nějaké změně)
}
