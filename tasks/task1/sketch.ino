#define LEDPIN 13
#define BUTTON 3

volatile boolean actionState = LOW;

/**
 * Инициализация
 * 
 * Добавляем режим работы для кнопки
 * В качестве методы прерывания исползьуется lightBlinking
 */
void setup() {
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(1, lightBlinking, RISING);
}

/*
* Метод для мигания светодиода
*/
void lightBlinking() {
    
    ledVarChange();
    waitMicros();

}

/*
* Изменяет значение на светодиоде
*/
static void ledVarChange() {
    actionState = !actionState;
    digitalWrite(LEDPIN, actionState);
}

/*
* Метод для избежания дрезбезга контактов
*/
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
