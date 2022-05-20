/*
  Implementation file for class Queue.
  Methods include:
  - Queue() (default constructor)
  - ~Queue() (programmer defined destructor)
  - void enqueue(int)
  - void dequeue(int &)
  - bool isEmpty() const
  - bool isFull() const
  - void clear()

  Purpose of this class is to run all the functions related to the Queue class. 

*/

#include <iostream>
#include <cstdlib>
#include "Queue.h" //This header file is used to access the Queue class

using namespace std;

/*
    Queue() is a default constructor that takes in no parameters and returns nothing. it sets the
    two pointers, front and rear, to nullptr
*/

Queue::Queue(){
  front = nullptr;
  rear = nullptr;
}

/*
    ~Queue() is a programmer-defined destructor that takes in no parameters and returns nothing. 
*/

Queue::~Queue(){
  QueueNode * garbage = front;
  while(garbage != nullptr){
    front = front->next;
    garbage->next = nullptr;
    delete garbage;
    garbage = front;
  }
}

/*
  enqueue() is a method that takes in an integer parameter and returns nothing. The function inserts 
  the value in parameter num at the rear of the queue
*/

void Queue::enqueue(int num){
  if(isEmpty()){
    front = new QueueNode(num);
    rear = front;
  }else{
    rear->next = new QueueNode(num);
    rear = rear->next;
  }
  count++;
}

/*
  dequeue() is a method that takes in an integer parameter as a reference and returns nothing. The function
  removes the value at the front of the queue, and copies it into the reference parameter num 
*/

void Queue::dequeue(int &num){
  QueueNode *temp = nullptr;
  if(isEmpty()){
    cout << "Queue is empty" << endl;
  }else{
    num = front->value;
    temp = front;
    front = front->next;
    delete temp;
  }
  count--;
}

/*
  isEmpty() is a constant method that takes in no parameters and returns a boolean. The function returns
  true if the queue is empty, found when front is pointing to nullptr, and false otherwise
*/

bool Queue::isEmpty() const{
  if(front == nullptr){
    return true;
  };
  return false;
}

/*
  isFull() is a constant method that takes in no parameters and returns a boolean. The function returns
  true if the queue is full, found when the count variable has reached 100, and false otherwise
*/

bool Queue::isFull() const{
  if(count == 100){
    return true;
  }
  return false;
}

/*
  clear() is a constant method that takes in no parameters and nothing. The function dequeues all the
  elements in the queue.
*/

void Queue::clear(){
  int val; //dummy variable needed for dequeue
  while(!isEmpty()){
    dequeue(val);
  }
}
