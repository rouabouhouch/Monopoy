#include"Joueur.h"
#include"Case.h"
#include <string>
#ifndef CARTE_H_
#define CARTE_H_

class Carte {
private:
    string texteCarte;
    int argentCarte;
    //Case* deplacementCarte;
    int indiceCase;

public:
    Carte(string txt, int arg, int indice);
    string getTexteCarte();
    int getArgentCarte();
    //Case* getDeplacementCarte();
    int getIndiceCase();
};


/*
private:
	string cardText;
	int moneyAmount;
	Carte** chance;
	Carte** community;

	public:
	Carte();
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Joueur* player1);
	string getCardText(int num);

};
*/
#endif


