#include "Morse.h"

Morse::Morse() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void Morse::convertirStringEnMorse(const String &p_entree) {
  for (byte i = 0; i < p_entree.length(); ++i) {  
    // Le caractère est une lettre: 
    if (toLowerCase(p_entree[i]) >= 'a' && toLowerCase(p_entree[i]) <= 'z') {
      // valeur du caractère - valeur de 'a' = sa position dans le tableau tabAlphabet. Exemples: 'a'(97) - 'a'(97) = 0, 'a' est bien à l'index 0 et'z'(122) - 'a'(97) = 25.
      byte valeurIndexAlpha = TAB_ALPHABET[toLowerCase(p_entree[i]) - 'a'];
      executerSelonValeurIndex(valeurIndexAlpha);
    }
    // Le caractère est un chiffre:
    else if (p_entree[i] >= '0' && p_entree[i] <= '9') {
      // Valeur du caractère - valeur de '0'= sa position dans le tableau TabNumerique. Exemples: '0' - '0' = 0 et '9' - '0' = 9.
      byte valeurIndexNumerique = TAB_NUMERIQUE[p_entree[i] - '0'];
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
  byte accesseur = p_valeurIndexTab >> POSITION;

  // "valeurBite" est la plage de bites isolé grace à l'opération bite à bite >> accesseur -1.
  // Cette plage de valeurs est donc logiquement 1 de moins que la position de l'accesseur.
  byte valeurBite = p_valeurIndexTab >> accesseur -1;

  for (byte position = accesseur; position > 0; --position) {

    // Isolation du dernier bite de valeurBite grace à un "&" logique avec un masque égale à 0000 0001
    valeurBite = valeurBite & MASQUE_VALEUR;
    
    if (valeurBite == 0) {    
      allumerDELInterne(UNITE);           // caractère court "." -> 0.
    }    
    else {                    
      allumerDELInterne(TROIS_UNITES);    // caractère long "-" -> 1.     
    }   
    eteindreDELInterne(UNITE);            // Éteindre UNITE * 1 entre les parties d'une lettre

    // Réatribution d'une nouvelle valeur à "valeurBite" grace à l'opérateur ">>" 
    // depuis "p_valeurIndexTab" avec la nouvelle valeur de "position".
    // "valeurBite sera remasqué en début de boucle pour isoler le bite suivant."
    valeurBite = p_valeurIndexTab >> accesseur - position;
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
