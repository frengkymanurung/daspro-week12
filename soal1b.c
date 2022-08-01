#include <stdio.h>
#include <stdlib.h>

void main(){
	char ** tmp = (char **) malloc(sizeof(char *) * 3); // row
	for(int i = 0; i < 3; i++){
		tmp[i] = (char *) malloc(sizeof(char) * 3); // col
	}
	
	free(tmp);
}