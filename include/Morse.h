#pragma once
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
class Morse {

public:

Morse();
void convertirStringEnMorse(String &p_entree);
void executerSelonValeurIndex(String p_valeurIndexTab);
void allumerDELInterne(short p_duree);
void eteindreDELInterne(short p_duree);

//                               a      b       c       d     e     f       g      h      i      j       k      l      m     
const String TAB_ALPHABET[26] = {"cl", "lccc", "lclc", "lcc", "c", "cclc", "llc", "cccc", "cc", "clll", "lcl", "clcc", "ll",
//                               n      o      p       q       r      s     t     u      v       w      x       y       z
                                "lc", "lll", "cllc", "llcl", "clc", "ccc", "l", "ccl", "cccl", "cll", "lccl", "lcll", "llcc"};
//                                   0        1        2        3        4        5        6        7        8        9        
const String TAB_NUMERIQUE[10] = {"lllll", "cllll", "cclll", "cccll", "ccccl", "ccccc", "lcccc", "llccc", "lllcc", "llllc"};
/*  J'ai essayé de faire un tableau de "Byte", mais j'ai rencontré un problème. Prenons en exemple les lettres e, i, s et h. 
    Elle auraient les valeurs 0b0, 0b00, 0b000 et 0b0000. se qui revient au final à 0. donc je me retrouve avec un mauvais 
    affichage. La même chose est vrais aussi pour les valeur qui commence par 0 comme a 0b01 au final ça valeur sera 1 et 
    sera identique à la valeur de u 0b001 soit 1 aussi. J'ai besoin d'une structure qui conserve toutes les valeurs déclarées.
    Je crois donc que la string reste la meilleur option puisque je suis capable de différencier chaque valeurs c et l.*/
const short UNITE = 200;
const short DEUX_UNITES = UNITE * 2;
const short TROIS_UNITES = UNITE * 3;
const short SEPT_UNITES = UNITE *7;
};
