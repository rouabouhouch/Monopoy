#ifndef _JEU_H_
#define _JEU_H_

#include "Joueur.h"
#include "Plateau.h"
#include "Carte.h"
#include "JeuDeCarte.h"

class Jeu {

private:
    int nbJ;
    Joueur* tabJ[4];
    JeuDeCarte* jeuDeCarte;

public :
    Jeu(Case* cas);
    Jeu(Case* cas, int nbJoueur);
    Joueur* getJoueurParIndice(int numJ);
    void setJoueurParIndice(int nmJ, Joueur* j);
    int getNbJ();
    Joueur** getTabJ();
    JeuDeCarte* getJeuDeCarte();
    int lancerDeDe();
    //void unTour();
    void deplacerJoueur(Case* cas, int numJ);
    //void actionCase(int numJ);
    void acheterCase(int numJ);
    void payerLoyer(int numJ);
    void payerLoyerGare(int numJ);
    void payerLoyerCompagnie(int numJ, int de);
};

#endif // _JEU_H_
