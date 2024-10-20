#include "Morse.h"

Morse::Morse() {
  ;
}

void Morse::allumerDELInterne(short p_duree) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}
void Morse::eteindreDELInterne(short p_duree) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}

void Morse::executerSelonValeurIndex(String p_valeurIndexTab) {
  for (byte i = 0; i < p_valeurIndexTab.length(); ++i) {
    // caractère court "c".
    if (p_valeurIndexTab[i] == 'c') {
      allumerDELInterne(UNITE);
    }
    // caractère long "l".
    else {
      allumerDELInterne(TROIS_UNITES);      
    }
    // Éteindre unite * 1 entre les parties d'une lettre
    eteindreDELInterne(UNITE);
  }
  // Ajouter éteindre * 2 pour avoir unité * 3 entre les lettres
  eteindreDELInterne(DEUX_UNITES);
}
