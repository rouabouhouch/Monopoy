#include "affichageTxt.h"
#include "Jeu.h"


#include <string>

#include <iostream>

#include <chrono>
#include <thread>

using namespace std;


affichageTxt::affichageTxt() {

}

/**
@brief affichage du plateau. Affiche les joueurs sur la case ou ils se trouvent
@param tabJ le tableau des joueurs
*/
void affichageTxt::afficherPlateau(Joueur** tabJ) {

    for(int i = 0; i<plat.getTaille(); i++) {
        cout<<"------------------------------------"<<endl;
        cout<<plat.getCase(i)->getNomC()<<endl;
        cout<<"Prix : " << plat.getCase(i)->getPrix()<<endl<<endl;
        for(int j =0; j<jeu->getNbJ(); j++) {
            if(plat.getCase(i)==tabJ[j]->getJoueurPosition()){ //si le joueur est sur la case
                cout<<jeu->getJoueurParIndice(j)->getNom()<<" (joueur "<<j+1<<")"<<endl;
            }
        }
        if(plat.getCase(i)->getTypeCase()==5){ //case visite prison : alors il faut afficher la case prison
            cout<<"------------------------------------"<<endl;
            cout<<plat.getCasePrison()->getNomC()<<endl;
            for(int j =0; j<jeu->getNbJ(); j++) {
                if(plat.getCasePrison()==tabJ[j]->getJoueurPosition()){ //si le joueur est sur la case prison
                    cout<<jeu->getJoueurParIndice(j)->getNom()<<" (joueur "<<j+1<<")"<<endl;
                }
            }
        }
        cout<<"------------------------------------"<<endl<<endl<<endl;
    }
}

/**
@brief affichage les règles du jeu
*/
void affichageTxt::afficherRegleDuJeu() {
    cout <<"----------------REGLES DU JEU-------------------------"<<endl;
    cout<<"Chaque joueur commence avec 1500M (2x500 + 4x100 + 1x50 + 1x20 + 2x10 + 1x5 + 5x1)"<<endl;
    cout<<"3 types de propriétés :"<<endl;
    cout<<"  -Terrains : à acheter puis se faire payer le loyer"<<endl;
    cout<<"  -Gares : le loyer double pour chaque gare pocédé (25/50/100/200)"<<endl;
    cout<<"  -Compagnie de sevice public : lancer les dé, le motant à payer est de 4 fois le réusltat ou 10 fois si on pocède les 2 "<<endl;
    cout<<endl;
    cout<<"Les cases impots (ex: Taxe de luxe) sont simplement à payer"<<endl;
    cout<<"Sur le parc gratuit rien ne se passe, chill !"<<endl;
    cout<<"La case <<ALLER EN PRISON>> vous déplace dans le case prison"<<endl;
    cout<<"Pour sortir de prison : "<<endl;
    cout<<"  -Payer une amande de 50M avant le tour, puis lancer les dé et jouer son tour"<<endl;
    cout<<"  -Passer un tour"<<endl;
    cout<<endl;
    cout<<"2 types de carte à piocher : "<<endl;
    cout<<"  -Les cartes communautés qui vous font gagner de l'argent"<<endl;
    cout<<"  -Les cartes chance qui vous déplace sur le plateau"<<endl;
    cout<<"----------------FIN DES REGLES DU JEU------------------"<<endl;

}

/**
@brief appel l'affichage du palteau puis débute une boucle infinie d'enchaînement de tour de jeu
*/
void affichageTxt::unePartie() {
    choixNbJoueur();
    cout<<"Plateau de jeu : "<<endl<<endl;

     //faire une pause dans l'affichage :
        std::this_thread::sleep_for(std::chrono::milliseconds(750));

    afficherPlateau(jeu->getTabJ());
    while(true) {
        lancerTour();
    }
}

