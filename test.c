#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "input.h"
#include "library.h"

int main(){
		int oper = 0, op = 0, n = 0, len = 0, stats = 0, a = 0, num = 0;
		int* mas = NULL;
		do{
		printf("Выберите действие и введите его номер\n 1. Инициализация массива \n 2. Вставка нового элемента по индексу\n 3. Удаление элемента по индексу \n 4. Обработка данных \n 5. Вывод текущего состояния массива \n 6. Выделение памяти \n 7. Выход из программы \n");
		op = getint(&oper, 0, INT_MAX);
		if (op == -1){
			free(mas);
			mas = NULL;
			return 0;
		}
		switch(oper){
			case 1:
				printf("Введите длину массива \nlen = ");
				op = getint(&n,0,INT_MAX);
				if (op == -1){
					return 3;
				}
				printf("n = %d \n",n);
				stats = inputarr(&mas,&n,&len);
				if (stats == 0){
					outarray(&mas,&n,&len);
				}
				if (stats == 1){
					n = 0;
				}
				break;
			case 2:
				printf("Введите номер элемента, который вы хотите добавить и его значение\n"); 
				op = getint(&num,0,INT_MAX);
				if (op == -1){
					return 3;
				}
				op = getint(&a,0,INT_MAX);
				if (op == -1){
					return 3;
				}
				stats = add(&mas,&n,&len,a,num);
				if (stats == 0){
					outarray(&mas,&n,&len);
				}
				break;
			case 3:
				printf("Введите индекс элемента, который вы хотите удалить\n");
				op = getint(&num,0,INT_MAX);
				if (op == -1){
					return 3;
				}
				stats = remelem(&mas,&n,num);
				if (stats == 0){
					outarray(&mas,&n,&len);
				}
				break;
			case 4:
				stats = myf(&mas,&n);
				if (stats == 0){
					outarray(&mas,&n,&len);
				}
				break;
			case 5:
				outarray(&mas,&n,&len);
				break;
			case 6:
				printf("Введите количество ячеек, под которые необходимо выделить память \n");
				op = getint(&len,1,INT_MAX);
				if (op == -1){
					return 3;
				}
				stats = memory(&mas,&n,&len);
				break;
			case 7:
				stats = 11;
				break;
			default:
				printf("Введите число от 1 до 7\n");
		}
		}while((stats==0) || (stats == 1));
		free(mas);
		mas = NULL;
		return 0;
		}
