#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
    if a > b: a-b > 0
    if a = b: a-b = 0
    if a < b: a-b < 0 

    prototype of a function
    int func(void *a, void *b)
*/
int func(void *a, void *b){
    int c, d;

    c = *(int *)a;
    d = *(int *)b;

    return c-d;
}

int funcS(void *a, void *b){
    char *c, *d;

    c = (char *)a;
    d = (char *)b;

    return strcmp(c,d);
}

void swap(void *v1, void *v2, int size){
    char buffer[size];

    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}

void *insertion(void *array, int (*function)(void *, void *), int l, int size){
    int j, i;
    char *key, *temp, *m;
    
    m = (char *)array;
    key = (char *)malloc(size);

    for(j=1; j < l; j++){
    
        temp = (char *)(array + (j*size));
        memcpy(key, temp, size);
        i = j-1;
        while(i >= 0 && function((char *)(array + (i*size)), key) > 0){
            swap((char *)(array + ((i+1)*size)), (char *)(array + (i*size)), size);
            i = i-1;
        }
        memcpy((char *)(array + ((i+1)*size)),key,size);
        
    }
    free(key);
    return array;
}


void show(char *a, int l){
    int i;

    for(i=0; i<l; i++){
        
        printf("%s",(a+i));
    }
}

int main(){
    int b[] = {4,3,2,1};
    char *c[] = {"e","d","c","b","a"};

    int *p = b;

    insertion(b, &func, 4, sizeof(int));

    for(int i=0; i<4; i++){
        printf("%d ",b[i]);
    }


}