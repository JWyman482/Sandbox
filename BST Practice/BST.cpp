#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include <iostream>
#include "BST.h"

using namespace std;

template<class type>
BST<type>::~BST() 
{
   
   root = deleteHelper(root);
}

template<class type>
bool BST<type>::add(type value) 
{
   cout << "\n---------------\n";
   cout << "Adding " << value << endl;
   cout << "---------------\n";
   
   Node<type>* spot = findHelper(root, value);

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

template<class type>
bool BST<type>::find(type value) 
{
   cout << endl;
   cout << "---------------\n";
   cout << "Searching for " << value << endl;
   cout << "---------------\n";

   if (findHelper(root, value, true)->m_value != value) {
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

template<class type>
bool BST<type>::remove(type value)
{
   cout << "\n---------------\n";
   cout << "Removing " << value << endl;
   cout << "---------------\n";

   if (removeHelper(root, value) == nullptr) return false;
   return true;

}

template<class type>
bool BST<type>::clearTree()
{
   root = deleteHelper(root);
   return true;
}

template<class type>
bool BST<type>::isEmpty()
{
   return root == nullptr;
}

template<class type>
type BST<type>::max()
{
   type tmp = findMax(root)->m_value;
   cout << "\n---------------\n";
   cout << "Max: " << tmp << endl;
   cout << "---------------\n";
   return tmp;
}

template<class type>
type BST<type>::min()
{
   type tmp = findMin(root)->m_value;
   cout << "\n---------------\n";
   cout << "Min: " << tmp << endl;
   cout << "---------------\n";
   return tmp;
}

// Performs postfix delete (L, R, Root)
template<class type>
Node<type>* BST<type>::deleteHelper(Node<type>* root) 
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
template<class type>
Node<type>* BST<type>::findHelper(Node<type>* root, type value, bool printTree)
{
   // Case: Empty Tree or Value Found
   if (root == nullptr || root->m_value == value) return root;
 
   if (printTree) print(root);
   
   // Case: Left Subtree
   if (value <= root->m_value && root->left != nullptr) return findHelper(root->left, value, printTree);
      
   // Case: Right Subtree
   if (value > root->m_value && root->right != nullptr) return findHelper(root->right, value, printTree);

   // Case: Not found/next subtree to examine is nullptr
   return root;
}

template<class type>
Node<type>* BST<type>::getNewNode(type value) {
   Node<type>* newNode = DBG_NEW Node<type>();
   newNode->m_value = value;
   return newNode;
}

template<class type>
void BST<type>::print(Node<type>* root) {
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

template<class type>
Node<type>* BST<type>::removeHelper(Node<type>* root, type value) {
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
         Node<type>* tmp = root->right;
         delete root;
         return tmp;
      }
      else if (root->right == nullptr) {
         Node<type>* tmp = root->left;
         delete root;
         return tmp;
      }
      
      // If the node has two children, find largest (maxRight) on
      // the left subtree, copy its value into the tgt Node, then
      // remove the original.
      Node<type>* tmp = findMax(root->left);
      root->m_value = tmp->m_value;
      root->left = removeHelper(root->left, tmp->m_value);

   }

   return root;
}

template<class type>
Node<type>* BST<type>::findMax(Node<type>* root) {
   Node<type>* curr = root;
   
   while (curr && curr->right != nullptr) {
      curr = curr->right;
   }

   // Curr will be the right-most node    
   // in the tree starting at root.
   return curr;
}

template<class type>
Node<type>* BST<type>::findMin(Node<type>* root) {
   Node<type>* curr = root;

   while (curr && curr->left != nullptr) {
      curr = curr->left;
   }

   // Curr will be the left-most node    
   // in the tree starting at root.
   return curr;
}