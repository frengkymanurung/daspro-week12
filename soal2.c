#include <stdio.h>
#include <stdlib.h>

void main()
{
	float *arr = (float *)malloc(sizeof(float) * 5);
	char **tmp = (char **)malloc(sizeof(char *) * 3); // row
	for (int i = 0; i < 3; i++)
	{
		tmp[i] = (char *)malloc(sizeof(char) * 3); // col
	}

	printf("== 1-D Array Float ==\n");
	for (int j = 0; j < 5; j++)
	{
		printf("Masukan data untuk posisi array (%d): ", j);
		scanf("%f", &arr[j]);
	}

	printf("\n\n== 2-D Array Character ==\n");
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			printf("Masukan data untuk posisi array (%d, %d): ", row, col);
			scanf("%s", &tmp[row][col]);
		}
	}

	free(tmp);
	free(arr);
}
