#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <limits.h>

int memory(int **mas, int *n, int *len){
	int op = 0;
	printf("Введите количество ячеек, под которые необходимо выделить память \n");
	op = getint(len,1,INT_MAX);
	if ((*len) < (*n)){
		*n = *len;
	}
	if (op == -1){
		return 1;
	}
	if (*mas == 0){
		*mas = (int*)malloc((*len)*sizeof(int));
		if (!(*mas)){
			return 1;
		}
		for(int i=0; i<(*len); i++){
			printf("mas[%d] = x\n",i);
		} //TODO
	}
	else{
		*mas = (int*)realloc(*mas,(*len)*sizeof(int));
		for(int i=0; i<(*n); i++){
			printf("mas[%d] = %d\n",i,(*mas)[i]);

		}
		for(int i=*n; i<(*len); i++){
			printf("mas[%d] = x \n",i);
		}
	}
	printf("Памяти выделено: %d ячеек \nПамяти используется: %d ячеек\n",*len,*n);
	printf("\n");
		return 0;
}

