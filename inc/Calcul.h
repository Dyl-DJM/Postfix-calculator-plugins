/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#ifndef __CALCUL__
#define __CALCUL__

    /*Cette fonction affecte à 'res' l'exponentiation 'one' ^ 'two'. Renvoie 1*/
    int Exp(int one, int two, int * res);

    /*Cette fonction affecte à 'res' la factorielle de 'val'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/
    int Facto(int val, int * res);

    /*Cette fonction affecte à 'res' la division 'one'/'two'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/
    int Division(int one, int two, int * res);

    /*Cette fonction affecte à 'res' le modulo 'one'%'two'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/
    int Modulo(int one, int two, int * res);

    /*Cette fonction affecte à 'res' la valeur du calcul représenté par le caractère 'signe'. Renvoie 1 si le calcul a bien été effectué et 0 sinon*/
    int operateur(char signe, int first, int second, int * res);

#endif
