#include <iostream>
#include <string>
#include "Cipher.h"
#include "CipherAdvanced.h"

using namespace std;

int main(){

  //string fileName;
  //int chosenOption;
  CipherAdvanced cipher;

  /* cout << "Press 1 to encrypt or 2 to decrypt: ";
  cin >> chosenOption;
  
  switch(chosenOption){
  case 1:
    cout << "please enter file name to encrypt: ";
    cin >> fileName;
    cipher.encodeFile(fileName);
    break;
  case 2:
    cout << "please enter file name to decrypt: ";
    cin >> fileName;
    cipher.decodeFile(fileName);
    break;
  default:
    break;
    };*/

  cipher.unknownScramble("plaue");

  //Cipher cipherObj;
  //int * ptr = cipherObj.getCipher();
  //cout << *(ptr + 0) << " " << *(ptr + 1) << " " << *(ptr + 2) << " " << *(ptr + 3) << endl;*/
 
  //int key[3] = {1, 0, 2};
  //cipherObj.setCipher(3, key);
  //int * newPtr = cipherObj.getCipher();
  //cout << newPtr << endl;
  //string cipherStr = cipherObj.encodeMessage("south");
  //cout << cipherStr << endl;
  //string decodeStr = cipherObj.decodeMessage("Igopp vkmt kv e ugvxQnhetg hrdtbtu oh xicqo zqx");
  //cout << decodeStr << endl;
}
