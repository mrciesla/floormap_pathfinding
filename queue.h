/************************************
Colleen Sain
EECS 281 - Project 1
Last Modified: 1/27/2012
************************************/

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

class emptyQueue
{ //Exception
};

template <typename T>
struct nodeq
{  T data;
   nodeq *next;
};

template <typename T>
class Queue
{
public:
   Queue();
   ~Queue();

   bool isEmpty();
   bool isFull();
   void enqueue(T); //Add T to the top of the list
   T dequeue();  // Remove the top item of the stack

private:
   nodeq<T> *top;
   nodeq<T> *bottom;
};


/*
Note: this is here *only* because the gnu compiler needs to see the
"templatized" versions of your methods.  This is the *only* instance
in which it is acceptable to #include a cpp file.
*/

#include "queue.cpp"

#endif /* __queue_H__ */
