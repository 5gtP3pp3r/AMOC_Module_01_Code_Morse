#include "Morse.cpp"

void setup() { 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Morse morse;
  String *entree = new String("Hello World 12345");
  // Représentation en morse de la string "Hello World 12345"
  // [. . . .] [.] [. _ . .] [. _ . .] [_ _ _]       [. _ _] [_ _ _] [. _ .] [. _ . .] [_ . .]       [. _ _ _ _] [. . _ _ _] [. . . _ _] [. . . . _] [. . . . .]
  //     h      e      l         l        o     ' '     w       o       r        l        d     ' '       1           2           3           4           5

  morse.convertirStringEnMorse(*entree);
  delete entree;
}
