#include <avr/io.h>
#include <avr/interrupt.h>

#define LEDPIN 13

void setup() {
    pinMode(LEDPIN, OUTPUT);
    cli(); 
    
    TCCR1A = 0; 
    TCCR1B = 0;

    OCR1A = 15624;

    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);

    TIMSK1 |= (1 << OCIE1A);

    sei();
}

void loop() {}

ISR(TIMER1_OVF_vect) {
    digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}