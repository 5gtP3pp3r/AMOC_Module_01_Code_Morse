#include "Morse.cpp"

void setup() { 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  Morse morse;
  String entree = "Hello World 12345";
// Représentation en morse de la string "Hello World 12345"
// [. . . .] [.] [. _ . .] [. _ . .] [_ _ _]       [. _ _] [_ _ _] [. _ .] [. _ . .] [_ . .]       [. _ _ _ _] [. . _ _ _] [. . . _ _] [. . . . _] [. . . . .]
//     h      e      l         l        o     ' '     w       o       r        l        d     ' '       1           2           3           4           5

  for (byte i = 0; i < entree.length(); ++i) {  
    // Le caractère est une lettre: 
    if (toLowerCase(entree[i]) >= 'a' && toLowerCase(entree[i]) <= 'z') {
      // valeur du caractère - valeur de 'a' = sa position dans le tableau tabAlphabet. Exemples: 'a'(97) - 'a'(97) = 0, 'a' est bien à l'index 0 et'z'(122) - 'a'(97) = 25.
      String valeurIndexAlpha = morse.TAB_ALPHABET[toLowerCase(entree[i]) - 'a'];
      morse.executerSelonValeurIndex(valeurIndexAlpha);
    }
    // Le caractère est un chiffre:
    else if (entree[i] >= '0' && entree[i] <= '9') {
      // Valeur du caractère - valeur de '0'= sa position dans le tableau TabNumerique. Exemples: '0' - '0' = 0 et '9' - '0' = 9.
      String valeurIndexNumerique = morse.TAB_NUMERIQUE[entree[i] - '0'];
      morse.executerSelonValeurIndex(valeurIndexNumerique);
    } 
    else {    
      // Le caractère est un espace, éteindre unité * 7 entre les mots.  
      morse.eteindreDELInterne(morse.UNITE_X_SEPT);
    }
  }
  // Montre visuellement la fin de la chaine avec: éteint 1400 ms, allumé 1400 ms et éteint 1400 ms.
  morse.eteindreDELInterne(morse.UNITE_X_SEPT);
  morse.allumerDELInterne(morse.UNITE_X_SEPT);
  morse.eteindreDELInterne(morse.UNITE_X_SEPT);
}
