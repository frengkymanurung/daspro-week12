#include <stdio.h>
#include <stdlib.h>

void cetak1DArray(float * param, int size){
	for(int i = 0; i < size; i++){
		printf("%.2f\t", param[i]);
	}
}

void cetak2DArray(char ** param, int rlen, int clen){
	for(int row = 0; row < rlen; row++){
		for(int col = 0; col < clen; col++){
			printf("%c\t", param[row][col]);
		}
		printf("\n");
	}
}

void main(){
	int arrLen = 5, rLen = 3, cLen = 3;
	float * arr = (float *) malloc (sizeof(float) * arrLen);
	char ** tmp = (char **) malloc(sizeof(char *) * rLen); // row
	for(int i = 0; i < rLen; i++){
		tmp[i] = (char *) malloc(sizeof(char) * cLen); // col
	}
	
	printf("== 1-D Array Float ==\n");
	for(int j = 0; j < arrLen; j++){
		printf("Masukan data untuk posisi array (%d): ", j); scanf("%f", &arr[j]);
	}
	cetak1DArray(arr, arrLen);
	
	printf("\n\n== 2-D Array Character ==\n");
	for(int row = 0; row < rLen; row++){
		for(int col = 0; col < cLen; col++){
			printf("Masukan data untuk posisi array (%d, %d): ", row, col);
			scanf("%s", &tmp[row][col]);
		}
	}
	cetak2DArray(tmp, rLen, cLen);

	free(tmp);
	free(arr);
}