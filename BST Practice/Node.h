#pragma once

struct Node {
   Node() {};
   Node(int val) : m_value(val) {};
   Node(int val, Node* left, Node* right) : m_value(val), left(left), right(right) {};
   bool isLeaf() { return left == nullptr && right == nullptr; };
   int m_value;
   Node* left = nullptr;
   Node* right = nullptr;
};

