#include "Morse.h"

Morse::Morse() {
  ;
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
  // "accesseur" est la valeur au début du byte, elle me donne donc le nombre d'itération à
  // faire dans la partie valeur du byte pour "accéder" aux valeurs 0 ou 1 à afficher.
  // L'accesseur est isolé grace à l'opérateur ">>" qui éliminera les 5 premiers bite de "p_valeurIndexTab".
  byte accesseur = p_valeurIndexTab >> POSITION;

  // "positionValeur" est un chiffre qui me donnera access au début des bites de la section  
  // "valeur" de "p_valeurIndexTab". Il sera décrémenter pour lire les bites de gauche à droite 
  // dans la section "valeur". Il est donc logiquement 1 de moins que la position de l'accesseur.
  byte positionValeur = accesseur -1 ;

  // "valeurBite" est donc le bite isolé à la position présenté par "positionValeur".
  byte valeurBite = p_valeurIndexTab >> positionValeur;

  for (byte i = 0; i < accesseur; ++i) {

    // Isolation du dernier bite de valeurBite grace à un "&" logique avec un masque égale à 0000 0001
    valeurBite = valeurBite & MASQUE_VALEUR;
    // caractère court "." -> 0.
    if (valeurBite == 0) {
      allumerDELInterne(UNITE);
    }
    // caractère long "-" -> 1.
    else {
      allumerDELInterne(TROIS_UNITES);      
    }
    // Éteindre unite * 1 entre les parties d'une lettre
    eteindreDELInterne(UNITE);

    // Décrémentation de "positionValeur" pour changer de bite à isoler depuis "p_valeurIndexTab".
    --positionValeur;
    
    // Réatribution d'une nouvelle valeur à "valeurBite" grace à l'opérateur ">>" 
    // depuis "p_valeurIndexTab" avec la nouvelle valeur de "positionValeur".
    // "valeurBite sera remasqué en début de boucle pour isoler le bite suivant."
    valeurBite = p_valeurIndexTab >> positionValeur;
  }
  // Ajouter éteindre * 2 pour avoir unité * 3 entre les lettres
  eteindreDELInterne(DEUX_UNITES);
}

void Morse::allumerDELInterne(short p_duree) const {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}
void Morse::eteindreDELInterne(short p_duree) const {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}
