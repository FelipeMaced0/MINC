#include <stdio.h>
#include <string.h>
#include "functions.h"

int Partition(void *a, int p, int r, int size, int(*function)(void *, void *)){
    int j, i;
    char *array, *key;

    array = (char *)a;
    key = array+(r*size);
    i = p-1;

    for(j = p; j < r; j++){
        if(function(array+(j*size),key) < 0){
            i = i + 1;
            swap(array+(i*size), array+(j*size), size);
        }
    }

    swap(array+((i+1)*size), array+(r*size), size);

    return i + 1; 
}

void QuickSort(void *a, int p, int r, int size, int(*function)(void *, void *)){
    
    if(p < r){
        int q = Partition(a, p, r, size, function);
        QuickSort(a, p, q-1, size, function);
        QuickSort(a, q+1, r, size, function);
    }
}
