#include <string>
#include <iostream>

using namespace std;

//-------------------------------------------------------------------
// This is an FNV hash. The hash starts with an offset dependent on a
// chosen size (32 bit here), performs an XOR on the last 8 bits of
// the hash (h), then multiplies by a prime that fits into the size.
// See more here: http://www.isthe.com/chongo/tech/comp/fnv/
// PRECONDITIONS: A set amount of buckets.
// POSTCONDITIONS: Returns an integer to be used in a hash table.

const int BUCKETS = 20000;
int hashFunc(const string& key)
{
  unsigned int h = 216136261u; // Without the u, this number is too large for an int
  for (int i = 0; i != key.size(); i++)
  {
    h += key[i];
    h *= 16777619;
  }
  return h % BUCKETS;
}

//-------------------------------------------------------------------
// The following is to test the hashfunc.
//int main() {
//   while (true) {
//      cout << "Enter a key to test here, 0 to exit: ";
//      string key;
//      getline(cin, key);
//
//      if (key == "0") return 0;
//
//      cout << hashFunc(key) << endl;
//   }
//}