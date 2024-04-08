#include <stdio.h>
#include <stdlib.h>
#include "inputArr.h"
#include "input.h"
#include <limits.h>
#include "vvod.h"

int myf(int** mas,int* n, int* len){
		int flag1=0,flag2=0,b=0,cnt2=0,cnt1=0,cifr1=0,cifr2=0,kol2=0,a=0,c=0;
		int *mas2 = 0;
		int *mas3 = 0;
		if (*mas == 0){
			printf("Сначала выделите необходимую память (пункт 6) \n");
			return 1;
		}
		else{
			for(int i = 0; i < (*n); i++){
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
						kol2 += 2;
						if (j == 1){
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
						mas2[kol2-2] = (*mas)[i];
						mas2[kol2-1] = (*mas)[j];
					cnt2 = 0;
					cnt1 = 0;
					}
				cnt1 = cnt2 = 0;
				}
			}
			c = *n;
			mas3 = (int*)malloc(c*sizeof(int));
			for(int i = 0; i <(*n); i++){
				mas3[i] = (*mas)[i];
			}
			for(int i = 0; i < kol2; i++){
				printf("mas2[%d] = %d \n",i,*(mas2+i));
				for(int j = 0; j<(*n); j++){
					if (mas2[i] != (*mas)[j]){
						continue;
					}
					c -= 1;
					for(int k = j; k<((*n)-1); k++){
						mas3[k] = mas3[k+1];
					}
				}
			}
			if (c > 0){
				*n = c;
				mas3 = (int*)realloc(mas3,(*n)*sizeof(int));
				if (*mas == NULL){
					return 10;
				}
			}
			printf("\n");
			for(int i = 0; i < (*n); i++){
				printf("mas[%d] = %d\n",i,*(mas3+i));
			}
			printf("Памяти выделено: %d ячеек \nПамяти используется: %d ячекк\n",*len,*n);
			for(int i = 0; i<(*n); i++){
				*(*mas+i) = mas3[i];
			}
			free(mas3);
			mas3 = NULL;
			printf("\n");
			free(mas2);
			mas2 = NULL;
			return 0;
		}
}
