#pragma once
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

#include <iostream>
#include <string>

using namespace std;

struct BST2Object {
   BST2Object() {};
   BST2Object(string input) : m_data(input) {};
   string getData() const { return m_data; };
   bool setData(string input) { m_data = input; return true; };
   string m_data = "test";

   bool operator==(const BST2Object& rhs) const {
      return m_data == rhs.m_data;
   }
   bool operator!=(const BST2Object& rhs) const {
      return m_data != rhs.m_data;
   }
   bool operator>(const BST2Object& rhs) const {
      return m_data > rhs.m_data;
   }
   bool operator<(const BST2Object& rhs) const {
      return m_data < rhs.m_data;
   }

   friend ostream& operator<<(ostream& output, const BST2Object& obj) {
      output << obj.m_data;
      return output;
   }
};

struct BST2Node {
   BST2Object* m_Obj = nullptr;
   BST2Node* l = nullptr;
   BST2Node* r = nullptr;
   int count = 0;
};

class BST2 {
public:
   BST2() {};

   ~BST2();

   //-------------------------------------------------------------------
   // helper function for the destructor. Recursively destroys the nodes
   // in the tree.
   // PRECONDITIONS: none.
   // POSTCONDITIONS: empty tree with root == nullptr;
   void helperDestroy(BST2Node* root);

   //----------------------------------------------------------------
   // add will take control of the object, make the passed pointer
   // null and delete the object it pointed to after it makes and
   // inserts a copy.
   // PRECONDITIONS: the objPtr is pointing to a valid BST2Object.
   // POSTCONDITIONS: the BST2Object will be in the tree.
   bool add(BST2Object obj);

   //----------------------------------------------------------------
   // Enables recursion for add(). Creates and places a new node in
   // the appropriate spot.
   // PRECONDITIONS: none.
   // POSTCONDITIONS: A new node is added to the tree.
   BST2Node* helperAdd(BST2Object& tgt, BST2Node*& treePtr);

   //----------------------------------------------------------------
   // find will return a reference to the BST2Object referenced to
   // it. Control is retained in the tree.
   // PRECONDITION: none.
   // POSTCONDITION: none.
   const BST2Object& find(const BST2Object& obj) const;

   BST2Node* helperFind(const BST2Object& tgt, BST2Node* root) const;

   //----------------------------------------------------------------
   // take will return a pointer to the BST2Object referenced to
   // it, and remove the object from the tree. Control is passed to 
   // the receiver.
   // PRECONDITION: none.
   // POSTCONDITION: none.
   BST2Object* take(const BST2Object*& objPtr);

   //----------------------------------------------------------------
   // remove removes an object from the tree and deletes it.
   // PRECONDITIONS: none.
   // POSTCONDITIONS: none.
   bool remove(BST2Object*& objPtr);

   //----------------------------------------------------------------
   // makeEmpty deletes all the items in the tree and sets the root
   // to null.
   // PRECONDITIONS: none.
   // POSTCONDITIONS: none.
   bool makeEmpty();

   //----------------------------------------------------------------
   void display();

   int size() {
      return treeSize;
   }

private:
   
   int treeSize = 0;
   BST2Node* root = nullptr;

};