#define LED 23

void setup() {
    // esp32:esp32:esp32doit-devkit-v1
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
}

void loop() {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}
