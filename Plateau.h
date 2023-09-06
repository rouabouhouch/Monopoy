#ifndef _PLATEAU_H_
#define _PLATEAU_H_

#include "Case.h"

class Plateau {

private:
    Case* tab[40];
    int taille;
    Case* casePrison;

public:
    Plateau();
    ~Plateau();

    int getTaille();
    Case* getCasePrison();

    void afficherPlateau(Case* caseJoueur);

    Case* getCase(int);

};


#endif // _PLATEAU_H_
