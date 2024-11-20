// Nastavení pinů pro segmenty sedmisegmentového displeje
// Každý pin odpovídá segmentu (a, b, c, d, e, f, g)
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};

// Společný pin displeje (katoda)
const int digitPin = 9;

// Pin, ke kterému je připojeno tlačítko
const int buttonPin = 10;

// Binární vzory pro zobrazení číslic od 0 do 9
// Každý bit v čísle určuje, který segment se má rozsvítit
const byte digitPatterns[] = {
  0b00111111, // Číslo 0
  0b00000110, // Číslo 1
  0b01011011, // Číslo 2
  0b01001111, // Číslo 3
  0b01100110, // Číslo 4
  0b01101101, // Číslo 5
  0b01111101, // Číslo 6
  0b00000111, // Číslo 7
  0b01111111, // Číslo 8
  0b01101111  // Číslo 9
};

// Výchozí hodnota počítání
int countValue = 9;

// Příznak určující směr počítání (true = dolů, false = nahoru)
bool countingDown = true;

// Proměnné pro sledování stavu tlačítka
bool lastButtonState = HIGH;    // Poslední známý stav tlačítka
bool currentButtonState = HIGH; // Aktuální stav tlačítka

// Proměnné pro potlačení zákmitů tlačítka
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // Zpoždění pro filtrování zákmitů (50 ms)

// Proměnné pro řízení intervalu počítání
unsigned long lastCountTime = 0;
const unsigned long countDelay = 1000; // Interval 1 sekunda

void setup() {
  // Nastavení všech pinů segmentů jako výstup
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Nastavení společné katody jako výstup a její vypnutí
  pinMode(digitPin, OUTPUT);
  digitalWrite(digitPin, LOW);

  // Nastavení tlačítka jako vstup s vestavěným pull-up rezistorem
  pinMode(buttonPin, INPUT_PULLUP);

  // Inicializace sériového připojení pro ladění
  Serial.begin(9600);
}

void loop() {
  // Zobrazení aktuální číslice na displeji
  displayNumber(countValue);

  // Čtení stavu tlačítka
  int reading = digitalRead(buttonPin);

  // Kontrola, zda se změnil stav tlačítka
  if (reading != lastButtonState) {
    // Uložení času změny
    lastDebounceTime = millis();
  }

  // Potlačení zákmitů tlačítka
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Pokud se stav tlačítka stabilně změnil
    if (reading != currentButtonState) {
      currentButtonState = reading;

      // Pokud bylo tlačítko stisknuto (LOW kvůli pull-up rezistoru)
      if (currentButtonState == LOW) {
        // Změna směru počítání
        countingDown = !countingDown;
        Serial.println(countingDown ? "Počítání dolů" : "Počítání nahoru");
      }
    }
  }

  // Aktualizace posledního známého stavu tlačítka
  lastButtonState = reading;

  // Kontrola, zda uplynul čas pro změnu číslice
  unsigned long currentTime = millis();
  if (currentTime - lastCountTime >= countDelay) {
    // Zvýšení nebo snížení číslice podle směru počítání
    if (countingDown) {
      countValue = (countValue > 0) ? countValue - 1 : 9;
    } else {
      countValue = (countValue < 9) ? countValue + 1 : 0;
    }

    // Uložení času poslední aktualizace
    lastCountTime = currentTime;

    // Výpis hodnoty do sériového monitoru pro ladění
    Serial.println(countValue);
  }
}

// Funkce pro zobrazení čísla na sedmisegmentovém displeji
void displayNumber(int num) {
  // Získání binárního vzoru pro dané číslo
  byte pattern = digitPatterns[num];

  // Rozsvícení odpovídajících segmentů
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(pattern, i));
  }
}
