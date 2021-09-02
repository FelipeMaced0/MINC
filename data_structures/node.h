#ifndef __NODE_H_N__
#define __NODE_H_N__
struct Node {
        Node *next;
        void *key;
        unsigned int size;
};

Node *create_node(void *key);
void free_node(Node *node);
#endif
