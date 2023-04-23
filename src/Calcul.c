/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#include"../inc/Calcul.h"
#include<stdio.h>
#include<math.h>


/*Cette fonction affecte à 'res' la division 'one'/'two'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/

int Division(int one, int two, int *res){
    if(two == 0){
        fprintf(stderr, "Erreur ! Divsion par 0\n");
        return two;
    }

    *res = one/two;
    return 1;
}


/*Cette fonction affecte à 'res' le modulo 'one'%'two'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/

int Modulo(int one, int two, int * res){
    if(two == 0){
        fprintf(stderr, "Erreur ! Divsion par 0\n");
        return two;
    }
    *res = one % two;
    return 1;
}


/*Cette fonction affecte à 'res' la factorielle de 'val'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/

int Facto(int val, int * res){
    int i;
    * res = 1;

    if(val < 0){
        fprintf(stderr, "Erreur ! Factorielle d'un nombre negatif\n");
        return 0;
    }


    if(val == 1){
        * res = 1;
        return 1;
    }

    for(i = 2; i < val + 1; i++){
        (*res) *= i;
    }
    return 1;
}


/*Cette fonction affecte à 'res' l'exponentiation 'one' ^ 'two'. Renvoie 1*/

int Exp(int one, int two, int * res){
    *res = pow(one, two);
    return 1;
}


/*Cette fonction affecte à 'res' la valeur du calcul représenté par le caractère 'signe'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/

int operateur(char signe, int first, int second, int * res){

    switch(signe){
        case '+': {
            *res = first + second;
            return 1;
        }
        case '-': {
            *res = first - second;
            return 1;
        }
        case '*': {
            *res = first * second;
            return 1;
        }
        case '/': {
            return Division(first, second, res);
        }
        case '!': {
            return Facto(first, res);
        }
        case '%': {
            return Modulo(first, second, res);
        }
        case '^': {
            return Exp(first, second, res);
        }
    }

    return -1;
}
