#include "CarteAct.h"
#include "carte.h"
#include <string>

CarteAct::CarteAct(){
	cardText = "Card Name";
	locationNum = -1;
}

void CarteAct::setAmount(int num){
	locationNum = num;
}

void CarteAct::setCardText(string text1){
	cardText = text1;
}

void CarteAct::cardAction(Joueur* player1){
	player1->setLocation(locationNum);
}

string CarteAct::getCardText(int num){
	return cardText;
}
