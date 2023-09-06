#ifndef _AFFICHAGETXT_H_
#define _AFFICHAGETXT_H_
#include "Case.h"
#include "Jeu.h"
#include "Plateau.h"
#include "Carte.h"

class affichageTxt {

private :
    Plateau plat;
    Jeu *jeu;

public :
    affichageTxt();
    void afficherPlateau(Joueur** tabJ);
    void unePartie();
    void unTour(int indinceJoueur);
    void afficherRegleDuJeu();
    void actionCase(int numJ);
    void acheterCase(int numJ);
    void payerLoyer(int numJ);
    void payerLoyerGare(int numJ);
    void payerLoyerCompagnie(int numJ);
    void caseDepart(int numJ);
    void payerImpot(int numJ);
    void choixNbJoueur();
    void lancerTour();
    void unTourIA(int indinceJoueur);
    void acheterCaseIA(int numJ);
    void actionCaseIA(int numJ);
    void tourPrison(int numJ);
    void tourPrisonIA(int numJ);
    void tirerCarteChance(int numJ);
    void tirerCarteCommunaute(int numJ);
    void payerLoyerCompagnieIA(int numJ);
};

#endif // _AFFICHAGETXT_H_


