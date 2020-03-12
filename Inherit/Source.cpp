#include <iostream>

using namespace std;

class Shape {
public:
   virtual Shape* create() = 0;
   char type;
};


class Triangle : public Shape {
   Triangle* create() {
      cout << "In Triangle.\n";
   };
};

class Square : public Shape {
   Square* create() {
   };
};


int main() {

}
