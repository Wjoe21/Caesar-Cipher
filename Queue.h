/*
  Wasif Johar
  CPSC 1071: 003
  C++// makes C bigger
  4/8/22

  This is the header file for class Queue. It has a struct QueueNode with a constructor that creates
  a new QueueNode. There are 3 pointers, next, front, and rear. The class Queue has one private variable
  that keeps track of the ongoing amount of current nodes in the queue, and 7 public methods
*/

#ifndef QUEUE_H
#define QUEUE_H

class Queue{
  struct QueueNode{
    int value;
    QueueNode *next;
    QueueNode(int val1, QueueNode *next1 = nullptr){
      value = val1;
      next = next1;
    }
  };
  //These track the front and rear of the queue
  QueueNode *front;
  QueueNode *rear;

private:
  int count = 0;
  
 public:
  Queue();
  ~Queue();
  void enqueue(int);
  void dequeue(int &);
  bool isEmpty() const;
  bool isFull() const;
  void clear();
};

#endif
