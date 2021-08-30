#include <stdlib.h>
#include <string.h>
#include "functions.h"


void insertion(void *arr, int len, int size){
	/*
	 * A pointer to a compare
	 * function provided by
	 * the user.
	 *
	 * typedef int (*cmp)(void *, void *);
	 *
	 * */
	extern cmp cmp_function;
	char *key, *array;
	int j, i;

	array = (char *)arr;
	/*
	 * Alloc memory that is the same size
	 * as the data beeing manipulated.
	 *
	 * */
	key = (char *)malloc(size); 

	for(j=1; j < len; j++){
		memcpy(key, array + (j*size), size);
		i = j-1;
		while(i >= 0 && cmp_function(array + (i*size), key) > 0){
			swap(array + ((i+1)*size), array + (i*size), size);
			i = i-1;
		}
		memcpy(array + ((i+1)*size), key, size);

	}
	free(key);
}
