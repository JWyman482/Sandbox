#pragma once

struct Node {
  Node* next = nullptr;
  Node* prev = nullptr;
  int value;
  int index;
};
