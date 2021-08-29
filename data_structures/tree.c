#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

static int (*cmp)(void *node_a, void *node_b);

void set_cmp(int(*cmp_user)(void *node_a, void *node_b)){
	cmp = cmp_user;
}


void *extract_key(Node *n){
	return (n != NULL) ? n->key : NULL;
}

/*
 *Standard function for comparison
 *between integers.
 *
 * if i-j > 0  thus a  > b
 * if i-j < 0  thus a  < b
 * if i-j == 0 thus a == b
 *
 * Make sure,  when implemanting 
 * your own "equal" function, to 
 * account for "NULL" pointers.
 *
 *
 * */
int cmp_int(void *a, void *b){
	int i, j;


	i = (a != NULL) ? *(int *)a : 0;
	j = (b != NULL) ? *(int *)b : 0;

	return i-j;
}

/*
 * Allocate memory for a tree.
 *
 * */
Tree* create_tree(){
	Tree *t = (Tree *)malloc(sizeof(Tree));

	t->root = (Node *)0x0;//Initialazing root with NULL

	return t;
}


/*
 * Allocate memory for a node and 
 * return it to the caller.
 *
 * */
Node* create_node(void *key, unsigned short type_size){
	Node* n = (Node *)malloc(sizeof(Node));

	n->key = key;
	n->type_size = type_size;

	return n;
}


void insert(Tree *t, Node *n){
	Node *x;
	Node *y;

	x = t->root;
	y = NULL;

	while(x != NULL){
		y = x;

		if(cmp(extract_key(n), extract_key(y)) < 0){
			x = x->left;
		}else{
			x = x->right;
		}
	}

	n->father = y;

	if(y == NULL){
		t->root = n;
	}else if(cmp(extract_key(n), extract_key(y)) < 0){
		y->left = n;
	}else{
		y->right = n;
	}
}

Node *min(Node *x){

	while(x->left != NULL){
		x = x->left;
	}

	return x;
}

Node *max(Node *x){

	while(x->right != NULL){
		x = x->right;
	}

	return x;
}

Node *search(Node *x, void *key){
	/* resolve conflict with */
	while(x != NULL && cmp(key, extract_key(x)) != 0){

		if(cmp(key, extract_key(x)) < 0){
			x = x->left;
		}else{
			x = x->right;
		}
	}

	return x;
}

Node *sucessor(Node *x){
	Node *y;

	y = NULL;

	if(x->right != NULL){
		return min(x->right);
	}

	y = x->father;

	while((y != NULL) && (cmp(extract_key(x), extract_key(y->right)) == 0)){
		x = y;
		y = y->father;
	}

	return y;

}

Node *predecessor(Node *x){
	Node *y;

	y = NULL;

	if(x->left != NULL){
		return max(x->left);
	}

	y = x->father;

	while((y != NULL) && (cmp(extract_key(x),extract_key(y->left)) == 0)){
		x = y;
		y = y->father;	
	}


	return y;
}

void in_order_tree_walk(Node *n){
	if(n != NULL){
		in_order_tree_walk(n->left);
		printf(" %d",*(int*)n->key);
		in_order_tree_walk(n->right);
	}	
}

void free_node(Node *n){
	if(n != NULL){
		free_node(n->left);
		free_node(n->right);
		free(n);
	}
}

void free_tree(Tree *t){
	if(t != NULL){
		free_node(t->root);
		free(t);
	}
}

int main(){
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	set_cmp(&cmp_int);
	Tree *t = create_tree();

	Node *g = create_node(&a, sizeof(int));
	Node *h = create_node(&b, sizeof(int));
	Node *j = create_node(&c, sizeof(int));
	Node *k = create_node(&d, sizeof(int));

	insert(t, g);
	insert(t, j);
	insert(t, h);
	insert(t, k);

	Node *s = sucessor(j);
	printf("\n%d\n", *(int *)s->key);
	free_tree(t);
//	free(t);

	return 0;
}
