#include "Morse.cpp"

void setup() { 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // Je l'admet mon code est simpliste, Ma classe Morse n'est qu'une classe de méthodes. C'est un premier jet qui remplace le premier exercice SOS

  Morse morse;
  String *entree = new String("Hello World 12345");
  // Représentation en morse de la string "Hello World 12345"
  // [. . . .] [.] [. _ . .] [. _ . .] [_ _ _]       [. _ _] [_ _ _] [. _ .] [. _ . .] [_ . .]       [. _ _ _ _] [. . _ _ _] [. . . _ _] [. . . . _] [. . . . .]
  //     h      e      l         l        o     ' '     w       o       r        l        d     ' '       1           2           3           4           5

  morse.convertirStringEnMorse(*entree);
}
