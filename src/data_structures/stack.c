#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "node.h"

void set_max_size(Stack *stack, unsigned int size){
	stack->size = size;
}

unsigned int get_size(Stack *stack){
	return stack->size;
}

bool is_empty(Stack *stack){
	return stack->size == 0;
}

bool is_full(Stack *stack){
	return stack->size == stack->max_size;
}

Stack *create_stack(){
	Stack *stack = (Stack *)malloc(sizeof(Stack));

	return stack;
}

void free_stack(Stack *stack){
	free_node(stack->head);
	free(stack);
}

int main(){
	int a = 1;
	Stack *m = create_stack();

	Node *n = create_node(&a, sizeof(int));	
	free_stack(m);
	return 0;
}
