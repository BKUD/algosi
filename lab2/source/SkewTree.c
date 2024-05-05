//
// Created by 79835 on 05.05.2024.
//

#include "SkewTree.h"


Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

Node* insert(Node* node, int key) {
    // Если дерево пустое, создаем новый узел
    if (node == NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Иначе рекурсивно спускаемся вниз по дереву
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Возвращаем неизмененный указатель на узел
    return node;
}

Node* merge(Node* tree1, Node* tree2) {
    if (tree1 == NULL) return tree2;
    if (tree2 == NULL) return tree1;

    // Сцепляем два дерева так, чтобы они оставались скошенными
    if (tree1->key < tree2->key) {
        tree1->right = merge(tree1->right, tree2);
        return tree1;
    } else {
        tree2->right = merge(tree1, tree2->right);
        return tree2;
    }
}

// Функция расцепления дерева на два по заданному ключу
void split(Node* root, int key, Node** left, Node** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
    } else if (root->key < key) {
        split(root->right, key, &(root->right), right);
        *left = root;
    } else {
        split(root->left, key, left, &(root->left));
        *right = root;
    }
}
int main() {
    Node* root = NULL;
    int key;
    char operation;
    printf("Enter the operation (i - insert, s - search, q - exit):\n");
    while (scanf(" %c", &operation) != EOF) {
        switch (operation) {
            case 'i':
                printf("Enter the insertion key: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 's':
                printf("Enter the search key: ");
                scanf("%d", &key);
                Node* result = search(root, key);
                if (result != NULL) {
                    printf("Key %d not found.\n", key);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 'q':
                printf("Exit from program.\n");
                return 0;
            default:
                printf("Unknown operation.\n");
        }
        printf("Введите операцию (i - вставка, s - поиск, q - выход):\n");
    }

    return 0;
}

