 # Binary Search Tree in C++

## Introduction

A binary search tree is a data structure that stores data in a way that allows for efficient searching and retrieval. It is a binary tree in which each node has a value and two child nodes, one on the left and one on the right. The left child node always has a value that is less than the value of the parent node, and the right child node always has a value that is greater than the value of the parent node.

## Implementation

The following code is an implementation of a binary search tree in C++:

```c++
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *createBinaryTree(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    Node *root = NewNode(arr[0]);

    queue<Node *> Q;
    Q.push(root);

    int i = 1;
    while (!Q.empty() && i < size)
    {
        Node *current = Q.front();
        Q.pop();

        if (arr[i] != -1) // -1 : Represents null node
        {
            current->left = NewNode(arr[i]);
            Q.push(current->left);
        }
        i++;

        if (i >= size)
            break;

        if (arr[i] != -1)
        {
            current->right = NewNode(arr[i]);
            Q.push(current->right);
        }
        i++;
    }

    return root;
}

Node *InsertinBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
        return root;
    }

    else if (data <= root->data)
    {
        root->left = InsertinBST(root->left, data);
    }

    else if (

Generated by [BlackboxAI](https://www.useblackbox.ai)