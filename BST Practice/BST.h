#pragma once
#include "Node.h"

using namespace std;

class BST {
public:
   ~BST();
   bool add(int value);
   bool search(int value);
   bool remove(int value);
   bool clearTree();
   bool isEmpty();

private:
   Node* root = nullptr;
   void print(Node* root);
   Node* removeHelper(Node* root, int value);
   Node* deleteHelper(Node* root);
   Node* searchHelper(Node* root, int value, bool printTree = false);
   Node* getNewNode(int data);
   Node* maxRight(Node* root);
};
