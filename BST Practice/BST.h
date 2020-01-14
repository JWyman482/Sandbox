// Author: John Wyman
// Date: 1/13/2020
// File: BST.h
// Description: A practice binary search tree.


#pragma once
#include "Node.h"

using namespace std;

template<class type>
class BST {
public:
   ~BST();
   bool add(type value);
   bool find(type value);
   bool remove(type value);
   bool clearTree();
   bool isEmpty();
   type max();
   type min();

private:
   Node<type>* root = nullptr;
   void print(Node<type>* root);
   Node<type>* removeHelper(Node<type>* root, type value);
   Node<type>* deleteHelper(Node<type>* root);
   Node<type>* findHelper(Node<type>* root, type value, bool printTree = false);
   Node<type>* getNewNode(type data);
   Node<type>* findMax(Node<type>* root);
   Node<type>* findMin(Node<type>* root);
};

#include "BST.cpp"
