#define LEDPIN 13

volatile boolean actionState = LOW;

void setup() {
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
    pinMode(3, INPUT_PULLUP);
    attachInterrupt(1, lightBlinking, RISING);
}

void lightBlinking() {
    
    ledVarChange();
    waitMicros();

}

static void ledVarChange() {
    actionState = !actionState;
    digitalWrite(LEDPIN, actionState);
}

void waitMicros() {
    for (int i = 0; i < 200; i++) {
        
        unsigned int microsTimerBuffer = micros();
        
        Serial.println(i);

        boolean exitState = true;
        while (exitState) {
            if (micros() - microsTimerBuffer > 50000) {
                exitState = false;
            }
        }
    }
}
 
void loop() {}
