#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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

   while (!file.eof()) {
      string input;
      getline(file, input);
      output.push_back(input);
   }

   file.close();

   return output;
}

//-------------------------------------------------------------------
//This is test code for readFile.
//int main() {
//   vector<string> testVec = readFile("testfile.txt");
//
//   for (string str : testVec) {
//      cout << str << endl;
//   }
//}