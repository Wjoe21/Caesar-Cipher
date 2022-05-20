#include <iostream>
#include <string>
#include "Cipher.h"
#include "CipherAdvanced.h"

using namespace std;

int main(){

  Cipher cipherObj;
 
  int key[3] = {1, 0, 2};
  cipherObj.setCipher(3, key);
  
  string cipherStr = cipherObj.encodeMessage("south");
  cout << cipherStr << endl;
  string decodeStr = cipherObj.decodeMessage("Igopp vkmt kv e ugvxQnhetg hrdtbtu oh xicqo zqx");
  cout << decodeStr << endl;
}
