#include "JeuDeCarte.h"
#include "Plateau.h"
#include <ctime>

/**
@brief constructeur qui initialise les tableaus des Cartes (chance et communaute)
*/
JeuDeCarte::JeuDeCarte(){

    communaute[0]= new Carte("C'est votre anniversaire : gagnez 50M",50,0);
    communaute[1]= new Carte("Retour sur investissement : gangez 20M",20,0);
    communaute[2]= new Carte("Les impôts vous rembourse: gangez 100M",100,0);
    communaute[3]= new Carte("Vous trouvez un billet de 50",50,0);
    communaute[4]= new Carte("Vous trouvez un billet de 20",20,0);

    chance[0]= new Carte("Vous vous déplacer à la case Départ (ne recevez pas 200)",0,0);
    chance[1]= new Carte("Vous vous déplacer à la case Simple Visite",0,10);
    chance[2]= new Carte("Vous vous déplacer à la case Parc Gratuit ",0,20);
    chance[3]= new Carte("Vous vous déplacer à la case Gare du Nord",0,25);
    chance[4]= new Carte("Vous vous déplacer à la case Avenue des champs-Elysées",0,39);
}

/**
@brief fonction qui effectue le dirage au sort d'une Carte chance dans le tableau
@return *Carte
*/
Carte* JeuDeCarte::tirerCarteChance(){
    srand(time(0));
    int indice =(rand()%5);
    return chance[indice];
}

/**
@brief fonction qui effectue le dirage au sort d'une Carte communaute dans le tableau
@return *Carte
*/
Carte* JeuDeCarte::tirerCarteCommunaute(){
    srand(time(0));
    int indice =(rand()%5);
    return communaute[indice];
}
