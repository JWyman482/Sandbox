#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
   Shape() {}
   Shape(vector<char> params) {
      type = params[0];
   }
   virtual Shape* create() = 0;
   virtual ~Shape() {};

   char type = 'X';
};



//class Triangle : public Shape {
//   Triangle* create() {
//      cout << "In Triangle.\n";
//      return new Triangle()
//   };
//};
//
class Square : public Shape {
public:
   Square() {
      //type = 'Z';
   };
   Square(vector<char> params) {
      type = params[1];
   };
   Square* create() {
      cout << "In Square.\n";
      return new Square;
   }
};




int main() {
   vector<char> vec = { 'a', 'b', 'c' };
   Shape* sptr = new Square();
   Shape* sptr2 = new Square(vec);

   cout << sptr->type << endl;
   cout << sptr2->type << endl;
}
