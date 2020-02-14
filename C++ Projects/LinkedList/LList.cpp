#include "LList.h"
#include <iostream>

using namespace std;

LList::LList() 
{
  head = nullptr;
  tail = nullptr;
}

/*LList::LList(int values[]) 
{
  for (int i = 0; i < howMany; i++)
    this->add(0);
}*/

LList::~LList() 
{
  cout << "Deleting Index: ";
  for (int i = 0; i < n; i++) 
  {
    //delete will move from tail up.
    if (tail->prev == nullptr) 
    {
      cout << tail->index << "(" << tail->value << ")" << endl;
      delete tail->prev;
      tail = nullptr;
      break;
    }
    tail = tail->prev;
    cout << tail->next->index << "(" << tail->next->value << ") ";
    delete tail->next;
    tail->next = nullptr;
  }
  n = 0;
}

void LList::add(const int &value) 
{
  //Add nodes - assume to back
  //n++, update index
  n++;
  //Error case: list is empty
  if (tail == nullptr) 
  {
    Node* newNode = new Node;
    newNode->index = 0;
    newNode->value = value;
    head = newNode;
    tail = newNode;
  }
  else 
  {
    //create new node
    Node* newNode = new Node;
    newNode->index = tail->index + 1;
    newNode->value = value;
    //attach prev of new node to tail node
    newNode->prev = tail;
    //attach next of tail node to new node
    tail->next = newNode;
    //tail to new node
    tail = newNode;
  }
}

bool LList::remove(const int &index) 
{
  //
  return true;
}

void LList::display() 
{

  // No nodes case exits
  if (n == 0)
  {
    cout << "No Nodes\n\n";
    return;
  }

  while (true)
  {
    cout << "\nIndex = " << head->index << endl;
    cout << "Value = " << head->value << endl;
    if (head->next == nullptr) cout << "Next Node Index = Null" << endl << endl;
    else cout << "Next Node Index = " << head->next->index << endl << endl;
    if (head->prev == nullptr) cout << "Prev Node Index = Null" << endl << endl; 
    else cout << "Prev Node Index = " << head->prev->index << endl << endl;
    
    if (head == tail) break;
    head = head->next;
  }
  
  cout << "End of List - head node = Index: " << head->index << endl;
  
  while (head->prev != nullptr) head = head->prev;
  
  cout << "End of Reset - head node = Index: " << head->index << endl;
  
}
