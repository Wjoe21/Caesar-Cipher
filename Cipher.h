/*
  This is the header file for class Cipher. It has three private members, one of them being a pointer
  to the current cipher key. The Queue Key is a Queue instance that keeps track of the key in the 
  Queue. There are 4 public methods
*/

#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string> //This header file is used to access the string class
#include "Queue.h" //This header file is used to access the Queue class and create an object for it

using namespace std;

class Cipher{
private:
  Queue key;
  int * ptr;
  int arrLength = 0;
 public:
  Cipher();
  void setCipher(int, int[]);
  int* getCipher();
  string encodeMessage(string in);
  string decodeMessage(string in);
};

#endif
