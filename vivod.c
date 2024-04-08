#include <stdio.h>
#include <stdlib.h>

void outarray(int** mas, int* n, int* len){
		if (mas == 0){
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
