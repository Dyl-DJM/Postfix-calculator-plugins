/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#include"../inc/Pile.h"
#include<stdlib.h>
#include<stdio.h>


/*Alloue un noeud dont l'étiquette est 'valeur'. Renvoie le noeud alloué de la pile*/

Pile AllouePile(int valeur){

    Pile tmp;
    tmp = (Valeur *) malloc(sizeof(Valeur));

    if(tmp != NULL){
        tmp->val = valeur;
        tmp->suivant = NULL;
    }

    return tmp;
}


/*Libère la structure 'pile' en mémoire*/

void LiberePile(Pile *pile){

    Pile tmp = *pile;

    if((*pile) == NULL){
        return;
    }

    tmp = (*pile)->suivant;

    while((*pile)->suivant != NULL){
        free(*pile);
        *pile = tmp;
        tmp = (*pile)->suivant;
    }

    free((*pile)->suivant);
}


/*Affiche les valeurs contenus dans la 'pile' si mode est différent de 'l' (last) sinon affiche le dernier élement uniquement de la pile*/

void AffichePile(Pile pile, char mode){
    int i;

    for(i = 0; pile != NULL;i++){

        if(mode == 'l'){
            if(pile->suivant == NULL){
                printf("%d\n", pile->val);
            }
        }else{
            printf("%d\n", pile->val);
        }

        pile = pile->suivant;
    }
}


/*Ajoute un noeud d'étiquette 'valeur' à la fin de la 'pile'. Renvoie 1 si l'ajout a bien été effectué et 0 sinon*/

int AjoutePile(Pile *pile, int valeur){

    Pile tmp = AllouePile(valeur);

    if(tmp == NULL){
        return 0;
    }else{
        if((*pile) == NULL){
            (*pile) = tmp;
            return 1;
        }else{
            return AjoutePile(&(*pile)->suivant, valeur);
        }
    }

    return 1;
}


/*Supprime le dernier élément de la 'pile'. Renvoie 1 si dernier élément supprimer et 0 si pile vide*/

int SupprimeFin(Pile *pile){

    Pile tmp;
    tmp = *pile;

    if((*pile) == NULL){
        return 0;
    }
    if((*pile)->suivant == NULL){
        free(*pile);
        (*pile) = NULL;
        return 1;
    }

    /*Tant que l'on arrive pas à l'avant dernier*/
    while((*pile)->suivant->suivant != NULL){
        *pile = (*pile)->suivant;
    }

    /*Suppression*/
    free((*pile)->suivant);
    (*pile)->suivant = NULL;

    *pile = tmp;
    return 1;
}


/*Vide la 'pile'. Renvoie 1 si la pile a bien été vidée et 0 sinon*/

int VidePile(Pile *pile){

    /*On libere l'ancienne pile*/
    LiberePile(&(*pile));
    *pile = NULL;
    return 1;
}


/*Echange les deux dernières valeurs de la 'pile'. Renvoie 1 si l'échange à eu lieu et 0 sinon*/

int ReverseLastTwo(Pile *pile){

    Pile sauv = *pile;
    Pile tmp = *pile;

    /*Pas assez d'éléements pour echanger deux derniers*/
    if((*pile) == NULL || (*pile)->suivant == NULL){
        return 0;
    }

    /*Plus de 2 elements : On va jusqu'à l'avant-avant dernier*/
    if((*pile)->suivant->suivant != NULL){

        while((((*pile)->suivant)->suivant)->suivant != NULL){
            *pile = (*pile)->suivant;
        }
    }else{
        /*2 elements : echange directement*/
        (*pile) = (*pile)->suivant;
        tmp->suivant = NULL;
        ((*pile)->suivant) = tmp;

        return 1;
    }

    /*Échange des deux valeurs (cas + de 2 elements)*/
    sauv = (*pile)->suivant;
    (*pile)->suivant = ((*pile)->suivant)->suivant;
    sauv->suivant = NULL;

    ((*pile)->suivant)->suivant = sauv;

    *pile = tmp;

    return 1;
}


/*Extrait les deux dernières valeurs ajoutées dans la 'pile' et les affecte à 'val_one', 'val_two', la fonction peut n'affecter que la dernière valeur
    à 'val_two'si la 'pile' ne contient qu'une valeur, ou aucune valeur si pile vide. Renvoie le nombre de valeurs extraites [0-2]*/

int ExtraitValeur(int *val_one, int *val_two, Pile pile){

    if((pile) == NULL){
        return 0;
    }

    if(pile->suivant == NULL){
        *val_two = pile->val;
        return 1;
    }

    while(pile->suivant->suivant != NULL){
        pile = pile->suivant;
    }

    *val_one = pile->val;
    *val_two = (pile->suivant)->val;

    return 2;
}


