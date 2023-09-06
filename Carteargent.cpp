#include "carteargent.h"
#include <string>
#include <iostream>

CarteArgent ::CarteArgent(){
	cardText = "Nom de Cart";
	moneyAmount = 0;

}


void CarteArgent::setAmount(int num){
	moneyAmount = num;
}
void CarteArgent::setCardText(string text1){
	cardText = text1;
}

void CarteArgent::cardAction(Joueur* player1){
	player1->giveMoney(moneyAmount);
}

string CarteArgent::getCardText(int num){
	return cardText;
}
