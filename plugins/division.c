
int eval(int * args){
	return args[0] / args[1]; 
}


int arity(void){
	return 2;
}


int check(int * args){

    if(args[1] == 0){
        return 1;
    }

    return 0;
}


int symbol(){
	return '/';
}