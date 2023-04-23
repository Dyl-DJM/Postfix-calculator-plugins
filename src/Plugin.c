#include "../inc/Plugin.h"


int apply_operation(char sym, int one, int two, int * arity, int * res){

    int i;
    int op[2];

    i = 0;

    op[0] = one;
    op[1] = two;

    fprintf(stderr, "Ancien resultat : %d\n(%d, %d)\n", *res, one, two);

    while(tab_of_plugs + i != NULL){

        if(tab_of_plugs[i].symbol == sym){

            if(tab_of_plugs[i].check(op) == 0){


                fprintf(stderr, "(%d, %d) = %d", one, two, tab_of_plugs[i].eval(op));

                *res = tab_of_plugs[i].eval(op);
                *arity = tab_of_plugs[i].arity;

                fprintf(stderr, "Caractère du plugin :%c\nArité : %d\nResultat : %d\n\n", tab_of_plugs[i].symbol, *arity, *res);

                return 1;

            }else{

                *arity = 0;
                return 0;
            }

        }

        i++;
    }

    return 0;
}



/*Permet le filtre reconnaissant les bibliothèque dynamique (Plugins)*/
int filter(const struct dirent * file){

    int file_name_length;

    file_name_length = strlen(file->d_name);


    if(file_name_length <= 3){
        return 0;
    }

    if(file->d_name[file_name_length - 3] == '.' && file->d_name[file_name_length - 2] == 's' && file->d_name[file_name_length - 1] == 'o'){
        return 1;
    }

    return 0;	/*Ne représente pas un plugin utilisable*/
}


/*Renvoie la structure contenant tous les plugins*/
char ** plugins_search(int * all_plugs){

    struct dirent ** plugins_list;
    int nb_plugs, name_length, i;

    char ** plugins_list_name = NULL;

    nb_plugs = scandir("./plugins", &plugins_list , filter, alphasort);

    plugins_list_name = (char **) malloc(sizeof(char *) * nb_plugs);

    for(i = 0; i < nb_plugs; i++){

        name_length = strlen(plugins_list[i]->d_name) + strlen("./plugins/");

        plugins_list_name[i] = (char *) malloc((sizeof(char) * name_length) + 1);

        plugins_list_name[i] = strcpy(plugins_list_name[i], "./plugins/");

        strcat(plugins_list_name[i], plugins_list[i]->d_name);
    }

    *all_plugs = nb_plugs;
    return plugins_list_name;

}

void * load_plugins(){
    int i, nb_plugs;

    nb_plugs = 0;

    void * dl;

    int (*arity)(void);
    int (*symbol)(void);
    int (*check)(int *);
    int (*eval)(int *);

    int op[2];

    op[0] = 2;
    op[1] = 2;
    Plug_symbol plugin;
    char ** plugins_list_name = NULL;

    plugins_list_name = plugins_search(&nb_plugs);

    tab_of_plugs = (Plug_symbol *) malloc(sizeof(Plug_symbol) * nb_plugs);

    fprintf(stderr, "...\nTotal plugins found : %d\n\nLet's start !!!\n\n", nb_plugs);

    for(i = 0; i < nb_plugs ; i++){

        dl = dlopen(plugins_list_name[i], RTLD_LAZY);

        arity = dlsym(dl, "arity");
        symbol = dlsym(dl, "symbol");

        check = dlsym(dl, "check");
        eval = dlsym(dl, "eval");

        tab_of_plugs[i].arity = arity();
        tab_of_plugs[i].symbol = symbol();

        tab_of_plugs[i].check = check;
        tab_of_plugs[i].eval = eval;

    }


    dlclose(dl);
}


