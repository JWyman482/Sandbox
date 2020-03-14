#include <iostream>
#include <vector>
#include <string>

//*********************** DEBUGGING MACROS **************************
#define __DEBUG__
#ifdef __DEBUG__
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DBG_NEW new ( _CLIENT_BLOCK , __FILE__ , __LINE__ )
#define DEBUG_MSG(str) do { std::cout << "*****" << str << "*****" << std::endl; } while( false )
#else
#define DBG_NEW new
#define DEBUG_MSG(str) do { } while ( false )
#endif //__DEBUG__
//********************** END DEBUGGING MACROS ***********************


using namespace std;

class StoreObject {
public:
   //********************CONSTRUCTORS/DESTRUCTORS********************
   StoreObject() {
      DEBUG_MSG("Inside StoreObject()");
   }

   StoreObject(const vector<string>& params) {
      DEBUG_MSG("Inside StoreObject(params), making " << params[0]); 
      type = params[0];
      this->params = params;

   }

   virtual ~StoreObject() {};

   //****************************METHODS*****************************
   //----------------------------------------------------------------
   // create is a virtual method meant to be called in derived
   // classes to create themselves. Sort of allows the factory thing
   // to happen.
   virtual StoreObject* create(const vector<string>& params) = 0;

   virtual void display() {
      DEBUG_MSG("Inside StoreObject.display()");
      string allParams = params[0];
      for (int i = 1; i < params.size(); i++) {
         allParams = allParams + DELIMITER + params[i];
      }

      cout << allParams << endl;
   };

protected:
   const string DELIMITER = ", ";
   string type;
   vector<string> params;

};

class Coin : public StoreObject {
public: 
   //********************CONSTRUCTORS/DESTRUCTORS********************
   
   //----------------------------------------------------------------
   // An important note about this constructor: the classes derived
   // from StoreObject are meant to be initialized by the
   // create(params) method in StoreObject. As such, the data 
   // members are instantiated with strings from the params vector 
   // passed through the dummy derived StoreObject (customer, etc) 
   // found in the Store's objects array's create method to the new 
   // derived object's parameterized constructor. This then uses the
   // member initialization list to pass params up to the base class
   // to instantiate the base class's params vector. From there, the
   // derived class sets its data members to the base class's 
   // params.
   // Why all this? Because even that was less typing than creating
   // a new display class etc. in every derived class.
   // 
   Coin() : year(""), grade(0), typeCoin("") { 
      DEBUG_MSG("Inside Coin()");
   }

   Coin(vector<string> params) : StoreObject(params) {
      DEBUG_MSG("Inside Coin(params)");
   }

   virtual ~Coin() {}

   //****************************METHODS*****************************
   virtual StoreObject* create(const vector<string>& params) override {
      return DBG_NEW Coin(params);
   }

   //****************************GETTERS*****************************
   string getYear() const {
      return year;
   }

   int getGrade() const {
      return grade;
   }

   string getTypeCoin() const {
      return typeCoin;
   }

   //****************************SETTERS*****************************
   bool setYear(const string& input) {
      year = input;
      return true;
   }

   //----------------------------------------------------------------
   // There are two setters for grade, one for integer inputs and one
   // for string inputs to handle both cases. The string getter
   // converts the input to an integer to store it in grade.
   // PRECONDITION: A grade in string format or integer format.
   // POSTCONDITION: grade is set to hold the number in the input 
   // string or integer. 
   bool setGrade(const int& input) {
      grade = input;
      return true;
   }
   bool setGrade(const string& input) {
      try {
         grade = stoi(input);
      }
      catch (...) {
         cout << "Invalid grade (not an integer) passed to Coin: " << typeCoin << endl;
         return false;
      }
      return true;
   }

   bool setTypeCoin(const string& input) {
      typeCoin = input;
      return true;
   }

protected:
   // string StoreObject::type set by constructors as "M"
   string year = params[2];
   int grade = setGrade(params[3]);
   string typeCoin = params[4];
};

class Customer : public StoreObject {
public:
   //********************CONSTRUCTORS/DESTRUCTORS********************
   //----------------------------------------------------------------
   // An important note about this constructor: the classes derived
   // from StoreObject are meant to be initialized by the
   // create(params) method in StoreObject. As such, the data 
   // members are instantiated with strings from the params vector 
   // passed through the dummy derived StoreObject (customer, etc) 
   // found in the Store's objects array's create method to the new 
   // derived object's parameterized constructor. This then uses the
   // member initialization list to pass params up to the base class
   // to instantiate the base class's params vector. From there, the
   // derived class sets its data members to the base class's 
   // params.
   // Why all this? Because even that was less typing than creating
   // a new display class etc. in every derived class.
   //
   Customer() : cid(""), name("") { 
      DEBUG_MSG("Inside Customer()");
      type = "C";
   }

   Customer(vector<string> params) : StoreObject(params) {
      DEBUG_MSG("Inside Customer(params)");
   }

   virtual ~Customer() {}

