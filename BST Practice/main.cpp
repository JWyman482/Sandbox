#include <iostream>
#include "BST.h"

using namespace std;

int main() {

   BST T;
   T.add(5);
   T.search(5);
   T.add(3);
   T.add(4);
   T.search(4);
   T.add(2);
   T.add(1);
   T.add(6);
   T.add(8);
   T.add(7);
   T.search(1);
   T.search(7);

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
   T.search(1);
   
   // Testing remove: Leaf
   T.remove(7);
   T.search(7);
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
   T.search(2);
   /*
              5
             / \
            3   6
           / \   \
          1   4   8
   */

   // Testing remove: Node w/Right Subtree
   T.remove(6);
   T.search(6);
   /*
              5
             / \
            3   8
           / \   
          1   4   
   */

   // Testing remove: Node w/Both Subtrees
   T.remove(3);
   T.search(3);
   /*
           5
          / \
         1   8
          \   
           4   
   */

}
