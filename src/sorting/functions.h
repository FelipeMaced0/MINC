#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
typedef int (*cmp)(void*, void*);
void set_cmp_function(cmp function);
int func_int(void *a, void *b);
int func_string(void *a, void *b);
void swap(void *v1, void *v2, int size);
#endif
