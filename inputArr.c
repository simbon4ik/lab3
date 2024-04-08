#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "input.h"

int inputarr(int **mas, int *n, int *len){
		if (*mas == NULL){
			printf("Сначала выделите необходимую память (пункт 6) \n");
			return 2;
		}
		for(int i=0; i<(*n); i++){
			printf("mas[%d] = ",i);
			getint(*mas+i,0,INT_MAX);
		}
		printf("\n");
		return 0;
}
