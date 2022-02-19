#include <iostream>
#include <fstream>
#include "CharStack.h"
#include <string>


using namespace std;

CharStack::CharStack()  //create an empty stack
{
  top_ = nullptr;
}

CharStack::~CharStack() //release all nodes
{

}

bool CharStack:: isEmpty() const//return true for an empty stack, false otherwise
{
  if (top_ == nullptr)
  {
   return true; 
  }
  
  else 
  return false;
} 

char& CharStack:: top() const    //return the reference to the top character
{
  return top_->letter;
}

void CharStack:: push(char c)      //push a character to the top of the stack
{
  Node *ptr = new Node;
  ptr->letter = c;
  ptr->next = nullptr;


  if (top_ == nullptr)
  {
    top_ = ptr;

    top_->next = nullptr;
  }

  else 
  {
    ptr->next = top_;

    top_ = ptr;
  }
}

void CharStack:: pop() //pop the top character from the stack
{
  Node * ptr;

  if (top_ == nullptr)
  {
    exit(1);
  }

  else 
  {
    ptr= top_;

    top_ = top_->next;

    ptr->next = nullptr;

    delete [] ptr;
  }
}          

void CharStack:: display() const//for testing purpose
 {
   Node *ptr = top_;

   while (ptr != nullptr)
   {
     cout << ptr->letter;
     ptr = ptr->next;
   }

   cout << endl;
 }

 string& CharStack:: message(string& message)
 {
   Node *ptr = top_;
  
   while (ptr != nullptr)
   {
     message += ptr->letter;
     ptr = ptr->next;
   }

   int n = message.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++)
    {
        swap(message[i], message[n - i - 1]);
    }

   return message;
 }

 
