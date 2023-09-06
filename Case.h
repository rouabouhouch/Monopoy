#ifndef _CASE_H_
#define _CASE_H_

#include <string>
#include <iostream>

using namespace std;
class Joueur;


class Case {

private:
    string nomC;
    int typeCase; //ex : 0 pour case départ, 1 pour case à acheter, 2 pour gare...
    int prixCase;
    int loyer;
    Joueur* possederPar;
    int positionDansPlateau;

public:
    Case(int positionDansPlateau, string nom, int typeCase, int prixCase, int loyer);
    ~Case();

    string getNomC();
    int getTypeCase();
    int getPrix();
    int getLoyer();
    int getPositionDansPlateau();
    Joueur* getPossederPar();
    void setPossederPar(Joueur* j);


};

#endif // _CASE_H_
