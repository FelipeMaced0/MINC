#ifndef __TREE_H__
#define __TREE_H__

#include "node.h"

typedef struct Tree Tree;
//typedef struct Node Node;


struct Node{
    Node *father;
    void *key;
    Node *left;
    Node *right;
    unsigned int type_size;
};

struct Tree{
    Node *root;
};

Tree* create_tree();
//Node* create_node(void *key, unsigned short type_size);
Node *min(Node *x);
Node *max(Node *x);
Node *search(Node *x, void *key);
Node *sucessor(Node *x);
Node *predecessor(Node *x);
void in_order_tree_walk(Node *n);
void set_cmp(int(*user_cmp)(void *a, void *b));
void insert(Tree *t, Node *n);

#endif