   //****************************METHODS*****************************
   virtual StoreObject* create(const vector<string>& params) override {
      return DBG_NEW Customer(params);
   }

   //****************************GETTERS*****************************
   string getID() const {
      return cid;
   }

   string getName() const {
      return name;
   }

   //****************************SETTERS*****************************
   bool setName(const string& input) {
      name = input;
      return true;
   }

protected:
   string cid = params[0];
   string name = params[1];
   
   // This will store the transaction history.
   //vector<Transaction*> history;
};

class Store {
public:
   Store() {
      objects[2] = DBG_NEW Customer(); // 3 = C
      objects[12] = DBG_NEW Coin();   // 9 = M
   }

   ~Store() {
      
      //DEBUG_MSG("In ~Store(). BUCKETS: " << BUCKETS << " itemInv.size() : " << itemInventory.size() << " custList.size() : " << customerList.size());

      for (int i = 0; i < BUCKETS && i < itemInventory.size() && i < customerList.size(); i++) {
         //DEBUG_MSG("[#" << i << "]: ");
         
         if (i < BUCKETS)
         {
            //DEBUG_MSG("Deleting Object.");
            delete objects[i];
         }
         if (i < itemInventory.size()) {
            //DEBUG_MSG("Deleting item.");
            delete itemInventory[i];
         }
         if (i < customerList.size()) {
            //DEBUG_MSG("Deleting cust.");
            delete customerList[i];
         }
      }

   }

   //----------------------------------------------------------------
   // makeObject takes a string as an input. The string represents an
   // object, whether collectible item, customer, or transaction.
   // The function relies on parse(object, delimiter) & hash(params).
   // First, parse parses the string into individual parameters, then
   // hash turns that list of parameters into an int key. Finally
   // the key is used to call the create() method on the appropriate
   // dummy StoreObject in the objects array.
   // PRECONDITIONS: A string describing an object in a single line,
   // with individual parameters of that object seperated by 
   // DELIMITER.
   // POSTCONDITIONS: A StoreObject pointer that points to a new 
   // object of one of the StoreObject types - item, customer, or 
   // transaction.
   StoreObject* makeObject(string object) {
      // Parse the input string into individual parameters
      const vector<string> params = parse(object, DELIMITER);

      // Determine which object to create (hash(params)) and
      // then create it by calling the create method on the
      // dummy object in objects.
      return objects[hash(params)]->create(params);
   }

   bool storeObject(StoreObject& object) {

   }

private:
   const static int BUCKETS = 26;
   const string DELIMITER = ", ";
   StoreObject* objects[BUCKETS] = { nullptr };
   vector<Coin*> itemInventory = { nullptr };
   vector<Customer*> customerList = { nullptr };
   
   //----------------------------------------------------------------
   // The first hash function takes a char and converts it to int.
   // Very simple. The second takes a vector of string parameters,
   // and based on those parameters hashes them to an int. Calls the
   // route function to do so.
   // PRECONDITIONS: A char or a vector of strings representing 
   // parameters to be eventually passed to an object.
   // POSTCONDITIONS: An int key for locating an item in a hash table
   int hash(const char& ch) const { return ch - 'A';}
   int hash(const vector<string>& params) const {
      return route(params) - 'A';
   }
  
   //----------------------------------------------------------------
   // route identifies the type of object described by params and 
   // returns a character code depending on the item.
   // PRECONDITIONS: none
   // POSTCONDITIONS: none
   char route(const vector<string>& params) const {
      // Try to convert to an integer. 
      try { int test = stoi(params[0]); }
      
      // If it fails, return the first char.
      catch (...) { return params[0][0]; }

      // If it succeeds, the first string is an integer meaning it's 
      // a customer.
      return 'C';
   }

   //-------------------------------------------------------------------
   // parse parses a string by a given delimiter and carves the string
   // into items in a vector. If the delimiter is invalid or not found
   // the vector will contain the entire input string in position 0.
   // PRECONDITIONS: none.
   // POSTCONDITIONS: a vector of strings with each piece of the input
   // string.
   vector<string> parse(string input, const string& delimiter) const {
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
};



int main ()
{
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   Store test;
   
   vector<string> newItem = { "M", "1", "1774", "42", "John's Coin" };
   string newItem2 = "M, 1, 1982, 100, John's other coin";

   cout << newItem[4] << endl;
   

   //-----------Combining up and testing string entry-----------
   string tmpStr = newItem[0];

   for (int i = 1; i < newItem.size(); i++) {
      tmpStr = tmpStr + ", " + newItem[i];
   }
   //-----------------------------------------------------------


   StoreObject* tmp = test.makeObject(tmpStr);
   StoreObject* tmp2 = test.makeObject(newItem2);

   tmp->display();
   tmp2->display();

   //--------------Start of Customer Test-----------------------
   string newCust = "123, John Wyman";
   StoreObject* tmp3 = test.makeObject(newCust);
   StoreObject* tmp4 = test.makeObject("456, Bilbo");

   tmp3->display();
   tmp4->display();
   //test.storeObject(*tmp);

}