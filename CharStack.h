#ifndef CHAR_STACK_H
#define CHAR_STACK_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
  char letter;
  Node* next;
};
class CharStack {
  private:
    Node* top_;
  public:
    CharStack();  //create an empty stack
    ~CharStack(); //release all nodes

    bool isEmpty() const; //return true for an empty stack, false otherwise
    char& top() const;    //return the reference to the top character
    void push(char c);      //push a character to the top of the stack
    void pop();           //pop the top character from the stack
    void display() const; //for testing purpose
    string& message(string &message);
   
  };

#endif
