#include <iostream>
#include <string>
#include <fstream>
#include "CaesarCipher.h"
#include "CharStack.h"
using namespace std;


int main() {
  string message; //This is to eventually store the message to be encrypted
  char ch;
  int i = 0;
  

  string key; //This is to collect the multi-digit key from the user
  cout << "What is your key (digits only)? ";
  cin >> key;
  cin.ignore();
  CaesarCipher multiple_bits(key);

  //This code block is to help test your cipher and decipher methods
  string testing_message = "FREE PIZZA IN THE CAFETERIA";
  cout << "Testing cipher: " << endl;
  cout << testing_message << endl;
  cout << "====>" << endl;
  string encrypted_message = multiple_bits.cipher(testing_message, key);
  cout <<  encrypted_message << endl << endl;
  cout << "Testing decipher: " << endl;
  cout << multiple_bits.decipher(encrypted_message, key) << endl << endl;
  
  
ifstream file("message.txt");
  CharStack undo, redo;
  string m;

  if (!file.is_open())
  {
    cout << "couldnt open file";
  }

  else if (file.is_open())
  {
    while (getline(file, m))
    {
      for (int i = 0; i <m.length(); i ++)
      {
        if (m[i] == '<')
        {
          if (undo.isEmpty() == true)
          {

          }

          else 
          {
            redo.push(undo.top());
            undo.pop();
          }
        }

        else if (m[i] == '>')
        {
          if (redo.isEmpty() == true)
          {

          }

          else 
          {
            undo.push(redo.top());
            redo.pop();
          }
        }

        else 
        {
          undo.push(m[i]);
          while (redo.isEmpty() != true)
          {
            redo.pop();
          }
        }
      }
    }
    
    undo.message(message);
    cout << endl;
  }

//Now, you are ready to apply the cipher and decipher to the message

  cout << "Applying cipher to the message from the undo stack:" << endl;
  cout << message << endl;
 cout << "Encrypted to:" << endl;
  encrypted_message = multiple_bits.cipher(message, key);
  cout << encrypted_message << endl;
  cout << "Decrypted back to:" << endl;
  cout << multiple_bits.decipher(encrypted_message, key) << endl;

  return 0;

}
