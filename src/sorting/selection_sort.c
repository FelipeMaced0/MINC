#include <stdio.h>
#include <string.h>
#include "functions.h"

void selection_sort(void *arr, int len, int size){
	extern cmp cmp_function;
	int i,j,min;
	char *array;

	array = (char*)arr;

	for(i=0; i < len-1; i++){
		min = i;
		for(j=i+1; j < len; j++){
			if(cmp_function(array+(j*size),array+(min*size)) < 0){
				min = j;
			}
		}

		if(min != i){
			swap(array+(i*size), array+(min*size), size);
		}
	}
}

int main(){
	int a[] = {5,4,3,2,1};
	char b[][10] = {"ed","d","c","b","a"};

	set_cmp_function(&func_string);
	selection_sort(b, 5 , 10);

	for(int i=0; i< 5; i++){
		printf("%s ", b[i]);
	}
}
