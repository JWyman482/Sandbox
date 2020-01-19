// Author: John Wyman
// Date: 1/13/2020
// File: SearchTree.h
// Description: A practice binary search tree.

#pragma once
#include <iostream>

using namespace std;

template <class type>
class SearchTree {
public:
   SearchTree() {};
   SearchTree(const SearchTree& orig);
   ~SearchTree();
   bool insert(type* ptr);
   bool insert(const type& data);
   bool remove(const type& data);
   void makeEmpty();
   type* retrieve(const type& data) const;
   int height(const type& data) const;
   
   const SearchTree& operator=(const SearchTree& rhs);
   bool operator==(const SearchTree& rhs);
   bool operator!=(const SearchTree& rhs);
   friend ostream& operator<<(ostream& output, const SearchTree& tree);

private:
   struct Node {
      type* m_cPtr = nullptr;
      int count = 0;
      Node* left = nullptr;
      Node* right = nullptr;
   };
   Node* root = nullptr;
   bool compHelper(Node* root1, Node* root2);
   Node* copyHelper(Node* root);
   Node* removeHelper(Node* root, const type& data, bool& wasFound);
   void deleteHelper(Node* root);
   Node* findHelper(Node* root, const type& data) const;
   int heightHelper(Node* root) const;
   Node* printHelper(Node* root, ostream& output) const;
   Node* getNewNode(type* ptr) const;
   Node* findMax(Node* root) const;
   Node* findMin(Node* root);
};

#include "SearchTree.cpp"

