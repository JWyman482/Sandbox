#include <iostream>
#include <string>
#include <vector>

using namespace std;


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


//-------------------------------------------------------------------
// Test to show function of parse.
//int main() {
//   
//   string input = "B, 456, M, 1913, 70, Liberty Nickel";
//   string delimiter = ", ";
//
//   vector<string> vec = parse(input, delimiter);
//
//   for (int i = 0; i < vec.size(); i++) {
//      cout << "vec[" << i << "]: " << vec[i] << endl;
//   }
//
//}