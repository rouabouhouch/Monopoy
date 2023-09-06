#include "Case.h"
#include "Joueur.h"

/**
@brief constructeur qui initialise les différents champs
@param position la position de la case dans le plateau
@param nom nom de la case
@param type décrit le type de la case :
    0: case départ,
    1: case achetable,
    2: Gare,
    3: piocher une carte Chance,
    4: aller en prison,
    5: case visite prison,
    6: piocher une carte Communauté,
    7: case à payer (impôt),
    8: Compagnie de sevice public,
    9: Parc gratuit,
    10: La prison
@param prix le prix que coute la case
@param loy le prix du loyer de la case
*/
Case::Case(int position, string nom, int type, int prix, int loy) {
    typeCase= type;
    prixCase = prix;
    loyer = loy;
    possederPar=NULL;
    nomC = nom;
    positionDansPlateau=position;
}
Case::~Case() {}

/**
@brief getter sur la donnée membre privé : nomC
@return string nomC
*/
string Case::getNomC() {
    return nomC;
}

/**
@brief getter sur la donnée membre privé : typeCase
@return int typeCase
*/
int Case::getTypeCase() {
    return typeCase;
}

/**
@brief getter sur la donnée membre privé : prixCase
@return int prixCase
*/
int Case::getPrix() {
    return prixCase;
}

/**
@brief getter sur la donnée membre privé : loyer
@return int loyer
*/
int Case::getLoyer() {
    return loyer;
}

/**
@brief getter sur la donnée membre privé : possederPar
@return Joueur* loyer
*/
Joueur* Case::getPossederPar() {
    return possederPar;
}

/**
@brief getter sur la donnée membre privé : positionDansPlateau
@return int positionDansPlateau
*/
int Case::getPositionDansPlateau() {
    return positionDansPlateau;
}

/**
@brief setter sur la donnée membre privé : possederPar
@param j joueur qui possède maintenant la case
*/
void Case::setPossederPar(Joueur* j) {
    possederPar = j;
}
