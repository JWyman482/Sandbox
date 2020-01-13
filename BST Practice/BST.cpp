#include <iostream>
#include "BST.h"

using namespace std;

BST::~BST() 
{
   deleteHelper(root);
}

bool BST::add(int value) 
{
   cout << "\n---------------\n";
   cout << "Adding " << value << endl;
   cout << "---------------\n";
   
   Node* spot = searchHelper(root, value);

   // Case: Empty Tree
   if (spot == nullptr) {   
      root = getNewNode(value);
      return true;
   }

   // Case: Duplicate value
   if (spot->m_value == value) return true;
   
   // Case: Insert new node on left/right subtree as appropriate
   value <= spot->m_value ? spot->left = getNewNode(value) : spot->right = getNewNode(value);
   return true;
}

bool BST::search(int value) 
{
   cout << endl;
   cout << "---------------\n";
   cout << "Searching for " << value << endl;
   cout << "---------------\n";

   if (searchHelper(root, value, true)->m_value != value) {
      cout << "---------------\n"; 
      cout << "Item not found.\n";
      cout << "---------------\n\n";
      return false;
   }
   cout << "---------------\n";
   cout << value << " found.\n"; 
   cout << "---------------\n";
   cout << endl;
   return true;
}

bool BST::remove(int value)
{
   cout << "\n---------------\n";
   cout << "Removing " << value << endl;
   cout << "---------------\n";

   if (removeHelper(root, value) == nullptr) return false;
   return true;

}

bool BST::clearTree()
{
   return false;
}

bool BST::isEmpty()
{
   return false;
}

// Performs postfix delete (L, R, Root)
Node* BST::deleteHelper(Node* root) 
{
   // Case: Empty Tree
   if (root == nullptr) return root;

   // Case: Left Subtree
   if (root->left != nullptr) {
      deleteHelper(root->left);
      root->left = nullptr;
   }
   
   // Case: Right Subtree
   if (root->right != nullptr) {
      deleteHelper(root->right);
      root->right = nullptr;
   }

   // Case: Leaf Node
   if (root->isLeaf()) {
      cout << "Deleting leaf w/val: " << root->m_value << endl;
      delete root;
      root = nullptr;
      return root;
   }

   return nullptr;
}

// Returns nullptr for empty trees, and a pointer to the 
// node where the value is, or the node above where the item should be.
Node* BST::searchHelper(Node* root, int value, bool printTree)
{
   // Case: Empty Tree or Value Found
   if (root == nullptr || root->m_value == value) return root;
 
   if (printTree) print(root);
   
   // Case: Left Subtree
   if (value <= root->m_value && root->left != nullptr) return searchHelper(root->left, value, printTree);
      
   // Case: Right Subtree
   if (value > root->m_value && root->right != nullptr) return searchHelper(root->right, value, printTree);

   // Case: Not found/next subtree to examine is nullptr
   return root;
}

Node* BST::getNewNode(int value) {
   Node* newNode = new Node();
   newNode->m_value = value;
   return newNode;
}

void BST::print(Node* root) {
   cout << "Current Node:\n";
   cout << "     " << root->m_value << "    " << endl;
   cout << "  /     \\\n";

   root->left == nullptr ?
      cout << " n" :
      cout << " " << root->left->m_value;

   root->right == nullptr ?
      cout << "       n" :
      cout << "       " << root->right->m_value;
   cout << endl;
}

Node* BST::removeHelper(Node* root, int value) {
   // Case: Empty Tree or Value Not Found
   if (root == nullptr) return root;

   // Case: Value is in left subtree
   if (value < root->m_value) root->left = removeHelper(root->left, value);

   // Case: Value is in right subtree
   else if (value > root->m_value) root->right = removeHelper(root->right, value);

   // Case: Found the value in the tree
   else {
      // If the node is a leaf or only has one child
      if (root->left == nullptr) {
         Node* tmp = root->right;
         delete root;
         return tmp;
      }
      else if (root->right == nullptr) {
         Node* tmp = root->left;
         delete root;
         return tmp;
      }
      
      // If the node has two children, find largest (maxRight) on
      // the left subtree, copy its value into the tgt Node, then
      // remove the original.
      Node* tmp = maxRight(root->left);
      root->m_value = tmp->m_value;
      root->left = removeHelper(root->left, tmp->m_value);

   }

   return root;
}

Node* BST::maxRight(Node* root) {
   Node* curr = root;
   
   while (curr && curr->right != nullptr) {
      curr = curr->right;
   }

   // Curr will be the right-most node    
   // in the tree starting at root.
   return curr;
}