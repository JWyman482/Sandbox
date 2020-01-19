#include <iostream>
#include "SearchTree.h"

using namespace std;

template <class type>
SearchTree<type>::SearchTree(const SearchTree& orig)
{
   copyHelper(orig.root);
}

template <class type>
SearchTree<type>::~SearchTree()
{
   deleteHelper(root);
   root = nullptr;
}

template <class type>
bool SearchTree<type>::insert(type* cPtr) 
{
   
   Node* spot = findHelper(root, *cPtr);

   // Case: Empty Tree
   if (spot == nullptr) {   
      root = getNewNode(cPtr);
      return true;
   }

   // Case: Duplicate c
   if (*spot->m_cPtr == *cPtr) {
      spot->count++;
      return true;
   }
   
   // Case: Insert new node on left/right subtree as appropriate
   *cPtr < *spot->m_cPtr ? spot->left = getNewNode(cPtr) : spot->right = getNewNode(cPtr);
   return true;
}

template<class type>
bool SearchTree<type>::insert(const type& data)
{
   type* temp = data;
   return insert(temp);
}

template <class type>
bool SearchTree<type>::remove(const type& c)
{

   bool wasFound = false;
   removeHelper(root, c, wasFound); 
   return wasFound;

}

template <class type>
void SearchTree<type>::makeEmpty()
{
   deleteHelper(root);
   root = nullptr;
}

template <class type>
type* SearchTree<type>::retrieve(const type& c) const 
{

   Node* tmp = findHelper(root, c);

   if (*tmp->m_cPtr == c) 
      return tmp->m_cPtr;
   else
      return nullptr;
   
}

template <class type>
int SearchTree<type>::height(const type& c) const
{
   Node* tgt = findHelper(root, c);
   if (*tgt->m_cPtr != c) return -1;

   return heightHelper(tgt);
}

template <class type>
const SearchTree<type>& SearchTree<type>::operator=(const SearchTree<type>& rhs)
{
   if (rhs.root == root) return *this;
   makeEmpty();
   copyHelper(rhs.root);
   return *this;
}

template <class type>
bool SearchTree<type>::operator==(const SearchTree& rhs)
{
   return compHelper(root, rhs.root);
}


template <class type>
bool SearchTree<type>::operator!=(const SearchTree& rhs)
{
   return !(*this==rhs);
}

template <class type>
ostream& operator<<(ostream& output, const SearchTree<type>& tree)
{
   tree.printHelper(tree.root, output);
   return output;
}


//*----------------------------- HELPER METHODS----------------------------------------------------

template <class type>
bool SearchTree<type>::compHelper(Node* root1, Node* root2) {

   // Case: Both traversals land on nullptrs at the same time.
   if (root1 == nullptr && root2 == nullptr) return true;
   
   // Case: One node has a comparable and one doesn't. 
   if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) return false;

   // Case: Each node has a value, but they don't match.
   if (*root1->m_cPtr != *root2->m_cPtr) return false;

   // Case: The comparables in both nodes are the same
   //     SubCase: Different counts
   if (root1->count != root2->count) return false;

   //     SubCase: Same counts
   return compHelper(root1->left, root2->left) && compHelper(root1->right, root2->right);

}

template <class type>
SearchTree<type>::Node* SearchTree<type>::copyHelper(Node* root)
{
   if (root == nullptr) return root;
   
   // To catch all the duplicates
   for (int i = 1; i <= root->count; i++)
      insert(root->m_cPtr);
   copyHelper(root->left);
   copyHelper(root->right);

   return root;
}

template <class type>
SearchTree<type>::Node* SearchTree<type>::removeHelper(Node* root, const type& c, bool& wasFound) {
   
   // Case: Empty Tree or c Not Found
   if (root == nullptr) return root;

   // Case: c is in left subtree
   if (c < *root->m_cPtr) root->left = removeHelper(root->left, c, wasFound);

   // Case: c is in right subtree
   else if (c > *root->m_cPtr) root->right = removeHelper(root->right, c, wasFound);

   // Case: Found the c in the tree
   else {
      // Subcase: If there are duplicates
      if (*root->m_cPtr == c && root->count > 1) {
         root->count--;
         wasFound = true;
         return root;
      }

      // Subcase: If the node is a leaf or only has L child
      if (root->left == nullptr) {
         Node* tmp = root->right;
      
         wasFound = true;
         delete root;
         return tmp;
      }

      // Subcase: If the node has a R child
      if (root->right == nullptr) {
         Node* tmp = root->left;

         wasFound = true;
         delete root;
         return tmp;
      }
      
      // If the node has two children, find largest on
      // the left subtree, copy its Comparable into the tgt Node, then
      // remove the original.
      Node* tmp = findMax(root->left);
      *root->m_cPtr = *tmp->m_cPtr;
      root->left = removeHelper(root->left, *tmp->m_cPtr, wasFound);
      wasFound = true;
      return root;
   }

   // cout << "Skipped to end on " << c << endl;
   return root;
}

template <class type>
void SearchTree<type>::deleteHelper(Node* root) 
{
   // Case: Empty Tree
   if (root != nullptr) {

      if (root->left != nullptr) deleteHelper(root->left);
      if (root->right != nullptr) deleteHelper(root->right);
      delete root;
      
      root = nullptr;
   }
}

template <class type>
SearchTree<type>::Node* SearchTree<type>::findHelper(Node* root, const type& c) const
{
   // Case: Empty Tree or c Found
   if (root == nullptr || *root->m_cPtr == c) return root;
   
   // Case: Left Subtree
   if (c < *root->m_cPtr && root->left != nullptr) return findHelper(root->left, c);
      
   // Case: Right Subtree
   if (c > *root->m_cPtr && root->right != nullptr) return findHelper(root->right, c);

   // Case: Not found/next subtree to examine is nullptr
   return root;
}

template <class type>
int SearchTree<type>::heightHelper(Node* root) const {
   if (root == nullptr) return 0;
   
   int leftHeight = heightHelper(root->left);
   int rightHeight = heightHelper(root->right);

   // Compare the two subranches for the taller subbranch, then
   // add 1 for the current branch before returning.
   if (leftHeight > rightHeight) return 1 + leftHeight;
   else return 1 + rightHeight;
}

template <class type>
SearchTree<type>::Node* SearchTree<type>::printHelper(Node* root, ostream& output) const {

   if (root == nullptr) return root;

   printHelper(root->left, output);
   output << *root->m_cPtr << " " << root->count << endl;
   printHelper(root->right, output);

   return root;

}

template <class type>
SearchTree<type>::Node* SearchTree<type>::getNewNode(type* cPtr) const {
   Node* newNode = new Node();
   newNode->m_cPtr = cPtr;
   newNode->count = 1;
   return newNode;
}

template <class type>
SearchTree<type>::Node* SearchTree<type>::findMax(Node* root) const {
   Node* curr = root;
   
   while (curr && curr->right != nullptr) {
      curr = curr->right;
   }

   // Curr will be the right-most node    
   // in the tree starting at root.
   return curr;
}

template<class type>
SearchTree<type>::Node* SearchTree<type>::findMin(Node* root) {
   Node<type>* curr = root;

   while (curr && curr->left != nullptr) {
      curr = curr->left;
   }

   // Curr will be the left-most node    
   // in the tree starting at root.
   return curr;
}



