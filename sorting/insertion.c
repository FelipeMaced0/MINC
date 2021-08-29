#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void insertion(void *a, int l, int size){
    extern cmp cmp_function; //Global variable to compare functions
    char *key, *array;
    int j, i;

    array = (char *)a;
    key = (char *)malloc(size);

    for(j=1; j < l; j++){
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

int main(){
	int a[] = {7,8,6,1,2,4,3,5};

	set_cmp_function(&func_int);
	insertion(a, 8, sizeof(int));
	
	for(int i=0; i < 8; i++){
		printf(" %d", a[i]);
	}

}
