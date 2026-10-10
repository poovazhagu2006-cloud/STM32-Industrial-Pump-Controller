// Industrial Pump Controller - STM32 Nucleo C031C6

const int TANK_LEVEL   = A0;
const int PRESSURE     = A1;
const int PUMP_CURRENT = A2;

const int START_STOP = D2;
const int EMERGENCY  = D3;

const int PUMP_LED   = D4;
const int ALARM_LED  = D5;
const int STATUS_LED = D6;
const int RELAY      = D7;

bool pumpState = false;
bool faultState = false;

void setup() {
  Serial.begin(115200);

  pinMode(START_STOP, INPUT);
  pinMode(EMERGENCY, INPUT);

  pinMode(PUMP_LED, OUTPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);
  pinMode(RELAY, OUTPUT);

  // LEDs are active LOW
  digitalWrite(PUMP_LED, LOW);
  digitalWrite(ALARM_LED, LOW);
  digitalWrite(STATUS_LED, LOW);
  digitalWrite(RELAY, HIGH);

  Serial.println("Industrial Pump Controller Started");
}

void loop() {

  int tankRaw = analogRead(TANK_LEVEL);
  int pressureRaw = analogRead(PRESSURE);
  int currentRaw = analogRead(PUMP_CURRENT);

  bool startCommand = digitalRead(START_STOP);
  bool emergencyStop = digitalRead(EMERGENCY);

  int tankPercent = map(tankRaw, 0, 4095, 0, 100);
  int pressurePercent = map(pressureRaw, 0, 4095, 0, 100);
  int currentPercent = map(currentRaw, 0, 4095, 0, 100);

  // Emergency stop
  if (emergencyStop == HIGH) {
    pumpState = false;
    faultState = true;
  }

  // Over-current protection
  if (currentPercent > 85) {
    pumpState = false;
    faultState = true;
  }

  // Low tank protection
  if (tankPercent < 15) {
    pumpState = false;
    faultState = true;
  }

  // Start pump
  if (startCommand == HIGH && faultState == false) {
    pumpState = true;
  }

  // Stop when tank is full
  if (tankPercent > 90) {
    pumpState = false;
  }

  // Pump ON
  if (pumpState && !faultState) {

    digitalWrite(RELAY, HIGH);

    digitalWrite(PUMP_LED, LOW);
    digitalWrite(STATUS_LED, LOW);
    digitalWrite(ALARM_LED, HIGH);

  } 
  else {

    digitalWrite(RELAY, LOW);

    digitalWrite(PUMP_LED, HIGH);
    digitalWrite(STATUS_LED, HIGH);

    if (faultState) {
      digitalWrite(ALARM_LED, LOW);
    } 
    else {
      digitalWrite(ALARM_LED, HIGH);
    }
  }

  // Serial Monitor
  Serial.print("Tank: ");
  Serial.print(tankPercent);
  Serial.print("% | Pressure: ");
  Serial.print(pressurePercent);
  Serial.print("% | Current: ");
  Serial.print(currentPercent);
  Serial.print("% | Pump: ");
  Serial.print(pumpState ? "ON" : "OFF");
  Serial.print(" | Fault: ");
  Serial.println(faultState ? "YES" : "NO");

  delay(500);
}