//Пин, к которому подключен пьезодинамик.
int piezoPin = 3;
 
void setup() {
 
}

void loop() {
 
  /*Функция принимает три аргумента
    1) Номер пина
    2) Частоту в герцах, определяющую высоту звука
    3) Длительность в миллисекундах. 
  */
//   tone(piezoPin, 1000, 500); // Звук прекратится через 500 мс, о программа останавливаться не будет!

  /* Вариант без установленной длительности   */
  tone(piezoPin, 2000); // Запустили звучание
  delay(500);
  noTone(piezoPin); // Остановили звучание


}