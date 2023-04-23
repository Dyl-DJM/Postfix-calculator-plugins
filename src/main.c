/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#include<stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include<stdlib.h>

#include"../inc/Parseur.h"
#include"../inc/Pile.h"
#include"../inc/Calcul.h"

int main(int argc, char * argv[]){

    /*On fait appel au lecteur du parseur*/
    read();

    return 0;
}

/*

COMMANDE ULTIME:

p c a 1 a c a c 0 r 1 r / % ^ a 3 ^ a 3 r ^ a 42 1984 a - - - - a 1947 - a ! 5 + ! a q

1
1
1
3
3
42
1984
1945
-2
6

Si choix d'ignorer toutes les anomalies, le programme renvoie la même chose pour la commande :

p c a 1 a c a c 0 r 1 r / % ^ a 3 ^ a 3 r ^ a 42 diobvbiov 1984 a - - - ibdcobuivf - a 1947 - a ! 5 + ! dsopcdib a q


*/

