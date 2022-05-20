#Caesar Cipher

A lightweight tools that implements the commmon Caesar Cipher for encryption and decryption for messages and files. The Caesar cipher (or Caesar code) is a monoalphabetic substitution cipher, where each letter is replaced by another letter located a little further in the alphabet (therefore shifted but always the same for given cipher message). The shift distance is chosen by a number called the offset, which can be right (A to B) or left (B to A).

## Features
- Allows for a multiple numeric key
- Can encrypt/decrypt an entire file and its contents

## Setup

### 1: Installing

#### Clone from GitHub
Use the command line program `git`:
```bash
$ git clone https://github.com/Wjoe21/Caesar-Cipher
```
or, you can click Download on this page and then unzip it.

### 2: Setting up settings
In the `Main.cpp` file is where the `Cipher` object will be created and its methods accessed.
The `Cipher` class gives the following functions:
  - `void setCipher(int, int[])` takes in an integer of the array length and then an array parameter
  - `int * getCipher()` returns a pointer of the current cipher key
  - `string encodeMessage(string)` returns the encoded message
  - `string decodeMessage(string)` returns the decoded message

##### Example code
```cpp
int main(){
  Cipher cipherObj;
 
  int key[3] = {1, 0, 2};
  cipherObj.setCipher(3, key);
  
  string cipherStr = cipherObj.encodeMessage("south");
  cout << cipherStr << endl;
  string decodeStr = cipherObj.decodeMessage("Igopp vkmt kv e ugvxQnhetg hrdtbtu oh xicqo zqx");
  cout << decodeStr << endl;
}
```

### 2.1: Running and compiling
To compile the code, run the following command line prompt:
```bash
$ g++ Main.cpp Cipher.cpp Queue.cpp
$ ./a.out
``` 
