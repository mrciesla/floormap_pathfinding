#include <iostream>
#include <cstdlib>
#include "queue.h"

template <typename T> //Constructor
Queue<T>::Queue()
{  top = bottom = NULL;
}

template <typename T> //Destructor
Queue<T>::~Queue() 
{  top = bottom = NULL;
} 

template <typename T> //isEmpty
bool Queue<T>::isEmpty() 
{  return (!top);
}

template <typename T> //isFull
bool Queue<T>::isFull() 
{  return false;
}

template <typename T> //enqueue(T) onto the bottom
void Queue<T>::enqueue(T elt)
{  nodeq<T> *newNode = new nodeq<T>;
   newNode->data = elt;
   newNode->next = NULL;
   if (top == NULL) top = newNode;
   else bottom->next = newNode;
   bottom = newNode;
}

template <typename T> //dequeue from the top
T Queue<T>::dequeue()
{  if(isEmpty()) throw emptyQueue();
   T result = top->data;
   nodeq<T> *victim = top;
   top = top->next;
   delete [] victim; //Changed this!
   return result;
}
