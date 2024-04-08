#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "input.h"

void outarray(int **mas, int *n, int* len);

int inputarr(int **mas, int *n, int *len){
		printf(" n len %d %d \n", *n, *len);
		if (*mas == NULL){
			printf("Сначала выделите необходимую память (пункт 6) \n");
			return 1;
		}
		if (*n > *len){
			printf("Недостаточно памяти \n");
			return 17;
		}
		for(int i=0; i<(*n); i++){
			printf("mas[%d] = ",i);
			getint(*mas+i,0,INT_MAX);
		}
		outarray(mas,n,len);
		return 0;
}

int add(int **mas, int *n, int *len, int a, int num){
		if (*mas == 0){
			printf("Сначала выделите необходимую память (пункт 6) \n");
			return 1;
		}
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
                return 0;
}

int remelem(int** mas, int* n, int num){
	if (*mas == NULL){
		printf("Сначала выделите необходимую память (пункт 6) \n");
		return 1;
	}
	if (num >=  (*n)){
		printf("Ошибка!");
		return 7;
	}
	for (int i = num; i<((*n)-1) ;i++){
		(*mas)[i] = (*mas)[i+1];
	}
	*n -= 1;
	return 0;
}

int myf(int** mas,int* n){
		int flag1=0,flag2=0,b=0,cnt2=0,cnt1=0,cifr1=0,cifr2=0,kol2=0,a=0,c=0;
		int *mas2 = NULL;
		if (*mas == 0){
			printf("Сначала выделите необходимую память (пункт 6) \n");
			return 1;
		}
		for(int i = 0; i < (*n); i++){
			if ((*mas)[i] == 0){
				continue;
			}
			for(int j = i + 1; j < (*n); j++){
				flag2 = 1;
				a = (*mas)[i];
				b = (*mas)[j];
				while (a > 0){
					flag1 = 0;
					cnt1+=1;
					cifr1 = a % 10;
					while (b > 0){
						cifr2 = b % 10;
						if (cifr2 == cifr1){
							cnt2+=1;
							flag1=1;
						}
						b /= 10;
					}
					if (flag1 == 0){
						flag2 = 0;
					}
					a /= 10;
					b = (*mas)[j];
				}
				if ((cnt2 >= cnt1)&&(flag2==1)){
					kol2+=1;
					if (mas2 == NULL){
						mas2=(int*)malloc(kol2*sizeof(int));
						printf("1\n");
						if (mas2 == NULL){
							return 8;
						}
					}
					else{
						mas2 = (int*)realloc(mas2,kol2 * sizeof(int));
						if (mas2 == NULL){
							return 9;
						}
					}
					mas2[kol2-1] = (*mas)[j];
					(*mas)[j] = 0;
					c = 1;
				}
			cnt1 = cnt2 = 0;
			}
		if (c == 1){
			kol2 += 1;
			mas2 = (int*)realloc(mas2,kol2*sizeof(int));
			if (mas2 == NULL){
				return 15;
			}
			mas2[kol2-1] = (*mas)[i];
			(*mas)[i] = 0;
			c = 0;
		}
		cnt1 = cnt2 = 0;
		}
		//printf("kol2 = %d\n",kol2);
		for(int i = 0; i < kol2; i++){
			printf("mas2[%d] = %d \n",i,*(mas2+i));
		}	
		for(int i = 0; i < (*n); i++){
			if ((*mas)[i] == 0){
				for(int j = i+1; j < (*n); j++){
					if ((*mas)[j] != 0){
						(*mas)[i] = (*mas)[j];
						(*mas)[j] = 0;
						break;
					}
					
				}
			}
		}
		printf("kol2 = %d \n",kol2);	
		*n -= kol2;
		//printf("n = %d",*n); 
		printf("n = %d \n",*n);
		free(mas2);
		mas2 = NULL;
		return 0;
}

void outarray(int** mas, int* n, int* len){
		if (*mas == NULL){
			printf("Сначала выделите необходимую память (пункт 6) \n");
		}
		else{
			for(int i = 0; i < (*n); i++){
				printf("mas[%d] = %d \n",i,*(*mas+i));
			}
			printf("Памяти выделено: %d ячеек \nПамяти используется: %d ячеек \n",*len,*n);
			printf("\n");
		}
}

int memory(int **mas, int *n, int *len){
	if ((*len) < (*n)){
		*n = *len;
	}
	if (*mas == NULL){
		*mas = (int*)malloc((*len)*sizeof(int));
		if (!(*mas)){
			return 1;
		}
	}
	else{
		*mas = (int*)realloc(*mas,(*len)*sizeof(int));
		for(int i=0; i<(*n); i++){
			printf("mas[%d] = %d\n",i,(*mas)[i]);
		}
	}
	for(int i = *n; i<(*len); i++){
		printf("mas[%d] = x \n",i);
	}
	printf("Памяти выделено: %d ячеек \nПамяти используется: %d ячеек\n",*len,*n);
	printf("\n");
		return 0;
}

