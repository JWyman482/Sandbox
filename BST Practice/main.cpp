#include <iostream>
#include "BST.h"

using namespace std;

int main() {

   BST<int> T;
   T.add(5);
   T.find(5);
   T.add(3);
   T.add(4);
   T.find(4);
   T.add(2);
   T.add(1);
   T.add(6);
   T.add(8);
   T.add(7);
   T.find(1);
   T.find(7);

   /*
                 5
                / \
               3   6
              / \   \  
             2   4   8   
            /       /
           1       7
   */


   // Testing duplicates w/add
   T.add(1);
   T.find(1);
   
   // Testing remove: Leaf
   T.remove(7);
   T.find(7);
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
   T.find(2);
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
   T.find(6);
   /*
              5
             / \
            3   8
           / \   
          1   4   
   */

   // Testing remove: Node w/Both Subtrees
   T.remove(3);
   T.find(3);
   /*
           5
          / \
         1   8
          \   
           4   
   */

   T.max(); // 8
   T.min(); // 1

}
