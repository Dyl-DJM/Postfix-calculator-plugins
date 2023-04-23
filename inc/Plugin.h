#ifndef __PLUGIN__
#define __PLUGIN__

    #define _DEFAULT_SOURCE

    #include <dirent.h>
    #include <string.h>
    #include <dlfcn.h>
    #include <stdlib.h>
    #include <stdio.h>
	

    typedef int (*eval)(int * args);
    typedef int (*check)(int * args);


    typedef struct {

        eval eval;
        check check;
        int arity;
        char symbol;

    }Plug_symbol;

    int apply_operation(char sym, int one, int two, int * arity, int * res);

    Plug_symbol * tab_of_plugs;

    void * load_plugins();


#endif
