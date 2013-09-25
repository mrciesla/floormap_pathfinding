#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

class emptyStack 
{ //Exception
};

template <typename T> //Node could go in private section of Slist (???)
struct node
{  T data;
   node *next;
};

template <typename T>
class Stack
{
public:
   Stack();
   ~Stack();

   bool isEmpty();
   bool isFull();
   void push(T); //Add T to the top of the list
   T pop();  // Remove the top item of the stack

private:
   node<T> *top;
};


/*
Note: this is here *only* because the gnu compiler needs to see the
"templatized" versions of your methods.  This is the *only* instance
in which it is acceptable to #include a cpp file.
*/

#include "stack.cpp"

#endif /* __STACK_H__ */
