#include"Carte.h"
#ifndef JEU_DE_CARTE_H_
#define JEU_DE_CARTE_H_

class JeuDeCarte{
private:
    Carte* communaute[5];
    Carte* chance[5];

public:
    JeuDeCarte();
    Carte* tirerCarteChance();
    Carte* tirerCarteCommunaute();

};

#endif
