#include "Morse.h"

Morse::Morse() {
  ;
}

void Morse::convertirStringEnMorse(String &p_entree) {
  for (byte i = 0; i < p_entree.length(); ++i) {  
    // Le caractère est une lettre: 
    if (toLowerCase(p_entree[i]) >= 'a' && toLowerCase(p_entree[i]) <= 'z') {
      // valeur du caractère - valeur de 'a' = sa position dans le tableau tabAlphabet. Exemples: 'a'(97) - 'a'(97) = 0, 'a' est bien à l'index 0 et'z'(122) - 'a'(97) = 25.
      String valeurIndexAlpha = TAB_ALPHABET[toLowerCase(p_entree[i]) - 'a'];
      executerSelonValeurIndex(valeurIndexAlpha);
    }
    // Le caractère est un chiffre:
    else if (p_entree[i] >= '0' && p_entree[i] <= '9') {
      // Valeur du caractère - valeur de '0'= sa position dans le tableau TabNumerique. Exemples: '0' - '0' = 0 et '9' - '0' = 9.
      String valeurIndexNumerique = TAB_NUMERIQUE[p_entree[i] - '0'];
      executerSelonValeurIndex(valeurIndexNumerique);
    } 
    else {    
      // Le caractère est un espace, éteindre unité * 7 entre les mots.  
      eteindreDELInterne(SEPT_UNITES);
    }
  }
  // Montre visuellement la fin de la chaine avec: éteint 1400 ms, allumé 1400 ms et éteint 1400 ms.
  eteindreDELInterne(SEPT_UNITES);
  allumerDELInterne(SEPT_UNITES);
  eteindreDELInterne(SEPT_UNITES);
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

void Morse::allumerDELInterne(short p_duree) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}
void Morse::eteindreDELInterne(short p_duree) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}
