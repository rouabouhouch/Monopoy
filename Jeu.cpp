#include "Jeu.h"
#include <ctime>

/**
@brief constructeur qui initialise les différents champs nombre joueur par défaut (2)
@param cas la case depart
*/
Jeu::Jeu(Case* cas) { //il faut envoyer la case départ
    nbJ = 2;
    tabJ[0] = new Joueur(cas);
    tabJ[1] = new Joueur(cas);
    jeuDeCarte = new JeuDeCarte();
}

/**
@brief constructeur qui initialise les différents champs avec choix nombre de joueur
@param cas la case depart
@param nbJoueur
*/
Jeu::Jeu(Case* cas, int nbJoueur){
    nbJ=nbJoueur;
    jeuDeCarte = new JeuDeCarte();
}

/**
@brief getter d'un joueur selon son indice dans le tableau de joueur
@param numJ l'indice du joueur
@return Joueur*
*/
Joueur* Jeu::getJoueurParIndice(int numJ) {
    return (tabJ[numJ]);
}

/**
@brief getter sur la donnée membre privé : nbJ
@return int nbJ
*/
int Jeu::getNbJ() {
    return (nbJ) ;
}

/**
@brief getter sur la donnée membre privé : tabJ
@return Joueur** tabJ
*/
Joueur** Jeu::getTabJ(){
    return tabJ;
}

/**
@brief getter sur la donnée membre privé : jeuDeCarte
@return JeuDeCarte* jeuDeCarte
*/
JeuDeCarte* Jeu::getJeuDeCarte(){
    return jeuDeCarte;
}

/**
@brief setter d'un joueur selon son indice dans le tableau de joueur
@param numJ l'indice du joueur
@param j le joueur par lequel on souhaite le remplacer
*/
void Jeu::setJoueurParIndice(int numJ, Joueur* j ){
    tabJ[numJ] = j;
}


/**
@brief fonction qui fait un lancer de dé (entre 1 et 6)
@return int
*/
int Jeu::lancerDeDe() {
    srand(time(0));
    int de =(rand()%6 +1);
    return de;
}

/**
@brief fonction qui déplace la position d'un joueur sur la plateau en fonction de l'indice du joueur et de la case ou il doit être déplacé
@param cas nouvelle position du joueur
@param numJ l'indice du joueur (le numéro du joueur)
*/
void Jeu::deplacerJoueur(Case* cas, int numJ) { //il faut envoyé la case ou doit aller le joueur
        //changer la case position du joueur
    tabJ[numJ]->setJoueurPosition(cas);

}

/**
@brief retir de l'argent au joueur et change le joueur qui possède la case achetée
@param numJ numero du joueur
*/
void Jeu::acheterCase(int numJ) {
    tabJ[numJ]->takeMoney(getJoueurParIndice(numJ)->getJoueurPosition()->getPrix());
    tabJ[numJ]->getJoueurPosition()->setPossederPar(tabJ[numJ]);
}


/**
@brief retir le montant du loyer au joueur sur la case et le donne a celui qui possède la case
@param numJ numero du joueur
*/
void Jeu::payerLoyer(int numJ) {
    getJoueurParIndice(numJ)->takeMoney(getJoueurParIndice(numJ)->getJoueurPosition()->getLoyer());
    getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->giveMoney(getJoueurParIndice(numJ)->getJoueurPosition()->getLoyer());
}


/**
@brief retir le montant du loyer au joueur sur la gare et le donne a celui qui possède la gare
@param numJ numero du joueur
*/
void Jeu::payerLoyerGare(int numJ){
    //on enlève au joueur le prix du loyer x le nombre de gare
    getJoueurParIndice(numJ)->takeMoney(getJoueurParIndice(numJ)->getJoueurPosition()->getLoyer()*getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbGare());
    //on ajoute ce motant au joueur qui pocède la case :
    getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->giveMoney(getJoueurParIndice(numJ)->getJoueurPosition()->getLoyer()*getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbGare());
}

/**
@brief retir le montant du loyer au joueur sur la compagnie et le donne a celui qui possède la compagnie
@param numJ numero du joueur
@param de le loyer depends du lancer de de (cf regle du jeu)
*/
void Jeu::payerLoyerCompagnie(int numJ,int de){
    if(getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbCompagnie() ==1){
        getJoueurParIndice(numJ)->takeMoney(de*4);
        getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->giveMoney(de*4);
    }
    if(getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbCompagnie() ==2){
        getJoueurParIndice(numJ)->takeMoney(de*10);
        getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->giveMoney(de*10);
    }
}
