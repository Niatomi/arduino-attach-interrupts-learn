#include <Keypad.h>

#define ZOOMER 10

// Иницаиализация переменных и библиотеки для работы с клавиатурой
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
{'1','4','7','d'}, 
{'2','5','8','0'},
{'3','6','9','#'},
{'A','B','C','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; 
byte colPins[COLS] = {9, 8, 7, 6}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  pinMode(ZOOMER, OUTPUT);
  digitalWrite(ZOOMER, 0);

}

/*
* После нажатия разных клавиш начинает 
* работать пьезодинамик, частота которого зависит от
* положения ключа в матрице hexaKeys
* @param customKey нажатая клавиша
*/
void loop(){
    char customKey = customKeypad.getKey();
    
    if (customKey){ 
      for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
          if (hexaKeys[x][y] == customKey) 
            tone(ZOOMER, 440 + x*100 + y*50, 200);
        }
      }
    }

}