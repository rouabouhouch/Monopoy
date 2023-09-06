#include "Plateau.h"

/**
@brief constructeur qui initialise le tableau de Case et la taille du tableau
*/
Plateau::Plateau() {
    taille = 40;
    tab[0] = new Case(0, "Départ",0,0,0);
    tab[1] = new Case(1, "Boulevard de Belleville",1,60,2);
    tab[2] = new Case(2, "Caisse de communauté",6,0,0);
    tab[3] = new Case(3, "Rue Lecourbe",1,60,4);
    tab[4] = new Case(4, "Impôt sur le revenu",7,200,200);
    tab[5] = new Case(5, "Gare Montparnasse",2,200,25);
    tab[6] = new Case(6, "Rue de vaugirard",1,100,6);
    tab[7] = new Case(7, "Chance",3,0,0);
    tab[8] = new Case(8, "Rue de courcelles",1,100,6);
    tab[9] = new Case(9, "Avenue de la république",1,120,8);
    //plus de plateau :
    tab[10] = new Case(10, "Simple Visite",5,0,0);
    tab[11] = new Case(11, "Boulevard de la Vilette",1,140,10);
    tab[12] = new Case(12, "Compagnie de distribution d'électricité",8,150,0);
    tab[13] = new Case(13, "Avenue de Neuilly",1,140,10);
    tab[14] = new Case(14, "Rue du Paradis",1,160,12);
    tab[15] = new Case(15, "Gare de Lyon",2,200,25);
    tab[16] = new Case(16, "Avenue Mozart",1,180,14);
    tab[17] = new Case(17, "Caisse de communauté",6,0,0);
    tab[18] = new Case(18, "Boulevard Saint-Michel",1,180,14);
    tab[19] = new Case(19, "Place Pigalle",1,200,16);
    tab[20] = new Case(20, "Parc Gratuit",9,0,0);
    tab[21] = new Case(21, "Avenue Matignon",1,220,18);
    tab[22] = new Case(22, "Chance",3,0,0);
    tab[23] = new Case(23, "Boulevard Malesherbes",1,220,18);
    tab[24] = new Case(24, "Avenye Henri-Martin",1,240,20);
    tab[25] = new Case(25, "Gare du Nord",2,200,25);
    tab[26] = new Case(26, "Faubourg Saint-Honoré",1,260,22);
    tab[27] = new Case(27, "Place de la Bourse",1,260,22);
    tab[28] = new Case(28, "Compagnie de distribution des eaux",8,150,0);
    tab[29] = new Case(29, "Rue la Fayette",1,280,24);
    tab[30] = new Case(30, "Allez en Prison",4,0,0);
    tab[31] = new Case(31, "Avenue de Breteuil",1,300,26);
    tab[32] = new Case(32, "Avenue Foch",1,300,26);
    tab[33] = new Case(33, "Caisse de communauté",6,0,0);
    tab[34] = new Case(34, "Boulevard des Capucines",1,320,28);
    tab[35] = new Case(35, "Gare Saint-Lazare",2,200,25);
    tab[36] = new Case(36, "Chance",3,0,0);
    tab[37] = new Case(37, "Avenue des champs-Elysées",1,350,35);
    tab[38] = new Case(38, "Taxe de Luxe",7,100,100);
    tab[39] = new Case(39, "Avenue des champs-Elysées",1,400,50);

    //la case prison:
    casePrison = new Case(-1,"Prison",10,0,0);
}

Plateau::~Plateau() {

}

/**
@brief getter sur la donnée membre privé : taille
@return int taille
*/
int Plateau::getTaille() {
    return taille;
}

/**
@brief getter sur la donnée membre privé : casePrison
@return Case* casePrison
*/
Case* Plateau::getCasePrison(){
    return casePrison;
}

/**
@brief getter sur les différentes cases du plateau (tableau)
@param indice l'indice de la case voulu dans le tableau
@return Case*
*/
Case* Plateau::getCase(int indice) {
    bool stop = false;
    int i = 0;
    while(!stop){
        if(tab[i]->getPositionDansPlateau() == indice) {
            stop = true;
            return tab[i];
        }
        i++;
    }
    return 0;
}
