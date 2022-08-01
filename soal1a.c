#include <stdio.h>
#include <stdlib.h>

void main()
{
	float *arr = (float *)malloc(sizeof(float) * 5);

	free(arr);
}