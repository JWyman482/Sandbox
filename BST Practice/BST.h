// Author: John Wyman
// Date: 1/13/2020
// File: BST.h
// Description: A practice binary search tree.


#pragma once
#include "Node.h"

using namespace std;

class BST {
public:
   ~BST();
   bool add(int value);
   bool find(int value);
   bool remove(int value);
   bool clearTree();
   bool isEmpty();
   int max();
   int min();

private:
   Node* root = nullptr;
   void print(Node* root);
   Node* removeHelper(Node* root, int value);
   Node* deleteHelper(Node* root);
   Node* findHelper(Node* root, int value, bool printTree = false);
   Node* getNewNode(int data);
   Node* findMax(Node* root);
   Node* findMin(Node* root);
};
