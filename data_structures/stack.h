#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
typedef struct Stack Stack;
typedef struct Node Node;

struct Node {
	Node *next;
	void *key;
	unsigned int size;
};

struct Stack {
	Node *head;
	unsigned int size;
	unsigned int max_size;
};

unsigned int set_max_size(Stack *stack);
unsigned int get_max_size(Stack *stack);
Stack *create();
Stack *search(void *key);
void push(void *key);
Stack *pop();
Stack *top();
bool is_empty();
bool is_full();

#endif
