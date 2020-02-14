#ifndef _LLIST_
#define _LLIST_

#include "Node.h"

using namespace std;

class LList
{
public:
  LList();
  //LList(int values[]);
  ~LList();
  void add(const int &value);
  bool remove(const int &index);
  void display();
private:
  int n = 0;
  Node* head;
  Node* tail;
};

#endif //_LLIST_#pragma once
