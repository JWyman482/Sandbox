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
#include <fstream>
#include <vector>
#include <string>
#include <cctype>


using namespace std;

struct Node {
   Node() {
      params.push_back(id);
   };

   Node(vector<string> params) {
      if (params.size() == 0) this->params.push_back(id);
      else {
         this->params = params;
         id = params[0];
      }
   }

   virtual ~Node() {};
   virtual void display() {
      for (string str : params) {
         cout << str << " ";
      }
      cout << endl;
   }
   virtual Node* create(vector<string> params) = 0;
   
   string id = "C";
   vector<string> params;
};

struct DerivedNodeA : public Node {
   DerivedNodeA() { id = "A"; }
   DerivedNodeA(vector<string> params) : Node(params) { 
      if (params[0] == "C") params[0] = "A";
   };
   virtual ~DerivedNodeA() {}
   virtual Node* create(vector<string> params) {
      return DBG_NEW DerivedNodeA(params);
   }
};

struct DerivedNodeB: public Node {
   DerivedNodeB() { id = "B"; }
   DerivedNodeB(vector<string> params) : Node(params) { 
      if (params[0] == "C") params[0] = "B";
   };
   virtual ~DerivedNodeB() {}
   virtual Node* create(vector<string> params) {
      return DBG_NEW DerivedNodeB(params);
   }
};

struct Factory {
   Factory() {
      cout << "Enter the filename to read: ";
      string fileName;
      cin >> fileName;

      vector<string> file = readFile(fileName);

      for (string str : file) {
         DEBUG_MSG("str: " << str); 
         make(parse(str, ", "));
      }
      DEBUG_MSG(" ");

      display("A");
      cout << endl;
      display("B");
      cout << endl;
   }
   
   ~Factory() {
      for (int i = 0; i < designs.size(); i++) {
         delete designs[i];
      }
   }
   
   vector<Node*> designs = { DBG_NEW DerivedNodeA, DBG_NEW DerivedNodeB };

   bool make(vector<string> params) {
      Node* product = designs[hash(params[0])]->create(params);
      return insert(product);
   }
   
   void display(const string& type) const {
      cout << "Displaying storage for: " << type << endl;
      if (type == "A") {
         for (DerivedNodeA dna : dnaStore) {
            dna.display();
         }
      }
      if (type == "B") {
         for (DerivedNodeB dnb : dnbStore) {
            dnb.display();
         }
      }
      cout << "End of storage display: " << type << endl;
   }

   bool insert(Node*& object) {
      if (object->id == "A") {
         DerivedNodeA* dna = dynamic_cast<DerivedNodeA*>(object);
         dnaStore.push_back(*dna);
         delete object;
         object = nullptr;
         return true;
      }
      if (object->id == "B") {
         DerivedNodeB* dnb = dynamic_cast<DerivedNodeB*>(object);
         dnbStore.push_back(*dnb);
         delete object;
         object = nullptr;
         return true;
      }
      return false;
   }

   int hash(string str) { return str[0] - 'A'; }

   //-------------------------------------------------------------------
   //This takes in a file of text and parses each line into a string,
   //then puts those strings into a vector and returns it.
   //PRECONDITIONS: the file must be in the same location as the
   //executible. The file must have lines of data delimited by newlines.
   //POSTCONDITIONS: A vector of strings containing each line from the
   // file.
   vector<string> readFile(const string& filename) {
      vector<string> output;
      ifstream file;
      file.open(filename);

      if (!file) {
         cout << "Unable to open file " << filename << endl;
         exit(1);
      }

      // Checks to ensure the first char of each line is a letter.
      while (!file.eof()) {
         string input;
         getline(file, input);
         if (isalpha(input[0])) output.push_back(input);
      }

      file.close();

      return output;
   }

   //-------------------------------------------------------------------
   // parse parses a string by a given delimiter and carves the string
   // into items in a vector. If the delimiter is invalid or not found
   // the vector will contain the entire input string in position 0.
   // PRECONDITIONS: none.
   // POSTCONDITIONS: a vector of strings with each piece of the input
   // string.
   vector<string> parse(string input, string delimiter) {
      vector<string> vec;
      size_t pos = 0;

      while ((pos = input.find(delimiter)) != string::npos) {
         string token = input.substr(0, pos);
         vec.push_back(token);
         input.erase(0, pos + delimiter.length());
      }

      vec.push_back(input);

      return vec;
   }
   
   vector<DerivedNodeA> dnaStore;
   vector<DerivedNodeB> dnbStore;
};

//struct Storage {
//
//   vector<DerivedNodeA> dnaStore;
//   vector<DerivedNodeB> dnbStore;
//
//   bool insert(Node*& object) {
//      if (object->id == "A") {
//         DerivedNodeA* dna = dynamic_cast<DerivedNodeA*>(object);
//         dnaStore.push_back(*dna);
//         delete object;
//         object = nullptr;
//         return true;
//      }
//      if (object->id == "B") {
//         DerivedNodeB* dnb = dynamic_cast<DerivedNodeB*>(object);
//         dnbStore.push_back(*dnb);
//         delete object;
//         object = nullptr;
//         return true;
//      }
//      return false;
//   }
//
//   void display(const string& type) const {
//      cout << "Displaying storage for: " << type << endl;
//      if (type == "A") {
//         for (DerivedNodeA dna : dnaStore) {
//            dna.display();
//         }
//      }
//      if (type == "B") {
//         for (DerivedNodeB dnb : dnbStore) {
//            dnb.display();
//         }
//      }
//      cout << "End of storage display: " << type << endl;
//   }
//
//};

int main() {
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   Factory factory;



   return 0;

 }
