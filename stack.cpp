#include <iostream>
#include <cstdlib>
#include "stack.h"

template <typename T> //Constructor
Stack<T>::Stack()
{  top = NULL;
}

template <typename T> //Destructor
Stack<T>::~Stack() 
{  top = NULL;
} 

template <typename T> //isEmpty
bool Stack<T>::isEmpty() 
{  return (!top);
}

template <typename T> //isFull
bool Stack<T>::isFull() 
{  return false;
}

template <typename T> //push(T)
void Stack<T>::push(T elt)
{  node<T> *newNode = new node<T>;
   newNode->data = elt;
   newNode->next = top;
   top = newNode;

}

template <typename T> //pop
T Stack<T>::pop()
{  if(isEmpty()) throw emptyStack();
   T result = top->data;
   node<T> *victim = top;
   top = top->next;
   delete [] victim;
   return result;
}
