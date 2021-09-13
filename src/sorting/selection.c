#include <stdio.h>
#include <string.h>

int func(void *a, void *b){
    int c, d;

    c = *(int *)a;
    d = *(int *)b;

    return c-d;
}

int funcS(void *a, void *b){
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

void selection(void *a, int l, int size, int(*function)(void *, void *)){
    int i,j,min;
    char *array;

    array = (char*)a;

    for(i=0; i < l-1; i++){
        min = i;
        for(j=i+1; j < l; j++){
            if(function(array+(j*size),array+(min*size)) < 0){
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
    char *b[] = {"e","d","c","b","a"};

    selection(b,5,sizeof(char *),&funcS);

    for(int i=0; i< 5; i++){
        printf("%s ",b[i]);
    }
}
