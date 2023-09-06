#include<iostream>
#include<string>
#ifndef MOVECARD_H_
#define MOVECARD_H_
#include<Player.h>

class CardMoney : public Card {

	private:
	string cardText;
	int moneyAmount;

	public:
	CardMoney();
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Bank* bank1, Player* player1);
	string getCardText(int num);

};

#endif
