/*
  Implementation file for class Cipher.
  Methods include:
  - Cipher() (default constructor)
  - void setCipher(int arrLength, int arr[])
  - int* getCipher()
  - string encodeMessage(string encodeString)
  - string decodeMessage(string decodeString)

  Purpose of this class is to run all the functions related to the Cipher class. 

*/

#include <iostream>
#include <string> //This header file is used to access the string class and its functions
#include <cctype> //This header file is used to use islower() and isupper() in ASCII checking
#include "Cipher.h" //This header file is used to access the Cipher class
#include "Queue.h" //This header file is used to access the Queue class

using namespace std;

/*
    Cipher() is a default constructor that takes in no parameters and returns nothing. It takes a default
    key of 1, 2, 3, 4 and adds it to the queue for future ciphering/deciphering. The ptr private variable
    is set to the default key array
*/

Cipher::Cipher(){
  static int keyArr[4] = {1, 2, 3, 4};
  for(int i = 0; i < 4; i++){
    key.enqueue(keyArr[i]);
  }
  ptr = keyArr;
  arrLength = 4;
}

/*
    setCipher() is a method that takes in an integer length and an integer array and returns nothing. It first
    clears the queue of any existing keys/nodes and iterates through the array to add the new user defined
    key to the queue. The private ptr variable is set to the array sent in
*/

void Cipher::setCipher(int length, int arr[]){
  key.clear();
  for(int i = 0; i < length; i++){
    key.enqueue(arr[i]);
  };
  ptr = arr;
  arrLength = length;
}

/*
    getCipher() is a method that takes in no parameters and returns a pointer that points to an integer. 
    This returns the private ptr variable that had been holding the array key.
*/

int* Cipher::getCipher(){
  return ptr;
}

/*
    encodeMesage() is a method that takes in a string input and returns a string. It iterates through 
    the string to look at each character of the string individually, and then it checks to see if its 
    ASCII code is between the range for lower case (a-z) and upper case (A-Z). If it is, it will dequeue
    the node at the top of the queue, due to FIFO method, and will check to see if the character is upper case
    or lower case. If it is upper case, it will change the character with an ASCII character formula. 
    The same thing is repeated if the character is a lowercase character. The current dequeued node is
    sent to the back of the queue, and the process is repeated for each character of the entire string
    The new encoded string is returned in the end
*/

string Cipher::encodeMessage(string in){
  //cout << "ENCODE" << endl;
  for(int i = 0; i < (int)in.length(); i++){
    if(((in[i] >= 97 && in[i] <= 122) || (in[i] >= 65 && in[i] <= 90))){
      int decKey;
      key.dequeue(decKey);
      //cout << in[i] << " " << (int)in[i] << " " << in[i] + decKey << endl;
      if(isupper(in[i])){
	in[i] = (((in[i] - 'A') + decKey) % 26) + 'A'; /*
                                                    'A' is subtracted from the original upper case character
                                                    this puts it in the range 0-26. The current chosen decKey
                                                    is added to the character, and then %26 is taken from the result
                                                  */
      }else{
	in[i] = (((in[i] - 'a') + decKey) % 26) + 'a';
      };
      key.enqueue(decKey);
    };
  };
  return in;
}

/*
    decodeMessage() is a method that takes in a string input and returns a string. It first clears the key
    of any existing keys, and using the length of the current cipher key and the ptr, it adds the value of the
    key array back to the queue to make a brand new queue that starts from the beginning. It iterates through 
    the string to look at each character of the string individually, and then it checks to see if its 
    ASCII code is between the range for lower case (a-z) and upper case (A-Z). If it is, it will dequeue
    the node at the top of the queue, due to FIFO method, and will check to see if the character is upper case
    or lower case. If it is upper case, it will change the character with an ASCII character formula. 
    The same thing is repeated if the character is a lowercase character. The current dequeued node is
    sent to the back of the queue, and the process is repeated for each character of the entire string
    The new decoded string is returned in the end
*/

string Cipher::decodeMessage(string in){
  //cout << "DECODE" << endl;
  key.clear();
  for(int i = 0; i < arrLength; i++){
    key.enqueue(*(ptr + i));
  };
  for(int i = 0; i < (int)in.length(); i++){
    if(((in[i] >= 97 && in[i] <= 122) || (in[i] >= 65 && in[i] <= 90))){
      int decKey;
      key.dequeue(decKey);
      //cout << in[i] << " " << (int)in[i] << " " << in[i] - decKey << endl;
      if(isupper(in[i])){
	in[i] = (((in[i] - 'Z') - decKey) % 26) + 'Z';
                                                  /*
                                                    'Z' is subtracted from the original upper case character
                                                    this puts it in the range 0-26. The current chosen decKey
                                                    is added to the character, and then %26 is taken from the result
                                                  */
      }else{
	in[i] = (((in[i] - 'z') - decKey) % 26) + 'z';
      };
      key.enqueue(decKey);
    };
  };
  return in;
}