/**
@brief fonction d'interaction IHM pour choisir et saisir le nombre de joueur
*/
void affichageTxt::choixNbJoueur() {
    int reponse = -1;
    while(reponse<1 || reponse>4) {
        cout<<"Saisir le nombre de joueur pour la partie (entre 1 et 4) (IA compris) : "<<endl;
        cin>>reponse;
    }
    jeu = new Jeu(plat.getCase(0),reponse);

    for(int i =0; i<reponse; i++) {
        char repIA = 'a';
        while(repIA != 'o'&& repIA != 'n') {
        cout<< "Joueur "<<i+1<<" est une IA ? (tapez o pour <<oui>> n pour <<non>>)"<<endl;
        cin>>repIA;
        }
        if(repIA == 'o') {
            string nom = "IA";
            jeu->setJoueurParIndice(i, new Joueur(nom, plat.getCase(0),true));
        }else{

            cout<<"Saisir le nom du joueur "<<i+1<<" : "<<endl;
            string repNom;
            cin>>repNom;
            Joueur * j = new Joueur(repNom, plat.getCase(0),false);
            jeu->setJoueurParIndice(i, j);
        }
    }
    cout<<endl<<endl;
}

/**
@brief fonction qui lance un tour soit IA, soit humain soit un tour de joueur en prison
*/
void affichageTxt::lancerTour(){
    for(int i=0;i<jeu->getNbJ(); i++) {
            if(jeu->getJoueurParIndice(i)->getEstIA()) {
                    if(jeu->getJoueurParIndice(i)->getJoueurPosition()==plat.getCasePrison()){
                        tourPrisonIA(i);
                    }else{
                        unTourIA(i);
                    }
            }else{ // n'est pas une IA
                if(jeu->getJoueurParIndice(i)->getJoueurPosition()==plat.getCasePrison()){
                    tourPrison(i);
                }else{
                    unTour(i);
                }
            }
    }
}


/**
@brief fonction IHM d'un tour prison
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::tourPrison(int numJ){
    cout<<endl;
    cout<<"Tour de joueur : "<<jeu->getJoueurParIndice(numJ)->getNom() <<" (joueur "<<numJ+1<<")"<<endl;

    cout<<"Vous êtes en prison, vous avez 2 choix:"<<endl;
    cout<<"  -Payer une amende de 50M puis jouer votre tour"<<endl;
    cout<<"  -Passez votre tour et joueur au tour prochain"<<endl;

    char reponse ='a';
    while(reponse != 'o'&& reponse != 'n') {
        cout<<"Saisir o pour payer ou n pour passer son tour : "<<endl;
        cin>>reponse;
    }
    if(reponse=='o'){
        cout<<"Votre argent avant amende :"<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        jeu->getJoueurParIndice(numJ)->takeMoney(50);
        cout<<"Votre argent après amende :"<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
            //changer la postion du joueur en visite simple
        jeu->getJoueurParIndice(numJ)->setJoueurPosition(plat.getCase(10));
            //puis lancer le tour
        cout<<"Votre tour va débuter : "<<endl;
        unTour(numJ);
    }else{//le joueur perd un tour
        cout<<"Vous passez votre tour mais sortez de prison"<<endl;
            //changer la postion du joueur en visite simple
        jeu->getJoueurParIndice(numJ)->setJoueurPosition(plat.getCase(10));
    }

}


/**
@brief gestion d'un tour prison par l'IA
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::tourPrisonIA(int numJ){
    cout<<endl;
    cout<<"Tour de joueur : "<<jeu->getJoueurParIndice(numJ)->getNom() <<" (joueur "<<numJ+1<<")"<<endl;

    cout<<"Vous êtes en prison, vous avez 2 choix:"<<endl;
    cout<<"  -Payer une amende de 50M puis jouer votre tour"<<endl;
    cout<<"  -Passez votre tour et joueur au tour prochain"<<endl;

    char reponse ='o';

        cout<<"Saisir o pour payer ou n pour passer son tour : "<<endl;
        cin>>reponse;

    if(reponse=='o'){
        cout<<"Votre argent avant amende :"<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        jeu->getJoueurParIndice(numJ)->takeMoney(50);
        cout<<"Votre argent après amende :"<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
            //changer la postion du joueur en visite simple
        jeu->getJoueurParIndice(numJ)->setJoueurPosition(plat.getCase(10));
            //puis lancer le tour
        cout<<"Votre tour va débuter : "<<endl;
        unTour(numJ);
    }else{//le joueur perd un tour
        cout<<"Vous passez votre tour mais sortez de prison"<<endl;
            //changer la postion du joueur en visite simple
        jeu->getJoueurParIndice(numJ)->setJoueurPosition(plat.getCase(10));
    }
}

/**
@brief fonction d'un tour IHM
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::unTour(int i) {
    cout<<endl;
    cout<<"Tour de joueur : "<<jeu->getJoueurParIndice(i)->getNom() <<" (joueur "<<i+1<<")"<<endl;

    //---------------------------------
    //saisie de l'utilisateur pour lancer le dé:
    //---------------------------------
    char rep = 'a';
    while(rep !='o'){
        cout<<"Pour lancer le dé saisir o (pour <<oui>>) :"<<endl;
        cin>>rep;
    }
    //---------------------------------

    int lance = jeu->lancerDeDe();
    cout<<"Vous avez fait : "<<lance<<endl<<endl;

    //faire une pause dans l'affichage :
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    int nouvellePosition = jeu->getJoueurParIndice(i)->getJoueurPosition()->getPositionDansPlateau() /*ancienne place + lancé de dé*/ + lance;
    if(nouvellePosition>plat.getTaille()) { //si le joueur passe par la case départ il recois de l'argent
        caseDepart(i);
    }
    nouvellePosition = (jeu->getJoueurParIndice(i)->getJoueurPosition()->getPositionDansPlateau() /*ancienne place + lancé de dé*/ + lance)%plat.getTaille();
    jeu->deplacerJoueur(plat.getCase(nouvellePosition), i);
    cout<<"Plateau après le tour de jeu : "<<endl<<endl;
    afficherPlateau(jeu->getTabJ());
    actionCase(i);

}


