#include <stdio.h>
#include <stdlib.h>

void cetak1DArray(float * param, int size, int mode){
	if(mode == 0){ // forward mode
		for(int i = 0; i < size; i++){
			printf("%.2f\t", param[i]);
		}
	}else{
		//backward mode
		for(int i = size-1; i >= 0; i--){
			printf("%.2f\t", param[i]);
		}
		printf("Sukses\n");
	}
}

void cetak2DArray(char ** param, int rlen, int clen, int mode){
	if(mode == 0){ // forward mode
		for(int row = 0; row < rlen; row++){
			for(int col = 0; col < clen; col++){
				printf("%c\t", param[row][col]);
			}
			printf("\n");
		}
	}else{
		//backward mode
		for(int row = rlen-1; row >= 0; row--){
			for(int col = clen; col >= 0; col--){
				printf("%c\t", param[row][col]);
			}
			printf("\n");
		}
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
	cetak1DArray(arr, arrLen, 0);

	printf("\n\n== 2-D Array Character ==\n");
	for(int row = 0; row < rLen; row++){
		for(int col = 0; col < cLen; col++){
			printf("Masukan data untuk posisi array (%d, %d): ", row, col);
			scanf("%s", &tmp[row][col]);
		}
	}
	cetak2DArray(tmp, rLen, cLen, 0);

	int len1DArr, newRLen, newCLen;

	//========> RESIZING 1-D FLOAT ARRAY ==========//
	printf("\n\n== Resizing 1-D Float Array ==\n");
	printf("Masukan tambahan blok memory 1-D yang anda inginkan: "); scanf("%d", &len1DArr);
	arr = (float *) realloc(arr, (arrLen + len1DArr));

	for(int j = arrLen; j < (arrLen + len1DArr); j++){
		printf("Masukan data untuk posisi array (%d): ", j); scanf("%f", &arr[j]);
	}

	cetak1DArray(arr, (arrLen + len1DArr), 1);
	free(arr);
	//===============================================================================//


	//========> RESIZING 2-D CHAR ARRAY ==========//
	printf("\n\n== Resizing 2-D Char Array ==\n");
	printf("Masukan tambahan blok *row* memory anda inginkan: "); scanf("%d", &newRLen);
	printf("Masukan tambahan blok *column* memory anda inginkan: "); scanf("%d", &newCLen);

	*tmp = realloc(*tmp, (rLen + newRLen)); // reallocate new block for rows

	/*According to manual:

	The realloc() function changes the size of the memory block pointed to by ptr to size bytes. 
	The contents will be unchanged in the range from the start of the region up to the minimum of the old and new sizes. 
	If the new size is larger than the old size, the added memory will not be initialized. 
	If ptr is NULL, then the call is equivalent to malloc(size), for all values of size; if size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr). Unless ptr is NULL, it must have been returned by an earlier call to malloc(), calloc() or realloc(). If the area pointed to was moved, a free(ptr) is done. */

	for(int a = 0; a < (rLen + newRLen); a++){
		tmp[a] = (char *) malloc (sizeof(char) * (cLen + newCLen));
	}

	for(int row = 0; row < (rLen + newRLen); row++){
		for(int col = 0; col < (cLen + newCLen); col++){
			printf("Masukan data untuk posisi array (%d, %d): ", row, col);
			scanf("%s", &tmp[row][col]);
		}
	}

	cetak2DArray(tmp, (rLen + newRLen), (cLen + newCLen), 1);
	//===============================================================================//

	// free up memory
	for(int idx = 0; idx < (rLen + newRLen); idx++) free(tmp[idx]);
}