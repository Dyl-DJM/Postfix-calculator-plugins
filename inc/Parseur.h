/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#ifndef __PARSEUR__
#define __PARSEUR__
    #include"Calcul.h"


    /*Fonction qui lit les chaînes reçues par l'utilisateur*/

    int read(void);

    /*Parse la chaîne 'str' selon si elle représente un opérateur, un opérande ou autre. Renvoie 'N' si 'str' est un nombre et affecte l'entier correspondant à *entier_converter
    'S' et affecte à 'str_converter' le caractère du signe si c'est un opérande et 'A' sinon. */

    char RecChaine(char * str, int * entier_converter, char * str_converter);

#endif
