//
// Created by BKUD on 04.04.2024.
//

#include <gtest/gtest.h>
#include <stdlib.h>
#include "SkewTree.h"

#include <gtest/gtest.h>
#include "SkewTree.h"

// Тесты для функции поиска
TEST(SearchTest, ReturnsNullForEmptyTree) {
    Node* root = NULL;
    ASSERT_EQ(NULL, search(root, 5));
}

TEST(SearchTest, ReturnsNodeForRootKey) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->key = 5;
    root->left = root->right = NULL;
    ASSERT_EQ(root, search(root, 5));
}

TEST(SearchTest, ReturnsNodeForNonRootKey) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->key = 5;
    root->left = root->right = NULL;
    insert(root, 3);
    Node* result = search(root, 3);
    ASSERT_TRUE(result != NULL);
    ASSERT_EQ(3, result->key);
}

// Тесты для функции вставки
TEST(InsertTest, CanInsertIntoEmptyTree) {
    Node* root = NULL;
    root = insert(root, 5);
    ASSERT_TRUE(root != NULL);
    ASSERT_EQ(5, root->key);
}

TEST(InsertTest, CanInsertIntoNonEmptyTree) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->key = 5;
    root->left = root->right = NULL;
    root = insert(root, 3);
    ASSERT_TRUE(root->left != NULL);
    ASSERT_EQ(3, root->left->key);
}

// Тесты для функции слияния
TEST(MergeTest, CanMergeTwoEmptyTrees) {
    Node* tree1 = NULL;
    Node* tree2 = NULL;
    Node* result = merge(tree1, tree2);
    ASSERT_EQ(NULL, result);
}

TEST(MergeTest, CanMergeEmptyAndNonEmptyTrees) {
    Node* tree1 = NULL;
    Node* tree2 = (Node*)malloc(sizeof(Node));
    tree2->key = 5;
    tree2->left = tree2->right = NULL;
    Node* result = merge(tree1, tree2);
    ASSERT_TRUE(result != NULL);
    ASSERT_EQ(5, result->key);
}

// Тесты для функции расщепления
TEST(SplitTest, CanSplitEmptyTree) {
    Node* root = NULL;
    Node* left;
    Node* right;
    split(root, 5, &left, &right);
    ASSERT_EQ(NULL, left);
    ASSERT_EQ(NULL, right);
}

TEST(SplitTest, CanSplitTreeWithOneNode) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->key = 5;
    root->left = root->right = NULL;
    Node* left;
    Node* right;
    split(root, 5, &left, &right);
    ASSERT_EQ(NULL, left);
    ASSERT_TRUE(right != NULL);
    ASSERT_EQ(5, right->key);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

