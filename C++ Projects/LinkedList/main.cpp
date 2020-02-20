#include "LList.h"
#include <iostream>

using namespace std;

int main()
{
  LList* newList = new LList;
  newList->display();

  newList->add(1);
  newList->add(2);
  newList->add(4);
  newList->add(8);

  int answer = 0;
  while (answer != -1) {
      cout << "Enter number to add. -1 terminates.\n";
      cin >> answer;
      newList->add(answer);
      newList->display();
  }
  delete newList;
}