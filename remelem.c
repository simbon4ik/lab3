#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <limits.h>

int remelem(int** mas, int* n, int* len){
	int op = 0, num = 0;
	if (*mas == 0){
		printf("Сначала выделите необходимую память (пункт 6) \n");
		return 1;
	}
	else{
		printf("Введите индекс элемента, который вы хотите удалить\n");
		op = getint(&num, 0, INT_MAX);
		if (op == -1){
			return 6;
		}
		if (num >  (*n)){
			printf("Ошибка!");
			return 7;
		}
			for (int i = num; i<((*n)-1) ;i++){
				(*mas)[i] = (*mas)[i+1];
			}
			*n -= 1;
			for(int j = 0;j < (*n);j++){
				printf("mas[%d] = %d\n",j,(*mas)[j]);
			}	
			printf("\n");
		printf("Памяти выделено: %d ячеек \nПамяти используется: %d ячеек\n",*len,*n);
		printf("\n");
		return 0;
	}
}
