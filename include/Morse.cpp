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
    // caractère court.
    if (p_valeurIndexTab[i] == 'c') {
      allumerDELInterne(UNITE);
    }
    // caractère long.
    else {
      allumerDELInterne(UNITE_X_TROIS);      
    }
    // Éteindre unite * 1 entre les parties d'une lettre
    eteindreDELInterne(UNITE);
  }
  // Ajouter éteindre * 2 pour avoir unité * 3 entre les lettres
  eteindreDELInterne(UNITE_X_DEUX);
}
