//
// Created by 79835 on 05.05.2024.
//

#ifndef LAB1_SKEWTREE_H
#define LAB1_SKEWTREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* search(Node* root, int key);
Node* insert(Node* node, int key);
Node* merge(Node* tree1, Node* tree2);
void split(Node* root, int key, Node** left, Node** right);



#endif //LAB1_SKEWTREE_H
