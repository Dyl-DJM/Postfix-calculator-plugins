/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/


#include "Pile.h"
#include "Calcul.h"
#include "Parseur.h"

#include <stdio.h>

/*========================= CALCULS ==============================*/

int test_Division(){
    int res = 0;
    int erreur;

    erreur = Division(3,3, &res);
    if(res != 1)
        return 0;

    erreur = Division(1,0, &res);
    if(erreur != 0)
        return 0;

    erreur = Division(8,4, &res);
    if(res != 2)
        return 0;

    erreur = Division(-8,2, &res);
    if(res != -4)
        return 0;

    return 1;
}


int test_Facto(){
    int res = 0;
    int erreur;

    erreur = Facto(0, &res);
    if(res != 1 || erreur == 0)
        return 0;

    erreur = Facto(1, &res);
    if(res != 1)
        return 0;

    erreur = Facto(2, &res);
    if(res != 2)
        return 0;

    erreur = Facto(4, &res);
    if(res != 24)
        return 0;

    erreur = Facto(7, &res);
    if(res != 5040)
        return 0;

    erreur = Facto(10, &res);
    if(res != 3628800)
        return 0;

    erreur = Facto(-2, &res);
    if(erreur != 0)
        return 0;

    return 1;
}

int test_Modulo(){
    int res;
    int erreur;

    erreur = Modulo(3, 1, &res);
    if(res != 0)
        return 0;

    erreur = Modulo(4, 2, &res);
    if(res != 0)
        return 0;

    erreur = Modulo(7, 12, &res);
    if(res != 7)
        return 0;

    erreur = Modulo(7, -7, &res);
    if(res != 0)
        return 0;

    erreur = Modulo(0, 2, &res);
    if(res != 0)
        return 0;

    erreur = Modulo(-7, 13, &res);
    if(res != -7)
        return 0;

    erreur = Modulo(-4, -7, &res);
    if(res != -4)
        return 0;

    erreur = Modulo(12, 0, &res);
    if(erreur != 0)
        return 0;

    return 1;
}


int test_Exp(){
    int res;
    int erreur;

    erreur = Exp(2, 10, &res);
    if(res != 1024)
        return 0;

    erreur = Exp(2, -1, &res);
    if(res != 0)
        return 0;

    erreur = Exp(-4, 3, &res);
    if(res != -64)
        return 0;

    erreur = Exp(0, 3, &res);
    if(res != 0)
        return 0;

    erreur = Exp(7, 0, &res);
    if(res != 1)
        return 0;

    erreur = Exp(-7, 2, &res);
    if(res != 49)
        return 0;

    return 1;
}


/*========================= PARSEUR ==============================*/

int test_RecChaine(){

    int entier_recup;
    char char_recup;

    char * test_1 = "+";
    char * test_2 = "*essai";
    char * test_3 = "90";
    char * test_4 = "3ZEbcb4";
    char * test_5 = "100b";
    char * test_6 = "essais23";

    if(RecChaine(test_1, &entier_recup, &char_recup) != 'S' || char_recup != '+')
        return 0;

    if(RecChaine(test_2, &entier_recup, &char_recup) != 'A')
        return 0;


    if(RecChaine(test_3, &entier_recup, &char_recup) != 'N' || entier_recup != 90)
        return 0;

    if(RecChaine(test_4, &entier_recup, &char_recup) != 'N' || entier_recup != 3)
        return 0;

    if(RecChaine(test_5, &entier_recup, &char_recup) != 'N' || entier_recup != 100)
        return 0;

    if(RecChaine(test_6, &entier_recup, &char_recup) != 'A')
        return 0;

    return 1;
}


/*========================= PILE ==============================*/

int test_ReverseLastTwo(Pile pile_1, Pile pile_2){

    if(ReverseLastTwo(&pile_1) != 0)
        return 0;

    if(ReverseLastTwo(&pile_2) != 1)
        return 0;

    return 1;
}


int test_SupprimeFin(Pile pile_1, Pile pile_2){

    if(SupprimeFin(&pile_1) != 0)
        return 0;

    if(SupprimeFin(&pile_2) != 1)
        return 0;

    return 1;
}


int test_ExtraitValeur(Pile pile_1, Pile pile_2){
    int a, b;

    if(ExtraitValeur(&a, &b, pile_1) != 0)
        return 0;

    if(ExtraitValeur(&a, &b, pile_2) != 2 || a != 1 || b != 2)
        return 0;

    return 1;
}


/*========================= TESTS ==============================*/

int test(){

    Pile pile_1 = NULL;
    Pile pile_2;

    pile_2 = AllouePile(1);
    pile_2->suivant = AllouePile(2);

    /*----------------- CalculL -----------------*/

    fprintf(stderr, "Cas de divisions par 0 et factorielle négative :\n\n");
    if(!test_Division()){
        printf("Err Divsion()\n");
        return 0;
    }
    if(!test_Facto()){
        printf("Err Facto()\n");
        return 0;
    }
    if(!test_Modulo()){
        printf("Err Modulo()\n");
        return 0;
    }
    if(!test_Exp()){
        printf("Err Exp()\n");
        return 0;
    }


    /*----------------- Parseur -----------------*/


    if(!test_RecChaine()){
        printf("Err RecChaine()\n");
        return 0;
    }


    /*----------------- Pile -----------------*/


    if(!test_ExtraitValeur(pile_1, pile_2)){
        printf("Err ExtraitValeur()\n\n");
        return 0;
    }

    if(!test_ReverseLastTwo(pile_1, pile_2)){
        printf("Err ReverseLastTwo()\n\n");
        return 0;
    }

    if(!test_SupprimeFin(pile_1, pile_2)){
        printf("Err SupprimeFin()\n\n");
        return 0;
    }

    /*Aucune erreur*/
    printf("\nTous les tests ont été effectués avec succès\n\n");

    return 1;
}


int main(void){

    /*On effectue les tests*/
    test();

    return 0;
}
