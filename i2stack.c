#include "istack.h"
#include <stdlib.h>


enum errorT error;

numberT null_number = {.discr = NONE};


void push(Stack s, numberT val) 
{

  if (!s) 
  {
    error = NOT_INITIALIZED;
    return;
  }


  stackElemPtrT pt = (stackElemPtrT)malloc(sizeof(stackElemT));

  if (!pt) 
  {
    error = NO_MEMORY;
    return;
  }


  pt->val = val;


  pt->prev = NULL;
  pt->next = s->top;

  if (s->top)
  {
      s->top->prev = pt;
  }

  s->top = pt;
  error = OK;

  return;
}


numberT pop(Stack s) 
{

  if (!s) 
  {
    error = NOT_INITIALIZED;
    return null_number;
  }

  if (!s->top) 
  {
    error = EMPTY;
    return null_number;
  }


  numberT rc = s->top->val;


  stackElemPtrT pt = s->top;
  s->top = s->top->next;

  if (s->top)
  {
      s->top->prev = NULL;
  }
    

  free(pt);
  error = OK;

  return rc;
}


numberT top(Stack s) 
{

  if (!s) 
  {
    error = NOT_INITIALIZED;
    return null_number;
  }

  if (!s->top) 
  {
    error = EMPTY;
    return null_number;
  }

  error = OK;

  return s->top->val;
}


void swap(Stack s)
{

  if (!s) 
  {
    error = NOT_INITIALIZED;
    return;
  }

  if (!s->top) 
  {
    error = EMPTY;
    return;
  }


  if (s->top->next) 
  {
    stackElemPtrT pt = s->top;
    s->top = s->top->next;

    s->top->prev = pt->prev;
    pt->prev = s->top;
    pt->next = s->top->next;
    s->top->next = pt;
  }

  error = OK;
  return;
}

Stack allocStack() 
{
  Stack s = (Stack)malloc(sizeof(struct _stack));

  if (!s) 
  {
    error = NO_MEMORY;
    return (Stack)0;
  }


  s->top = (stackElemPtrT)0;
  error = OK;

  return s;
}


void freeStack(Stack s) 
{

  if (!s) 
  {
    error = NOT_INITIALIZED;
    return;
  }

  stackElemPtrT pt = s->top;
  while (pt) 
  {
    stackElemPtrT p2 = pt;
    pt = pt->next;
    free(p2);
  }

  free(s);
  error = OK;
  return;
}