/**
@brief fonction d'affichage que le joueur est passé par la case dépoart
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::caseDepart(int numJ){
    cout<<endl;
    cout<<"Vous êtes passé par la case départ, recevez 200M"<<endl;
    jeu->getJoueurParIndice(numJ)->giveMoney(200);
    cout<<"Votre argent : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl<<endl;
    //faire une pause dans l'affichage après une acrtion faites automatiquement :
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

/**
@brief gestion d'un tour par l'IA
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::unTourIA(int i) {
    cout<<endl;
    cout<<"Tour de joueur : "<<jeu->getJoueurParIndice(i)->getNom() <<" (joueur "<<i+1<<")"<<endl;

    cout<<"Pour lancer le dé saisir o (pour <<oui>>) :"<<endl;
    //faire une pause dans l'affichage :
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout<<"o"<<endl;

    int lance = jeu->lancerDeDe();
    cout<<"Vous avez fait : "<<lance<<endl<<endl;

     //faire une pause dans l'affichage :
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    int nouvellePosition = (jeu->getJoueurParIndice(i)->getJoueurPosition()->getPositionDansPlateau() /*ancienne place + lancé de dé*/ + lance)%plat.getTaille();
    jeu->deplacerJoueur(plat.getCase(nouvellePosition), i);
    cout<<"Plateau après le tour de jeu : "<<endl<<endl;
    afficherPlateau(jeu->getTabJ());
    actionCaseIA(i);
}


