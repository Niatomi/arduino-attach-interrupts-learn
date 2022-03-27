# Прерывания

## Запуск скетчей

Перед запуском определённого файла следует указать нужную папку в файле `.vscode\arduino.json` в параметре `sketch`.
Пример `.vscode\arduino.json` для запуска третьего задания:

```json
{
  "sketch": "tasks\\task3\\sketch.ino",
  "output": "build",
  "board": "arduino:avr:uno",
  "port": "COM3",
  "programmer": "arduino:avrispmkii"
}
```

<hr>

## Задачи

1. Реализовать прерывание по кнопке

2. Реализовать прерывание по таймеру

3. Разработать программу вывода на экран нажатой кнопки с
   подтверждением нажатя с помощью звукового сигнала 1. Необходимо собрать последнюю схему подключения клавиатуры
   ![schema](/schema.png) 2. Подключить к контроллеру пьезоизлучатель и дисплей
