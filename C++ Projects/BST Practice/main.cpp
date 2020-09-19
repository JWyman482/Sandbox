#include <vector>
#include <iostream>
#include "SearchTree.h"

using namespace std;

int main() {

   vector<const int*> arr;

   SearchTree<int> T;
   T.insert(5);
   arr.push_back(T.retrieve(5));

   T.insert(3);
   T.insert(4);
   arr.push_back(T.retrieve(4));
   T.insert(2);
   T.insert(1);
   T.insert(6);
   T.insert(8);
   T.insert(7);
   arr.push_back(T.retrieve(1));
   arr.push_back(T.retrieve(7));

   /*
                 5
                / \
               3   6
              / \   \  
             2   4   8   
            /       /
           1       7
   */


   // Testing duplicates w/insert
   T.insert(1);
   arr.push_back(T.retrieve(1));
   
   // Testing remove: Leaf
   T.remove(7);
   arr.push_back(T.retrieve(7));
   /*
                 5
                / \
               3   6
              / \   \
             2   4   8
            /
           1
   */

   // Testing remove: Node w/Left Subtree
   T.remove(2);
   /*                n
                /         \
               5           n
             /   \       /   \   
            3     6     n     n
           / \   / \   / \   / \
          1   4 n   8 n   n n   n   
   */

   // Testing remove: Node w/Right Subtree
   T.remove(6);
   
   /*
              5
             / \
            3   8
           / \   
          1   4   
   */

   // Testing remove: Node w/Both Subtrees
   T.remove(3);
   
   /*
           5
          / \
         1   8
          \   
           4   
   */

   //T.max(); // 8
   //T.min(); // 1

   //T.clearTree();
   //T.~BST();

   for (auto i : arr) {
      if (i != nullptr) cout << *i << endl;
   }

   cout << T;
}

