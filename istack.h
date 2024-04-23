#ifndef __ISTACK_H
#define __ISTACK_H

enum errorT { OK, NOT_INITIALIZED, EMPTY, NO_MEMORY };

enum types { INT, FLOAT, NONE };


extern enum errorT error;

typedef struct stackElem *stackElemPtrT;
typedef struct _stack 
{
  stackElemPtrT top;
} *Stack;

typedef struct numberT 
{
  enum types discr;
  union 
  {
    int as_int;
    float as_float;
  };
} numberT;

extern numberT null_number;

typedef struct stackElem 
{
  numberT val;
  stackElemPtrT next;
  stackElemPtrT prev;
} stackElemT;


void push(Stack, numberT);

numberT pop(Stack);

numberT top(Stack);

void swap(Stack);


Stack allocStack();

void freeStack(Stack);

#endif