#include <iostream>
#include "affichageTxt.h"

using namespace std;

main (void) {

    affichageTxt aff;
    aff.afficherRegleDuJeu();
    cout<<endl;
    aff.unePartie();
    return(0);

}
