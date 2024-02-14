#define FIRST_LINE_PIN 2
#define SECOND_LINE_PIN 4
#define COL1_IN_PIN 7
#define COL2_IN_PIN 8

String result = "";

void setup() {
  pinMode(FIRST_LINE_PIN, OUTPUT);
  pinMode(SECOND_LINE_PIN, OUTPUT);
  // pinMode(COL1_IN_PIN, INPUT_PULLUP);
  // pinMode(COL2_IN_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // digitalWrite(FIRST_LINE_PIN, HIGH);
  // result = digitalRead(COL1_IN_PIN);
  // Serial.println(result);
  result = "";
  if (readLine(FIRST_LINE_PIN, COL1_IN_PIN)) {
    result += "1";
  }
  if (readLine(SECOND_LINE_PIN, COL1_IN_PIN)) {
    result += "2";
  }
  if (readLine(FIRST_LINE_PIN, COL2_IN_PIN)) {
    result += "3";
  }
  if (readLine(SECOND_LINE_PIN, COL2_IN_PIN)) {
    result += "4";
  }

  Serial.println(result);
}

bool readLine(int pinLine, int pinInCol) {
  int result = 0;
  digitalWrite(pinLine, HIGH);
  result = digitalRead(pinInCol);
  digitalWrite(pinLine, LOW);

  return result;
}