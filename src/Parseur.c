/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#include "../inc/Parseur.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/Pile.h"
#include "../inc/Plugin.h"



/*Affichage et gestion d'erreur causée par la chaine 'str'*/

void Erreur(char * str){

    int choix_erreur = 0;
    int retour_scanf;

    fprintf(stderr, "Erreur('%s')\n(1) Ignorer erreur\n(2) Effectuer calculs avant erreur\n", str);

    /*Tant que l'utilisateur ne choisi aucune des deux options
    one recommence à demander sa réponse*/
    while(choix_erreur != 1 && choix_erreur != 2){

        printf("=> ");
        retour_scanf = scanf(" %d", &choix_erreur);

        if(retour_scanf != 1){
            fprintf(stderr, "Problème rencontré, un entier etait demandé\n");
            exit(0);
        }

        /*On ignire simplement l'erreur*/
        if(choix_erreur == 1){
            fprintf(stderr, "Erreur('%s') : Ignorée\n", str);
        }

        /*On effectue pas les opération après*/
        if(choix_erreur == 2){

            fprintf(stderr, "Erreur('%s') : Annule suite\n", str);

            /*On skippe le reste de la chaine entrée*/
            while(str != NULL){
                str = strtok(NULL, " \r");
            }
        }
    }
}


/*Parse la chaîne 'str' selon si elle représente un opérateur, un opérande ou autre. Renvoie 'N' si 'str' est un nombre et affecte l'entier correspondant à *entier_converter
'S' et affecte à 'str_converter' le caractère du signe si c'est un opérande et 'A' sinon. */

char RecChaine(char * str, int * entier_converter, char * str_converter){

    char * endPtr;

    int recup_entier = strtol(str, &endPtr,10);

    /*Si la chaine a bien été convertie en entier*/
    if(endPtr != str){

        /*On transforme au mieux, si on a 34abc alors entier_converter = 34*/
        *entier_converter = recup_entier;
        return 'N';

    }else{

        /*La chaîne est un unique caractère*/
        if(strlen(str) == 1){

            switch(str[0]){
                case '+' : { *str_converter = '+'; return 'S';}
                case '-' : { *str_converter = '-'; return 'S';}
                case '*' : { *str_converter = '*'; return 'S';}
                case '/' : { *str_converter = '/'; return 'S';}
                case '%' : { *str_converter = '%'; return 'S';}
                case '^' : { *str_converter = '^'; return 'S';}
                case '!' : { *str_converter = '!'; return 'S';}
                default : return 'A';
            }
        }else{
            /*chaine non recevable*/
            return 'A';
        }
    }
    return 'A';
}


/*Fonction qui lit les chaînes reçues par l'utilisateur*/

int read(){

    int extraction, retour, recup_entier;

    /*Opérations*/
    int res, val_one, val_two;

    /*Caractères*/
    char signe, type_chaine;

    /*Chaînes*/
    char * nouv_chaine;
    char * sauv;
    char * ligne;

    Pile pile = NULL;

    load_plugins();


    retour = 1;

    res = 0;


    while(retour){

        /*On récupère la ligne & ajout historique*/
        ligne = readline("");
        add_history(ligne);

        /*On prépare une chaine de sauvegarde*/
        if(NULL == (sauv = (char *) malloc(strlen(ligne)*sizeof(char)))){
            fprintf(stderr, "Erreur Allocation\n");
            return -1;
        }

        strcpy(sauv, ligne);
        nouv_chaine = strtok(sauv, " \r");


        /*On parcourt la chaîne par morceaux séparés par des espaces*/
        while(nouv_chaine != NULL){

            /*On definit le type de la chaine donnée*/
            type_chaine = RecChaine(nouv_chaine, &recup_entier, &signe);

            /*===== OPÉRATEUR ======*/
            if(type_chaine == 'S'){

                extraction = ExtraitValeur(&val_one, &val_two, pile);

                if(signe == '!'){
                    val_one = val_two;
                }

                /*L'opération a été effectuée*/
                if(apply_operation(signe, val_one, val_two, &extraction, &res) == 1){

                    if(signe == '!' && extraction >=  1){

                        SupprimeFin(&pile);

                        /*Ajout resultat dans pile*/
                        if(AjoutePile(&pile, res) == 0){
                            fprintf(stderr, "Erreur d'ajout à la pile");
                            return -1;
                        }
                    }else{
                        if(extraction >= 2){    /*ON Y MET L'ARITÉ*/

                            SupprimeFin(&pile);
                            SupprimeFin(&pile);

                            /*Ajout resultat dans pile*/
                            if(AjoutePile(&pile, res) == 0){
                                fprintf(stderr, "Erreur d'ajout à la pile\n");
                                return -1;
                            }
                        }else{

                            /*Manque de valeurs dans pile*/
                            if(signe == '!'){
                                fprintf(stderr, "Erreur ! (%c) est un caractère unaire, manque de valeurs dans la pile\n", signe);
                            }else{
                                fprintf(stderr, "Erreur ! (%c) est un caractère binaire, manque de valeurs dans la pile\n", signe);
                            }
                        }
                    }
                }
            }

            /*===== OPÉRANDE ======*/
            if(type_chaine == 'N'){

                /*Ajout entier*/
                AjoutePile(&pile, recup_entier);
            }

            /*===== COMMANDE & AUTRE ======*/
            if(type_chaine == 'A'){
                if(strlen(nouv_chaine) == 1){
                    /*Gestion des commandes*/
                    switch(nouv_chaine[0]){

                        case 'q': {
                            retour = 0;
                            break;
                        }
                        case 'p': {
                            AffichePile(pile, 'l');
                            break;
                        }
                        case 'c': {
                            VidePile(&pile);
                            break;
                        }
                        case 'a': {
                            AffichePile(pile, 'a');
                            break;
                        }
                        case 'r': {
                            if(ReverseLastTwo(&pile) == 0){
                                fprintf(stderr, "Pas assez de valeurs dans la pile\n");
                            }
                            break;
                        }
                        default :{
                            Erreur(nouv_chaine);
                        }
                    }
                }else{
                     Erreur(nouv_chaine);
                }
            }
            /*On continue à parcourir les morceaux de la chaine
            entrée par l'utilisateur*/
            nouv_chaine = strtok(NULL, " \r");
        }
        /*On libère la mémoire de la ligne*/
        free(ligne);
    }

    clear_history();
    LiberePile(&pile);

    return 1;
}

