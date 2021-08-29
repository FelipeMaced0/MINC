#ifndef __STACK_H__
#define __STACK_H__

typedef struct Stack Stack;

struct Stack {
	Stack *head;
	Stack *tail;
	void *key;
}

int set_cmp(void *a, void *b);
Stack *create_stack();
Stack *search_stack(void *key);
void insert_stack(void *key);


#endif
