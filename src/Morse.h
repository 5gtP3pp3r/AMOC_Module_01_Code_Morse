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

//                               a      b       c       d     e     f       g      h      i      j       k      l      m     
const String TAB_ALPHABET[26] = {"cl", "lccc", "lclc", "lcc", "c", "cclc", "llc", "cccc", "cc", "clll", "lcl", "clcc", "ll",
//                               n      o      p       q       r      s     t     u      v       w      x       y       z
                                "lc", "lll", "cllc", "llcl", "clc", "ccc", "l", "ccl", "cccl", "cll", "lccl", "lcll", "llcc"};
// À essayer plus tard: Utiliser tableau de byte! (0b1010)
//                                   0        1        2        3        4        5        6        7        8        9        
const String TAB_NUMERIQUE[10] = {"lllll", "cllll", "cclll", "cccll", "ccccl", "ccccc", "lcccc", "llccc", "lllcc", "llllc"};

const short UNITE = 200;

Morse();
void allumerDELInterne(short p_duree);
void eteindreDELInterne(short p_duree);
void executerSelonValeurIndex(String p_valeurIndexTab);

};
