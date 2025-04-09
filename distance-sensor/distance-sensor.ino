// esp32:esp32:esp32doit-devkit-v1

const int echoPin = 19;
const int trigPin = 18;
const int maxDist = 300;

unsigned long tim, tim2, totalTime, maxTime = (maxDist*1000000*2)/34300;

long ping() {
    // Start sending ultra-sonic waves
    digitalWrite(trigPin, HIGH);
    tim = micros();
    while((micros()-tim) < 10);
    digitalWrite(trigPin, LOW);

    while(!digitalRead(echoPin));
    tim = micros();
    do { tim2 = micros(); }
    while(digitalRead(echoPin) && tim2-tim <= maxTime);
    totalTime = tim2 - tim;
    if(totalTime <= maxTime){
        long dist = 34300 * totalTime / 2000000;
        return dist;
    }
    else {
        return 0;
    }

    
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    delay(10); // this speeds up the simulation
    Serial.println(ping());
    
}
