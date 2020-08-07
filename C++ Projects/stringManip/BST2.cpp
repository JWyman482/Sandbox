#include "BST2.h"

//*********************** DEBUGGING MACROS **************************
#define __DEBUG__
#ifdef __DEBUG__
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DBG_NEW new ( _CLIENT_BLOCK , __FILE__ , __LINE__ )
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DBG_NEW new
#define DEBUG_MSG(str) do { } while ( false )
#endif //__DEBUG__
//********************** END DEBUGGING MACROS ***********************

BST2::~BST2()
{   
   helperDestroy(root);
}

//-------------------------------------------------------------------
// helper function for the destructor. Recursively destroys the nodes
// in the tree.
// PRECONDITIONS: none.
// POSTCONDITIONS: empty tree with root == nullptr;
void BST2::helperDestroy(BST2Node* root)
{
   if (root == nullptr) return;

   helperDestroy(root->l);
   helperDestroy(root->r);

   delete root->m_Obj;
   root->m_Obj = nullptr;

   delete root;
   root = nullptr;
}

//----------------------------------------------------------------
// add will take control of the object, make the passed pointer
// null and delete the object it pointed to after it makes and
// inserts a copy.
// PRECONDITIONS: the objPtr is pointing to a valid BST2Object.
// POSTCONDITIONS: the BST2Object will be in the tree.
bool BST2::add(BST2Object obj)
{
   
   BST2Node* temp = helperAdd(obj, root);
   
   // If helperAdd found something it will increment that
   // node's count and return the pointer to it.
   if (temp) return false;
   treeSize++;
   return true;
}

//----------------------------------------------------------------
// Enables recursion for add(). Creates and places a new node in
// the appropriate spot.
// PRECONDITIONS: none.
// POSTCONDITIONS: A new node is added to the tree.
BST2Node* BST2::helperAdd(BST2Object& tgt, BST2Node*& treePtr) {
   // Found the spot.
   if (!treePtr) {
      // Make a new node
      BST2Node* tmp = DBG_NEW BST2Node;
      // Assign the target Object to it
      tmp->m_Obj = &tgt;
      // Connect it to the parent node
      treePtr = tmp;
     
      return nullptr;
   }

   // If a duplicate plus up the count.
   if (*treePtr->m_Obj == tgt) {
      treePtr->count++;
      return treePtr;
   }

   // If tgt < current value go left.
   if (tgt < *treePtr->m_Obj) return helperAdd(tgt, treePtr->l);
   
   // Else go right.
   return helperAdd(tgt, treePtr->r);
}

//----------------------------------------------------------------
// find will return a pointer to the BST2Object referenced to
// it. Control is retained in the tree.
// PRECONDITION: none.
// POSTCONDITION: none.
BST2Object& BST2::find(const BST2Object& tgt) const
{
   BST2Node* tmp = helperFind(obj, root);
   if (tmp )
   return;
}

BST2Node* BST2::helperFind(const BST2Object& tgt, BST2Node* root) const {
   // Not Found
   if (!root) return nullptr;
   
   // Found
   if (*root->m_Obj == tgt) {
      return root;
   }

   // If tgt < current value go left.
   if (tgt < *root->m_Obj) return helperFind(tgt, root->l);

   // Else go right.
   return helperFind(tgt, root->r);
}

BST2Object* BST2::take(const BST2Object*& objPtr)
{
   return nullptr;
}

bool BST2::remove(BST2Object*& objPtr)
{
   return false;
}

bool BST2::makeEmpty()
{
   return false;
}

void BST2::display()
{
}




