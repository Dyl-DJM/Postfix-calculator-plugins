/* Auteur : Dylan DE JESUS
 * Date creation : 05-10-2021
 * Date modification : 20-10-2021*/

#ifndef __PILE__
#define __PILE__

    /*Type structuré représentant la Pile*/
    typedef struct valeur{
        int val;
        struct valeur *suivant;
    } Valeur, *Pile;


    /*Ajoute un noeud d'étiquette 'valeur' à la fin de la 'pile'. Renvoie 1 si l'ajout a bien été effectué et 0 sinon*/
    int AjoutePile(Pile *pile, int valeur);

    /*Affiche les valeurs contenus dans la 'pile'*/
    void AffichePile(Pile pile, char mode);

    /*Alloue un noeud dont l'étiquette est 'valeur'. Renvoie le noeud alloué de la pile*/
    Pile AllouePile(int valeur);

    /*Supprime le dernier élément de la 'pile'. Renvoie 1 si dernier élément supprimer et 0 si pile vide*/
    int SupprimeFin(Pile *pile);

    /*Vide la 'pile'. Renvoie 1 si la pile a bien été vidée et 0 sinon*/
    int VidePile(Pile *pile);

    /*Echange les deux dernières valeurs de la 'pile'. Renvoie 1 si l'échange à eu lieu et 0 sinon*/
    int ReverseLastTwo(Pile *pile);

    /*Extrait les deux dernières valeurs ajoutées dans la 'pile' et les affecte à 'val_one', 'val_two', la fonction peut n'affecter que la dernière valeur
    à 'val_two'si la 'pile' ne contient qu'une valeur, ou aucune valeur si pile vide. Renvoie le nombre de valeurs extraites [0-2]*/
    int ExtraitValeur(int *val_one, int *val_two, Pile pile);

    /*Libère la structure 'pile' en mémoire*/
    void LiberePile(Pile *pile);

#endif
