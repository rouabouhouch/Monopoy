#ifndef CARD_MONEY_H
#define CARD_MONEY_H

#include "carte.h"

class CarteArgent {

	private:
	string cardText;
	int moneyAmount;

	public:
	CarteArgent();
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Joueur* player1);
	string getCardText(int num);

};
#endif
