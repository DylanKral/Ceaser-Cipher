#include <iostream>
#include <string>
#include <sstream>
#include "CaesarCipher.h"

using namespace std;

const string CaesarCipher:: ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
CaesarCipher::CaesarCipher(const string& key)
{
  size_ = key.length();

  key_ = new int [size_];

  char current;

  for (int i = 0; i < size_; i++)
  {
    current = key.at(i);
    key_[i] = (int)current -'0';
  }
  
}

 CaesarCipher::~CaesarCipher()
 {
  delete [] key_;
  key_ = nullptr;
 }
//////////////////////////////////////////////////////////////
//////////////////////////Cipher//////////////////////////////
//////////////////////////////////////////////////////////////
 string CaesarCipher:: cipher(const string& s, const string &key)
{
  
  int keySize = key.length();
  int size = ALPHABET.length();
  string encrypt = s; 

  cout << endl;

  int size1 = encrypt.length();
  int k = 0;
  
  for (int i = 0; i < size1; i++)
  {
    int j = 0;
    if (k >= keySize)
    {
      k = 0;
    }

   while (encrypt[i] != ALPHABET[j])
   {
     if (encrypt[i] == ' ')
     {
       i++;
     }

     else
     j++;
   } 

    encrypt[i] = ALPHABET[(j+ key_[k])%size];

    k++;
    
  }

  return encrypt;
  
}
///////////////////////////////////////////////////////////
///////////////////////Decipher////////////////////////////
///////////////////////////////////////////////////////////
string CaesarCipher:: decipher(const string& s, const string& key)
{
  int keySize = key.length(); 
  int size = ALPHABET.length();
  string decrypt = s;

  int size1 = s.length();
  int k = 0;
  
  for (int i = 0; i < size1; i++)
  {
    int j = 0;
    if (k >= keySize)
    {
      k = 0;
    }

   while (s[i] != ALPHABET[j])
   {
     if (s[i] == ' ')
     {
       i++;
     }

     else
     j++;
   } 
   
   decrypt[i] = ALPHABET[(j+ (size- key_[k] ))%size];
   
    k++;
  }
  return decrypt;
}
