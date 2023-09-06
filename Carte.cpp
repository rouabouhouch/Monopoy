#include "carte.h"
#include <string>

/**
@brief constructeur qui initialise les différents champs
@param txt texte de la cartee
@param arg argent que rapporte la carte
@param indice indice d'où ce trouve sur le plateau la case où déplacer le joueur
*/
Carte::Carte(string txt, int arg, int indice){
    texteCarte=txt;
    argentCarte=arg;
    //deplacementCarte=cas;
    indiceCase=indice;
}

/**
@brief getter sur la donnée membre privé : texteCarte
@return string texteCarte
*/
string Carte::getTexteCarte(){
    return texteCarte;
}

/**
@brief getter sur la donnée membre privé : argentCarte
@return int argentCarte
*/
int Carte::getArgentCarte(){
    return argentCarte;
}
/*
Case* Carte::getDeplacementCarte(){
    return deplacementCarte;
}*/

/**
@brief getter sur la donnée membre privé : indiceCase
@return int indiceCase
*/
int Carte::getIndiceCase(){
    return indiceCase;
}




/*
Carte::Carte(){
	cardText = "Nom carte";
	moneyAmount = 0;
	int index_size = 5;
    int shuffle_count = 10;
    int index[index_size];

    for(int i =0; i<index_size; i++){
        index[i] = i;
    }
    int tmp, rand1, rand2;
    for(int i=0; i<shuffle_count; i++){
        rand1 = rand()%index_size;
        rand2 = rand() %index_size;
        tmp = index[rand1];
        index[rand1] = index[rand2];
        index[rand2] = tmp;
    }


	     //setting up the Chance cards
	            chance = new Carte*[5];

		        chance[index[0]] = new Carte();
		        chance[index[1]] = new Carte();
		        chance[index[2]] = new Carte();
		        chance[index[3]] = new Carte();
		        chance[index[4]] = new Carte();

		        //Chance Card 0
		        chance[index[0]]->setCardText("./chance/chance0.png");
		        chance[index[0]]->setAmount(0);

		        //Chance Card 1
		        chance[index[1]]->setCardText("./chance/chance1.png");
		        chance[index[1]]->setAmount(28);

		        //Chance Card 2
		        chance[index[2]]->setCardText("./chance/chance2.png");
		        chance[index[2]]->setAmount(50);

		        //Chance Card 3
		        chance[index[3]]->setCardText("./chance/chance3.png");
		        chance[index[3]]->setAmount(11);

		        //Chance Card 4
		        chance[index[4]]->setCardText("./chance/chance4.png");
		        chance[index[4]]->setAmount(100);

		        //Chance Card 5
		        chance[index[5]]->setCardText("./chance/chance5.png");
		        chance[index[5]]->setAmount(15);


		        community = new Carte*[5];

		        community[index[0]] = new Carte();
		        community[index[1]] = new Carte();
		        community[index[2]] = new Carte();
		        community[index[3]] = new Carte();
		        community[index[4]] = new Carte();

		        //Community Card 0
		        community[index[0]]->setCardText("./community/community0.png");
		        community[index[0]]->setAmount(0);

		        //Community Card 1
		        community[index[1]]->setCardText("./community/community1.png");
		        community[index[1]]->setAmount(75);

		        //Community Card 2
		        community[index[2]]->setCardText("./community/community2.png");
		        community[index[2]]->setAmount(150);

		        //Community Card 3
		        community[index[3]]->setCardText("./community/community3.png");
		        community[index[3]]->setAmount(24);

		        //Community Card 4
		        community[index[4]]->setCardText("./community/community4.png");
		        community[index[4]]->setAmount(100);

		        //Community Card 5
		        community[index[5]]->setCardText("./community/community5.png");
		        community[index[5]]->setAmount(20);



}

void Carte::setAmount(int num){
	moneyAmount = num;

}

void Carte::setCardText(string text1){
	cardText = text1;

}

void Carte::cardAction(Joueur* player1){

	player1->giveMoney(moneyAmount);
}

string Carte::getCardText(int num){
	return cardText;
}
*/


