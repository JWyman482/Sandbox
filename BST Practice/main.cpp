#include <iostream>
#include "BST.h"

using namespace std;

int main() {
   //Node* root = new Node(5);
   //Node* l1 = new Node(3);
   //root->left = l1;
   //l1->right = new Node(4);
   //l1->left = new Node(2);

   //cout << "root.isLeaf()? " << root->isLeaf() << endl;
   //cout << "l1.isLeaf()? " << l1->isLeaf() << endl << endl;

   BST T;
   T.add(5);
   T.add(3);
   T.add(4);
   T.add(2);

   //T.search(3);
   //T.search(4);
   //T.search(6);
   //T.search(2);
   //T.search(9);

   
   T.add(1);
   T.add(6);
   

   
   // Testing duplicates w/add
   T.add(1);
   T.search(1);
   

}
