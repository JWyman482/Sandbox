#pragma once

template<class type>
struct Node {
   Node() {};
   Node(type val) : m_value(val) {};
   Node(type val, Node* left, Node* right) : m_value(val), left(left), right(right) {};
   bool isLeaf() { return left == nullptr && right == nullptr; };
   type m_value;
   Node* left = nullptr;
   Node* right = nullptr;
};

