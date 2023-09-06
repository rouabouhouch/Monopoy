
#include "carte.h"
#include <string>

class CarteAct{

	private:
	string cardText;
	int locationNum;

	public:
	CarteAct();
	void setAmount(int num);
	void setCardText(string text1);
	void cardAction(Joueur* player1);
	string getCardText(int num);

};
#endif
