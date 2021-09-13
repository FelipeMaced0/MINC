#include <stdio.h>
#include <string.h>
#include "functions.h"

extern cmp cmp_function;

static int Partition(void *arr, int p, int r, int size){
    int j, i;
    char *array, *key;

    array = (char *)arr;
    key = array+(r*size);
    i = p-1;

    for(j = p; j < r; j++){
        if(cmp_function(array+(j*size),key) < 0){
            i = i + 1;
            swap(array+(i*size), array+(j*size), size);
        }
    }

    swap(array+((i+1)*size), array+(r*size), size);

    return i + 1; 
}

static void QuickSort(void *arr, int p, int r, int size){
    
    if(p < r){
        int q = Partition(arr, p, r, size); // Does the ordering and find the pivot
        QuickSort(arr, p, q-1, size); // Devide until p == q-1
        QuickSort(arr, q+1, r, size); // Divede until q+1 == r
    }
}

void quick_sort(arr, int len, int size){
	QuickSort(arr, 0, len-1, int size);
}
