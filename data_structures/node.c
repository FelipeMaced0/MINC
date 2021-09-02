#include <stdlib.h>

Node *create_node(void *key, unsigned int size){
        Node *node = (Node *)malloc(sizeof(Node));

        node->key =  key;
        node->size = size;

        return node;
}

void free_node(Node *node){
        Node *current_node;

        while(node->next != NULL){
                current_node = node;
                node = node->next;
                free(current_node);
        }

        free(node);
}

