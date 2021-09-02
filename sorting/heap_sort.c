#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define TRUE 1

void heap_sort(void *arr, int len, unsigned short size){
	unsigned int father, son;
	char *array = (char *)arr;
	char *key = (char *)malloc(size);
	unsigned int i = len/2;
	extern cmp cmp_function;

	while(TRUE){
		if(i > 0){
			i--;
			memcpy(key, array+(i*size), size);
		}else{
			len--;
			if(len <= 0) return;
			memcpy(key, array+(len*size), size);
			memcpy(array+(len*size), arr, size);
		}

		father = i;
		son = (i*2)+1;
		while(son < len){
			if((son+1 < len) && (cmp_function(array+((son+1)*size), array+(son*size))>0)){
				son++;
			}

			if(cmp_function(array+(son*size), key) > 0){
				memcpy(array+(father*size), array+(son*size), size);
				father = son;
				son = (father*2)+1;
			}else{
				break;
			}
		}

		memcpy(array+(father*size), key, size);
	}

}
