#include <string.h>
#include "functions.h"

cmp cmp_function;

void set_cmp_function(cmp function){
	cmp_function = function;
}
/*
    if a > b: a-b > 0
    if a = b: a-b = 0
    if a < b: a-b < 0 

    prototype of a function
    int func(void *a, void *b){
        int c, d;
        
        c = *(int *)a;
        d = *(int *)b;

        return c-d;
    }
*/
int func_int(void *a, void *b){
    int c, d;

    c = *(int *)a;
    d = *(int *)b;

    return c-d;
}


/*
    char ** because void *a is the adress
    of the array of strings not the string itself. So
    we need get the string adress and then extract
    the string
*/
int func_string(void *a, void *b){
    char *c, *d;

    c = *(char **)a;
    d = *(char **)b;

    return strcmp(c,d);
}

void swap(void *v1, void *v2, int size){
    char buffer[size];

    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}
