//
// Created by BKUD on 03.04.2024.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* merge(Node* h1, Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    if (h1->key > h2->key) {
        h1->right = merge(h1->right, h2);
        return h1;
    } else {
        h2->right = merge(h2->right, h1);
        return h2;
    }
}

Node* insert(Node* head, int key) {
    Node* node = newNode(key);
    return merge(head, node);
}

Node* deleteMax(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = merge(head->left, head->right);
    free(head);
    return temp;
}

void search(Node* head, int key) {
    if (head == NULL) return;
    if (head->key == key) {
        printf("Key found\n");
        return;
    }
    search(head->left, key);
    search(head->right, key);
}

int main() {
    Node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 15);
    search(head, 20);
    head = deleteMax(head);
    search(head, 20);
    return 0;
}
