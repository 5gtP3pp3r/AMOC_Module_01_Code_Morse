#pragma once
#include <Arduino.h>
class Morse {

public:

    static const int dotDuration = 100;

    void allumerDELInterne(short p_duree);
    void eteindreDELInterne(short p_duree);
    void executerSelonValeurIndex(String p_valeurIndexTab);
};

