#include "Morse.h"

Morse::Morse() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void Morse::convertirStringEnMorse(const String &p_entree) {
  for (byte caractere = 0; caractere < p_entree.length(); ++caractere) {  
    // Le caractère est une lettre: 
    if (toLowerCase(p_entree[caractere]) >= 'a' && toLowerCase(p_entree[caractere]) <= 'z') {
      // valeur du caractère - valeur de 'a' = sa position dans le tableau tabAlphabet. Exemples: 'a'(97) - 'a'(97) = 0, 'a' est bien à l'index 0 et'z'(122) - 'a'(97) = 25.
      byte valeurIndexAlpha = TAB_ALPHABET[toLowerCase(p_entree[caractere]) - 'a'];
      executerSelonValeurIndex(valeurIndexAlpha);
    }
    // Le caractère est un chiffre:
    else if (p_entree[caractere] >= '0' && p_entree[caractere] <= '9') {
      // Valeur du caractère - valeur de '0'= sa position dans le tableau TabNumerique. Exemples: '0' - '0' = 0 et '9' - '0' = 9.
      byte valeurIndexNumerique = TAB_NUMERIQUE[p_entree[caractere] - '0'];
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

void Morse::executerSelonValeurIndex(byte p_valeurIndexTab) const {
  // "accesseur" est la valeur de 3 bites au début du byte, elle me donne donc le nombre d'itération
  // à faire dans la plage "valeur" du byte pour "accéder" aux valeurs 0 ou 1 à afficher. L'accesseur
  // est isolé grace à l'opérateur ">>" qui éliminera les 5 premiers bite de "p_valeurIndexTab".
  // Exemple avec la lettre "a" 0b[010]00001
  byte accesseur = p_valeurIndexTab >> POSITION;
                                                                                                        
  for (byte position = accesseur -1; position >= 0; --position) {     
    // "valeurBites" est une plage de bites isolé grace à l'opération bite à bite >> "position".
    // Cette plage contiendra la valeur du bite à isoler qui sera masqué plus tard.                       // Exemples des opérations dans  
    // Au départ, position est donc logiquement 1 de moins que l'accesseur. Position                      // la boucle avec la lettre "a" 0b01000001
    // sera décrémenté à chaque tour pour isoler le prochain bite vers la droite.                         // accesseur = 0b01000001 >> 5 = 0b/00000/[010] donc 2 tours
    byte valeurBites = p_valeurIndexTab >> position;                                                      // Tour 1: valeurBites = 0b01000001 >> (00000010 (2) - 1) = 0b/0/010000[0]
    // Isolation du dernier bite de valeurBite grace à un "&" logique avec un masque égale à 0000 0001    // bite = 0b0010000[0] & 0b0000000[1] = 0b0000000[0] donc 0
    byte bite = valeurBites & MASQUE_VALEUR;                                                              // Est appelé: allumerDELInterne(UNITE);                                                                                                          
                                                                                                          // Tour 2: valeurBites = 0b01000001 >> (00000010 (2) - (2)) = 0b0100000[1]
    if (bite == 0) {                                                                                      // bite = 0b0001000[1] & 0b0000000[1] = 0b0000000[1] donc 1
      allumerDELInterne(UNITE);           // caractère court "." -> 0.                                    // Est appelé: allumerDELInterne(TROIS_UNITES);
    }                                                                                                     // Résultat "a" ". -" = "0 1" :)
    else {                    
      allumerDELInterne(TROIS_UNITES);    // caractère long "-" -> 1.     
    }   
    eteindreDELInterne(UNITE);            // Éteindre UNITE * 1 entre les parties d'une lettre
  }  
  eteindreDELInterne(DEUX_UNITES);        // Ajouter UNITE * 2 pour avoir UNITE * 3 entre les lettres
}

void Morse::allumerDELInterne(short p_duree) const {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}
void Morse::eteindreDELInterne(short p_duree) const {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}
