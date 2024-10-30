#pragma once
#include <Arduino.h>
/*
    
                                LOGIQUE MORSE EN BYTE

                                [accesseur]   -> Nombre de bites contenants des valeurs
                                [non utilisé] -> Bites ignorés
                                [valeur]      -> Valeurs équivalentes "." = 0, "-" = 1

                                                                               [accesseur] [non utilisé] [valeur]
A . _         01     U . . _          001         "A" -> byte = 0b01000001 ->     [010]        [000]        [01]
B _ . . .   1000     V . . . _       0001         "B" -> byte = 0b10001000 ->     [100]          [0]      [1000]
C _ . _ .   1010     W . _ _          011         "C" -> byte = 0b10001010 ->     [100]          [0]      [1010]
D _ . .      100     X _ . . _       0110         "D" -> byte = 0b01100100 ->     [011]         [00]       [100]
E .            0     Y _ . _ _       1011         "E" -> byte = 0b00100000 ->     [001]       [0000]         [0]
F . . _ .   0010     Z _ _ . .       1100
G _ _ .      110
H . . . .   0000
I . .         00
J . _ _ _   0111
K _ . _      101     1 . _ _ _ _     01111        "1" -> byte = 0b10101111 ->     [101]                  [01111]
L . _ . .   0100     2 . . _ _ _     00111
M _ _         11     3 . . . _ _     00011
N _ .         10     4 . . . . _     00001
O _ _ _      111     5 . . . . .     00000        "5" -> byte = 0b10100000 ->     [101]                  [00000]
P . _ _ .   0110     6 _ . . . .     10000
Q _ _ . _   1101     7 _ _ . . .     11000
R . _ .      101     8 _ _ _ . .     11100
S . . .      000     9 _ _ _ _ .     11110
T _            1     0 _ _ _ _ _     11111        "0" -> byte = 0b10111111 ->     [101]                  [11111]

*/
class Morse {

public:

Morse();
void convertirStringEnMorse(const String &p_entree);
void executerSelonValeurIndex(byte p_valeurIndexTab) const;
void allumerDELInterne(short p_duree) const;
void eteindreDELInterne(short p_duree) const;

//                                 a           b           c           d           e           f           g           h           i           j           k           l           m     
const byte TAB_ALPHABET[26] = {0b01000001, 0b10001000, 0b10001010, 0b01100100, 0b00100000, 0b10000010, 0b01100110, 0b10000000, 0b01000000, 0b10000111, 0b01100101, 0b10000100, 0b01000011,
//                                 n           o           p           q           r           s           t           u           v           w           x           y           z
                               0b01000010, 0b01100111, 0b10000110, 0b10001101, 0b01100010, 0b01100000, 0b00100001, 0b01100001, 0b10000001, 0b01100011, 0b10001001, 0b10001011, 0b10001100};
//                                  0           1           2           3           4           5           6           7           8           9        
const byte TAB_NUMERIQUE[10] = {0b10111111, 0b10101111, 0b10100111, 0b10100011, 0b10100001, 0b10100000, 0b10110000, 0b10111000, 0b10111100, 0b10111110};

/*  1- Temps d'un point est un unité.
    2- Temps d'un trait est trois unités.
    3- Temps entre chaque valeurs d'une lettre ou chiffre est un unité.
    4- Temps entre chaque lettre ou chiffre est trois unités
    5- Temps entre chaque mots ou monbre est sept unités
*/
const short UNITE = 200;
const short DEUX_UNITES = UNITE * 2;
const short TROIS_UNITES = UNITE * 3;
const short SEPT_UNITES = UNITE *7;

const byte POSITION = 5;
const byte MASQUE_VALEUR = 0b00000001;
};
