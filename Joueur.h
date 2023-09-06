#ifndef _JOUEUR_H_
#define _JOUEUR_H_
#include <string>
//#include<cstring>
#include <vector>

using namespace std;

class Case;

class Joueur {

private:
	//string gamePieceName;
	string nomJ;
	Case* joueurPosition;
	int argent;
    //vector<Case> casePosseder;
    bool estIA;
    int nbGare;
    int nbCompagnie;


public:
        //constructors
	Joueur(string nom, Case* depart, bool IA);
    Joueur(Case* depart);

        //functions to set
	void setNom(string inputName);
	//void setGamePieceName(string inputPieceName);
	void setArgent(int arg);
    //void setCasePossede(Case* cas);
    void setJoueurPosition(Case* cas);

        //functions to get
	string getNom();
	string getgamePieceName;
	int getArgent();
	//string getCassePossede();
    Case* getJoueurPosition();
    bool getEstIA();
    int getNbGare();
    int getNbCompagnie();

        //money functions
	void giveMoney(int amount);
	void takeMoney(int amount);

    void ajouterGare();
    void ajouterCompagnie();

    };

 #endif // _JOUEUR_H_
