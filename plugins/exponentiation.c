#include <math.h>


int eval(int * args){
	return pow(args[0], args[1]); 
}


int arity(void){
	return 2;
}


int check(int * args){
	return 0;
}


int symbol(){
	return '-';
}