/**
@brief gestion de l'action de la nouvelle case position du joueur en fonction du type de case
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::actionCase(int numJ) {
    //définition de quelque constante :
    int typeCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getTypeCase();
    Joueur* jQuiPossedeCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar();
    int argentJoueur = jeu->getJoueurParIndice(numJ)->getArgent();
    int prixCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPrix();
    string nomCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC();



    //case 0: case départ
    //case 1: case achetable
    //case 2: Gare
    //case 3: piocher une carte Chance
    //case 4: aller en prison
    //case 5: case visite prison
    //case 6: piocher une carte Communauté
    //case 7: case à payer (impôt)
    //case 8: Compagnie de sevice public
    //case 9: Parc gratuit
    //case 10: La prison

    switch (typeCase) {
        case 0 : //case départ
            cout<<"Vous êtes sur la case départ, rien de spécial"<<endl;
            break;
        case 1 : //case achetable

                //si la case appartient à personne il peut l'acheter
            if(jQuiPossedeCase == NULL) {

                //si le joueur à plus d'argent que coût la case alors il peut l'acheter
                if(argentJoueur > prixCase) { //peut acheter la case
                    acheterCase(numJ);

                } else {
                    //peut pas acheter la case
                    cout << "Vous n'avez pas assez d'argent pour acheter la case"<<endl;
                }

            } else { //sinon il doit payer le joueur qui la possède
                payerLoyer(numJ);
            }

            break ;
        case 2 : //gare
            //si la case appartient à personne il peut l'acheter
            if(jQuiPossedeCase == NULL) {

                //si le joueur à plus d'argent que coût la case alors il peut l'acheter
                if(argentJoueur > prixCase) { //peut acheter la case
                    acheterCase(numJ);

                } else {
                    //peut pas acheter la case
                    cout << "Vous n'avez pas assez d'argent pour acheter la case"<<endl;
                }

            } else { //sinon il doit payer le joueur qui la possède
                payerLoyerGare(numJ);
            }

            break;
        case 3 : //tirer une carte Chance
            tirerCarteChance(numJ);

            break;
        case 4 : //aller en prison
            cout<<"Vous allez en prison"<<endl;
            jeu->deplacerJoueur(plat.getCasePrison(),numJ);

            break;
        case 5 : //case visite prison
            cout<<"Vous visitez la prison, rien de spécial"<<endl;


            break;
        case 6 : //tirer une carte Communauté
            tirerCarteCommunaute(numJ);


            break;
        case 7 : //case à payer (ex : impôt)
            payerImpot(numJ);

            break;
        case 8 : //Compagnie de sevice public
            //si la case appartient à personne il peut l'acheter
            if(jQuiPossedeCase == NULL) {

                //si le joueur à plus d'argent que coût la case alors il peut l'acheter
                if(argentJoueur > prixCase) { //peut acheter la case
                    acheterCase(numJ);

                } else {
                    //peut pas acheter la case
                    cout << "Vous n'avez pas assez d'argent pour acheter la case"<<endl;
                }

            } else { //sinon il doit payer le joueur qui la possède
                payerLoyerCompagnie(numJ);
            }


            break;
        case 9 : //parc gratuit
            cout<<"Vous êtes au Parc Gratuit. Vous n'avez rien à faire, repos !"<<endl;

            break;
        case 10 : // La prison
            //on est pas censé arriver ici
            cout<<"Vous êtes en Prison"<<endl;

            break;

    }
}

/**
@brief fonction IHM de l'achat d'une case
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::acheterCase(int numJ){
    char reponse ='a';
    while(reponse != 'o'&& reponse != 'n') {
        cout<< "Voulez vous acheter la case : <<"<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC();
        cout<<">> pour : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPrix()<<"M"<<endl;
        cout<<"Votre argent : "<< jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl<<endl;
        cout<<"Sasir o (pour oui) ou n (pour non) : ";

        //---------------saisie de l'utilisateur
        cin>> reponse;
        //------------------------------

        if(reponse=='o'){ //il faut soustraire le prix de la case
            jeu->acheterCase(numJ);
            if(jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getTypeCase()==2){ //c'est une gare
                jeu->getJoueurParIndice(numJ)->ajouterGare();
            }
            if(jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getTypeCase()==8){ //c'est une compagnie
                jeu->getJoueurParIndice(numJ)->ajouterCompagnie();
            }
            cout<<endl;
            cout<<"Vous avez bien acheté la case. Il vous reste : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        }//sinon rien à faire
    }

}

/**
@brief fonction qui gère l'affichage pour payer le loyer
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::payerLoyer(int numJ){
    cout<<"Vous êtes sur la case : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC()<<endl;
    if (jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()==jeu->getJoueurParIndice(numJ)) { //si la case lui appartient il n'a rien à faire
        cout <<"Cette case vous appartient ! Vous n'avez rien à faire"<<endl;
    }else{
        cout<<"Cette case est possédée par : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNom()<<endl;
        cout<<"Vous devez donc payer le loyer : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getLoyer()<<"M"<<endl;
        cout<<"Votre argent avant de payer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        jeu->payerLoyer(numJ);
        cout<<"Votre argent après avoir payer le loyer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        }
}

/**
@brief fonction qui gère l'affichage pour payer le loyer d'une gare
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::payerLoyerGare(int numJ){
    cout<<"Vous êtes sur la case : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC()<<endl;
    if (jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()==jeu->getJoueurParIndice(numJ)) { //si la case lui appartient il n'a rien à faire
        cout <<"Cette case vous appartient ! Vous n'avez rien à faire"<<endl;
    }else{
        cout<<"Cette case est possédée par : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNom()<<endl;
        cout<<"Ce joueur pocède : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbGare()<< " gare(s)"<<endl;
        cout<<"Vous devez donc payer un loyer de : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getLoyer()*jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbGare()<<"M (nombre de gare x 25)"<<endl;
        cout<<"Votre argent avant de payer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        jeu->payerLoyerGare(numJ);
        cout<<"Votre argent après avoir payer le loyer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        }
}

/**
@brief fonction IH% qui gère la facon de payer le loyer d'une compagnie
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::payerLoyerCompagnie(int numJ){
    cout<<"Vous êtes sur la case : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC()<<endl;
    if (jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()==jeu->getJoueurParIndice(numJ)) { //si la case lui appartient il n'a rien à faire
        cout <<"Cette case vous appartient ! Vous n'avez rien à faire"<<endl;
    }else{
        cout<<"Cette case est possédée par : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNom()<<endl;
        cout<<"Ce joueur pocède : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbCompagnie()<< " Compagnie(s)"<<endl;
        cout<<"Pour connaître le motant du loyer vous devez tirer le dé. Le motant sera de 4 (pour 1 compagnie) ou 10 fois (pour 2) le résultat dé."<<endl;

        char rep = 'a';
        while(rep !='o'){
            cout<<"Pour lancer le dé saisir o (pour <<oui>>) :"<<endl;
            cin>>rep;
        }

        int lance = jeu->lancerDeDe();
        cout<<"Vous avez fait : "<<lance<<endl<<endl;
        cout<<"Votre argent avant de payer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        jeu->payerLoyerCompagnie(numJ, lance);
        cout<<"Votre argent après avoir payer le loyer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        }
}


/**
@brief fonction d'affichage pour payer un impot
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::payerImpot(int numJ){
    cout<<"Aie, vous êtes sur la case : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC()<<endl;
    cout<<"Vous devez payer : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPrix()<<"M"<<endl;
    jeu->getJoueurParIndice(numJ)->takeMoney(jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPrix());
    cout<<"Argent après impot : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;

    //faire une pause dans l'affichage après une acrtion faites automatiquement :
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

/**
@brief fonction d'affichage du tirage d'une carte communauté
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::tirerCarteCommunaute(int numJ){
    cout<<"Vous tirez une carte Communauté !"<<endl;
    Carte* carte = jeu->getJeuDeCarte()->tirerCarteCommunaute();
    cout<<carte->getTexteCarte()<<endl;
    cout<<"Argent avant : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
    jeu->getJoueurParIndice(numJ)->giveMoney(carte->getArgentCarte());
    cout<<"Argent arpès : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
}

/**
@brief fonction d'affichage du tirage d'une carte chance
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::tirerCarteChance(int numJ){
    cout<<"Vous tirez une carte Chance !"<<endl;
    Carte* carte = jeu->getJeuDeCarte()->tirerCarteChance();
    cout<<carte->getTexteCarte()<<endl;
    jeu->deplacerJoueur(plat.getCase(carte->getIndiceCase()),numJ);
}


/**
@brief fonction de gestion des actions des cases par l'IA en fonction du type de case
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::actionCaseIA(int numJ){
    //définition de quelque constante :
    int typeCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getTypeCase();
    Joueur* jQuiPossedeCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar();
    int argentJoueur = jeu->getJoueurParIndice(numJ)->getArgent();
    int prixCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPrix();
    string nomCase = jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC();



    switch (typeCase) {
        case 0 : //case départ
            cout<<"Vous êtes sur la case départ, rien de spécial"<<endl;
            break;
        case 1 : //case achetable

                //si la case appartient à personne il peut l'acheter
            if(jQuiPossedeCase == NULL) {

                //si le joueur à plus d'argent que coût la case alors il peut l'acheter
                if(argentJoueur > prixCase) { //peut acheter la case
                        acheterCaseIA(numJ);

                } else {
                    //peut pas acheter la case
                    cout << "Vous n'avez pas assez d'argent pour acheter la case"<<endl;
                }

            } else { //sinon il doit payer le joueur qui la possède
                payerLoyer(numJ);
                }

            break ;
        case 2 : //gare
            //si la case appartient à personne il peut l'acheter
            if(jQuiPossedeCase == NULL) {

                //si le joueur à plus d'argent que coût la case alors il peut l'acheter
                if(argentJoueur > prixCase) { //peut acheter la case
                    acheterCaseIA(numJ);


                } else {
                    //peut pas acheter la case
                    cout << "Vous n'avez pas assez d'argent pour acheter la case"<<endl;
                }

            } else { //sinon il doit payer le joueur qui la possède
                payerLoyerGare(numJ);
            }



            break;
        case 3 : //tirer une carte
            tirerCarteChance(numJ);

            break;
        case 4 : //aller en prison
            cout<<"Vous allez en prison"<<endl;
            jeu->deplacerJoueur(plat.getCasePrison(),numJ);


        case 5 : //case visite prison
            cout<<"Vous visitez la prison, rien de spécial"<<endl;

            break;
        case 6 : // communauté
            tirerCarteCommunaute(numJ);

            break;
        case 7 : //case à payer (ex : impôt)
            payerImpot(numJ);

            break;
        case 8 : //Compagnie de sevice public
            //si la case appartient à personne il peut l'acheter
            if(jQuiPossedeCase == NULL) {

                //si le joueur à plus d'argent que coût la case alors il peut l'acheter
                if(argentJoueur > prixCase) { //peut acheter la case
                    acheterCaseIA(numJ);

                } else {
                    //peut pas acheter la case
                    cout << "Vous n'avez pas assez d'argent pour acheter la case"<<endl;
                }

            } else { //sinon il doit payer le joueur qui la possède
                //payerLoyerCompagnieIA(numJ);
            }


            break;
        case 9 : //parc gratuit
            cout<<"Vous êtes au Parc Gratuit. Vous n'avez rien à faire, repos !"<<endl;

            break;
        case 10 : // La prison
            //on est pas censé arriver ici
            cout<<"Vous êtes en Prison"<<endl;

            break;
    }
}

/**
@brief fonction de gestion de l'achat d'une case par l'IA
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::acheterCaseIA(int numJ){
    char reponse ='o';
        cout<< "Voulez vous acheter la case : <<"<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC();
        cout<<">> pour : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPrix()<<"M"<<endl;
        cout<<"Votre argent : "<< jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl<<endl;
        cout<<"Sasir o (pour oui) ou n (pour non) : ";

        //---------------saisie de l'utilisateur
        cout<<reponse;
        //------------------------------

        if(reponse=='o'){ //il faut soustraire le prix de la case
            jeu->acheterCase(numJ);
            if(jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getTypeCase()==2){ //c'est une gare
                jeu->getJoueurParIndice(numJ)->ajouterGare();
            }
            if(jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getTypeCase()==8){ //c'est une compagnie
                jeu->getJoueurParIndice(numJ)->ajouterCompagnie();
            }
            cout<<endl;
            cout<<"Vous avez bien acheté la case. Il vous reste : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        }//sinon rien à faire

}

/**
@brief fonction de gestion d'un loyer de compagnie par l'IA
@param numJ le numéro du joueur dont c'est le tour
*/
void affichageTxt::payerLoyerCompagnieIA(int numJ){
    cout<<"Vous êtes sur la case : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getNomC()<<endl;
    if (jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()==jeu->getJoueurParIndice(numJ)) { //si la case lui appartient il n'a rien à faire
        cout <<"Cette case vous appartient ! Vous n'avez rien à faire"<<endl;
    }else{
        cout<<"Cette case est possédée par : " << jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNom()<<endl;
        cout<<"Ce joueur pocède : "<<jeu->getJoueurParIndice(numJ)->getJoueurPosition()->getPossederPar()->getNbCompagnie()<< " Compagnie(s)"<<endl;
        cout<<"Pour connaître le motant du loyer vous devez tirer le dé. Le motant sera de 4 (pour 1 compagnie) ou 10 fois (pour 2) le résultat dé."<<endl;

        char rep = 'o';
        cout<<"Pour lancer le dé saisir o (pour <<oui>>) :"<<endl;

        //faire une pause dans l'affichage :
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        cin>>rep;

        int lance = jeu->lancerDeDe();
        cout<<"Vous avez fait : "<<lance<<endl<<endl;
        cout<<"Votre argent avant de payer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        jeu->payerLoyerCompagnie(numJ, lance);
        cout<<"Votre argent après avoir payer le loyer : "<<jeu->getJoueurParIndice(numJ)->getArgent()<<"M"<<endl;
        }
}

