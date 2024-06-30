// C++ code
//

// Sensor.
int trig = 5;
int echo = 6;

// Leds.
int LedVerde = 2;
int LedAmarelo = 3;
int LedVermelho = 4;

// Buzina.
int buzina = 9;

long duracao;
int distancia;

void setup() {
  // Sensor.
  pinMode(5, OUTPUT);  // trig.
  pinMode(6, INPUT);   // echo.

  // Leds.
  pinMode(2, OUTPUT);  // Led Verde.
  pinMode(3, OUTPUT);  // Led Amarelo.
  pinMode(4, OUTPUT);  // Led Vermelho

  // Buzina.
  pinMode(9, OUTPUT);  // Buzina.

  // Inicializa com os Leds desligados.
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  // Sem buzina.
  noTone(9);

  // Monitor Serial.
  Serial.begin(9600);
}

void loop() {
  // Sensor(trig).
  digitalWrite(5, LOW);
  delayMicroseconds(2);  // Wait for 2 microseconds.

  digitalWrite(5, HIGH);
  delayMicroseconds(10);  // Wait for 10 microseconds.

  digitalWrite(5, LOW);


  duracao = pulseIn(6, HIGH);
  distancia = duracao * 0.034 / 2;

  // Led Verde.
  if (distancia >= 30 && distancia <= 40) {
    digitalWrite(2, HIGH);
    tone(9, 1500);

  } else {
    noTone(9);
    digitalWrite(2, LOW);  // Led Verde.
    digitalWrite(3, LOW);  // Led Amarelo.
    digitalWrite(4, LOW);  // Vermelho.
  }

  // Led Amarelo.
  if (distancia >= 20 && distancia <= 29) {
    digitalWrite(3, HIGH);
    tone(9, 1100);
  }

  // Led Vermelho.
  if (distancia >= 10 && distancia <= 19) {
    digitalWrite(4, HIGH);
    tone(9, 950);

    while (digitalRead(4) == HIGH) {
      digitalWrite(4, HIGH);
      delay(1000);
      digitalWrite(4, LOW);
      delay(1000);
    }
  }
}