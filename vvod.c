#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <limits.h>

int add(int **mas, int *n, int *len, int a, int num){
		int num = 0, a = 0;
		if (*mas == 0){
			printf("Сначала выделите необходимую память (пункт 6) \n");
			return 1;
		}
		printf("Введите номер и значение, который вы хотите добавить\n");
               	if (num <=(*n)){
			if (*n == *len){
				printf("Недостаточно памяти\n");
				return 4;
			}
                     	(*n) += 1;
                       	num +=1;
                       	for(int i = (*n)-1; i>=num; i--){
                              	(*mas)[i] = (*mas)[i-1];
                       	}
                       	num -=1;
                       	(*mas)[num] = a;
               	}
		if (num>(*n)){
			if ((num > (*len))&&(*n == *len)){
				printf("Недостаточно памяти\n");
				return 5;
			}
			else{
				(*n) += 1;
				(*mas)[(*n)-1] = a;
			}
		}
		printf("\n");
                return 0;
}
