#include <stdio.h>

char* my_print(char* msg){
	printf(msg);
	return msg;
}

int main(){
	
	my_print("Renato Oliveira");
	
	return 0;
}
