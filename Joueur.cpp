#include<iostream>
#include<cstring>
#include <vector>
#include<string>
#include "Joueur.h"
#include "Case.h"

//////////get functions

/**
@brief constructeur qui initialise les différents champs avec choix du nom et des IA
@param nom nom du joueur
@param depart case où commence le joueur (case depart)
@param IA true si le joueur est une IA, sinon false
*/
 Joueur::Joueur(string nom,Case* depart, bool IA){
    nomJ=nom;
	joueurPosition=depart;
    estIA = IA;
	 //gamePieceName="Hat";
    argent=1500;
    nbCompagnie =0;
    nbGare=0;
	}

/**
@brief constructeur qui initialise les différents champs par défaut
@param depart case où commence le joueur (case depart)
*/
 Joueur::Joueur(Case* depart){
	nomJ= "John";
	joueurPosition=depart;
	argent=1500;
	estIA = false;
	nbCompagnie =0;
    nbGare=0;
}


/**
@brief getter sur la donnée membre privé : nomJ
@return string nomJ
*/
 string Joueur::getNom(){
	return nomJ;
}

/**
@brief getter sur la donnée membre privé : argent
@return int argent
*/
int Joueur::getArgent() {
    return argent;
}

/**
@brief getter sur la donnée membre privé : joueurPosition
@return Case* joueurPosition
*/
Case* Joueur::getJoueurPosition(){
       return joueurPosition;
}

/**
@brief getter sur la donnée membre privé : estIA
@return bool estIA
*/
bool Joueur::getEstIA(){
    return estIA;
}

/**
@brief getter sur la donnée membre privé : nbGare
@return int nbGare
*/
int Joueur::getNbGare(){
    return nbGare;
}

/**
@brief getter sur la donnée membre privé : nbCompagnie
@return int nbCompagnie
*/
int Joueur::getNbCompagnie(){
    return nbCompagnie;
}

///////set functions

/*
void Joueur::setCasePossede(Case* cas){
	casePosseder.push_back(*cas);
    casePosseder.pop_back();
}
*/

/**
@brief setter sur la donnée membre privé : joueurPosition
@param cas1 case de la nouvelle position du joueur
*/
void Joueur::setJoueurPosition(Case* cas1){
	 joueurPosition=cas1;
}

/**
@brief setter sur la donnée membre privé : argent
@param arg nouvel argent du joueur
*/
 void Joueur::setArgent(int arg){
	 argent=arg;
 }


/**
@brief ajouter de l'argent au joueur
@param amount argent a ajouter
*/
void Joueur::giveMoney(int amount){
	argent=argent+amount;
}


/**
@brief retire de l'argent au joueur
@param amount argent a retirer
*/
void Joueur::takeMoney(int amount){
	 argent=argent-amount;
 }


 //the functions we may need


/**
@brief ajoute une compagnie au joueur
*/
void Joueur::ajouterCompagnie(){
    nbCompagnie = nbCompagnie +1;
}

/**
@brief ajoute une gare au joueur
*/
void Joueur::ajouterGare(){
    nbGare = nbGare + 1;
}

 /*void Player::movePlayer(int number){
	Location=Location+number;
}

void Player::setGamePieceName(string inputPieceName){
	gamePieceName=inputPieceName;
}
*/
