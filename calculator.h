#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#define SUCCESS 10000
#define FAILURE 10001
#define TRUE    10002
#define FALSE 	10003



#include <stdio.h>
#include <stdlib.h>

struct node
{
	int date;
	struct node *next;
};
typedef struct node Node;


struct stack
{
	Node *top;
	int count;
};
typedef struct stack Stack;

int LinkStackInit(Stack **s);
int LinkStackEmpty(Stack *s);
int Push(Stack **s,int e);
int GetTop(Stack *s);
int Pop(Stack **s);
int LinkStackClear(Stack **s);
int LinkStackDestory(Stack **s);



