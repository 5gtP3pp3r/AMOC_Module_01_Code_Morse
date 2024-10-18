#include <Arduino.h>

/*
    1- The length of a dot is one unit.
    2- A dash is three units.
    3- The space between parts of the same letter is one unit.
    4- The space between letters is three units.
    5- The space between words is seven units.

A . _           U . . _
B _ . .         V . . . _
C _ . _ .       W . _ _
D _ . .         X _ . . _
E .             Y _ . _ _
F . . _ .       Z _ _ . . 
G _  _ .
H . . . .
I . .
J . _ _ _
K _ . _         1 . _ _ _ _
L . _ . .       2 . . _ _ _
M _ _           3 . . . _ _
N _ .           4 . . . . _
O _ _ _         5 . . . . .
P . _ _ .       6 _ . . . .
Q _ _ . _       7 _ _ . . .
R . _ .         8 _ _ _ . .
S . . .         9 _ _ _ _ .
T _             0 _ _ _ _ _

*/

// Déclaration fonction ici:
void allumerDELInterne(short p_duree);
void eteindreDELInterne(short p_duree);
void executerSelonValeurIndex(String p_valeurIndexTab);

const short unite = 200;
//                               a      b       c       d     e     f       g      h      i      j       k      l      m     
const String tabAlphabet[26] = {"cl", "lccc", "lclc", "lcc", "c", "cclc", "llc", "cccc", "cc", "clll", "lcl", "clcc", "ll",
//                               n      o      p       q       r      s     t     u      v       w      x       y       z
                                "lc", "lll", "cllc", "llcl", "clc", "ccc", "l", "ccl", "cccl", "cll", "lccl", "lcll", "llcc"};

//                                  0        1        2        3        4        5        6        7        8        9        
const String tabNumerique[10] = {"lllll", "cllll", "cclll", "cccll", "ccccl", "ccccc", "lcccc", "llccc", "lllcc", "llllc"};

String entree = "Hello World 12345";
// Représentation en morse de la string "Hello World 12345"
// [. . . .] [.] [. _ . .] [. _ . .] [_ _ _]       [. _ _] [_ _ _] [. _ .] [. _ . .] [_ . .]       [. _ _ _ _] [. . _ _ _] [. . . _ _] [. . . . _] [. . . . .]
//     h      e      l         l        o     ' '     w       o       r        l        d     ' '       1           2           3           4           5

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (byte i = 0; i < entree.length(); ++i) {  
    // Le caractère est une lettre: 
    if (toLowerCase(entree[i]) >= 'a' && toLowerCase(entree[i]) <= 'z') {
      // valeur du caractère - valeur de 'a' = sa position dans le tableau tabAlphabet. Exemples: 'a'(97) - 'a'(97) = 0, 'a' est bien à l'index 0 et'z'(122) - 'a'(97) = 25.
      String valeurIndexAlpha = tabAlphabet[toLowerCase(entree[i]) - 'a'];
      executerSelonValeurIndex(valeurIndexAlpha);
    }
    // Le caractère est un chiffre:
    else if (entree[i] >= '0' && entree[i] <= '9') {
      // Valeur du caractère - valeur de '0'= sa position dans le tableau TabNumerique. Exemples: '0' - '0' = 0 et '9' - '0' = 9.
      String valeurIndexNumerique = tabNumerique[entree[i] - '0'];
      executerSelonValeurIndex(valeurIndexNumerique);
    } 
    else {    
      // Le caractère est un espace, éteindre unité * 7 entre les mots.  
      eteindreDELInterne(unite * 7);
    }
  }
  // Montre visuellement la fin de la chaine avec: éteint 1400 ms, allumé 1400 ms et éteint 1400 ms.
  eteindreDELInterne(unite * 7);
  allumerDELInterne(unite * 7);
  eteindreDELInterne(unite * 7);
}

// Définitions des fonctions:
void allumerDELInterne(short p_duree) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}
void eteindreDELInterne(short p_duree) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}

void executerSelonValeurIndex(String p_valeurIndexTab) {
  for (byte j = 0; j < p_valeurIndexTab.length(); ++j) {
    // caractère court.
    if (p_valeurIndexTab[j] == 'c') {
      allumerDELInterne(unite);
    }
    // caractère long.
    else {
      allumerDELInterne(unite * 3);      
    }
    // Éteindre unite * 1 entre les parties d'une lettre
    eteindreDELInterne(unite);
  }
  // Ajouter éteindre * 2 pour avoir unité * 3 entre les lettres
  eteindreDELInterne(unite * 2);
}