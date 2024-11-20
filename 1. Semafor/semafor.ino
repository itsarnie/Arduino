// Definujeme piny, na které jsou připojené LED diody semaforů
const int redLED1 = 8;  // Červená LED semaforu 1, označuje STOP
const int yellowLED1 = 9;  // Žlutá LED semaforu 1, označuje PŘIPRAVIT SE
const int greenLED1 = 10;  // Zelená LED semaforu 1, označuje JEĎ

const int redLED2 = 11;  // Červená LED semaforu 2
const int yellowLED2 = 12;  // Žlutá LED semaforu 2
const int greenLED2 = 13;  // Zelená LED semaforu 2

const int pedestrianRedLED1 = 4;  // Červená LED semaforu pro chodce 1, označuje STOP
const int pedestrianGreenLED1 = 5;  // Zelená LED semaforu pro chodce 1, označuje VOLNO

const int pedestrianRedLED2 = 6;  // Červená LED semaforu pro chodce 2
const int pedestrianGreenLED2 = 7;  // Zelená LED semaforu pro chodce 2

// Časy, po které budou jednotlivé barvy svítit, jsou udávány v milisekundách
const int redDelay = 5000;  // Červená svítí 5 sekund
const int yellowDelay = 2000;  // Žlutá svítí 2 sekundy
const int greenDelay = 4000;  // Zelená svítí 4 sekundy

void setup() {
  // Nastavujeme všechny piny jako výstupy, aby Arduino mohlo ovládat LED diody
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
  pinMode(pedestrianRedLED1, OUTPUT);
  pinMode(pedestrianGreenLED1, OUTPUT);
  pinMode(pedestrianRedLED2, OUTPUT);
  pinMode(pedestrianGreenLED2, OUTPUT);
}

void loop() {
  // Krok 1: Oba hlavní semafory ukazují červenou, chodci čekají
  digitalWrite(redLED1, HIGH);  // Semafor 1: Červená svítí
  digitalWrite(redLED2, HIGH);  // Semafor 2: Červená svítí
  digitalWrite(yellowLED2, LOW);  // Semafor 2: Žlutá nesvítí
  digitalWrite(pedestrianRedLED1, HIGH);  // Chodci na přechodu 1 mají červenou
  digitalWrite(pedestrianRedLED2, HIGH);  // Chodci na přechodu 2 mají červenou
  digitalWrite(pedestrianGreenLED1, LOW);  // Zelená pro chodce na přechodu 1 je vypnutá
  delay(redDelay);  // Čekáme 5 sekund

  // Krok 2: Semafor 1 se připravuje na zelenou, chodci u přechodu 2 mohou přejít
  digitalWrite(redLED1, HIGH);  // Semafor 1 stále ukazuje červenou
  digitalWrite(yellowLED1, HIGH);  // Semafor 1 ukazuje žlutou
  digitalWrite(greenLED1, LOW);  // Zelená na semaforu 1 je vypnutá
  digitalWrite(pedestrianRedLED2, LOW);  // Chodci na přechodu 2 mají volno
  digitalWrite(pedestrianGreenLED2, HIGH);  // Zelená pro chodce na přechodu 2 svítí
  delay(yellowDelay);  // Čekáme 2 sekundy

  // Krok 3: Semafor 1 ukazuje zelenou, semafor 2 stále červenou
  digitalWrite(redLED1, LOW);  // Semafor 1: Červená je vypnutá
  digitalWrite(yellowLED1, LOW);  // Semafor 1: Žlutá je vypnutá
  digitalWrite(greenLED1, HIGH);  // Semafor 1: Zelená svítí
  delay(greenDelay);  // Čekáme 4 sekundy

  // Krok 4: Semafor 1 přechází zpět na červenou, chodci na přechodu 2 už čekají
  digitalWrite(yellowLED1, HIGH);  // Semafor 1 ukazuje žlutou
  digitalWrite(greenLED1, LOW);  // Zelená na semaforu 1 je vypnutá
  delay(yellowDelay);  // Čekáme 2 sekundy

  // Krok 5: Přepneme semafor 2 na zelenou, chodci u přechodu 1 mají volno
  digitalWrite(redLED2, HIGH);  // Semafor 2 ukazuje červenou
  digitalWrite(yellowLED2, HIGH);  // Semafor 2 ukazuje žlutou
  digitalWrite(greenLED2, LOW);  // Zelená na semaforu 2 je vypnutá
  digitalWrite(pedestrianRedLED1, LOW);  // Chodci na přechodu 1 mají volno
  digitalWrite(pedestrianGreenLED1, HIGH);  // Zelená pro chodce na přechodu 1 svítí
  delay(yellowDelay);  // Čekáme 2 sekundy

  // Krok 6: Semafor 2 ukazuje zelenou, semafor 1 stále červenou
  digitalWrite(redLED2, LOW);  // Červená na semaforu 2 je vypnutá
  digitalWrite(yellowLED2, LOW);  // Žlutá na semaforu 2 je vypnutá
  digitalWrite(greenLED2, HIGH);  // Semafor 2: Zelená svítí
  delay(greenDelay);  // Čekáme 4 sekundy

  // Krok 7: Semafor 2 přechází zpět na červenou
  digitalWrite(yellowLED2, HIGH);  // Semafor 2 ukazuje žlutou
  digitalWrite(greenLED2, LOW);  // Zelená na semaforu 2 je vypnutá
  delay(yellowDelay);  // Čekáme 2 sekundy
}
