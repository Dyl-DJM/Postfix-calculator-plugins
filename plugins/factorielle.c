


int eval(int * args){
	return args[0]; 
}


int arity(void){
	return 1;
}


int check(int * args){

	if(args[0] <  0){
		return 1;
	}

	return 0;
}


int symbol(){
	return '!';
}