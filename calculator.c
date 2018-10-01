#include "linkstack.h"

int LinkStackInit(Stack **s)
{
	if(s == NULL)
	{
		return FAILURE;
	}

	(*s) = (Stack *)malloc(sizeof(Stack) * 1);

	if(*s == NULL)
	{
		return FAILURE;
	}

	(*s) -> top = NULL;
	(*s) -> count = 0;

	return SUCCESS;
}
int LinkStackEmpty(Stack *s)
{
	if(s == NULL)
	{
		return FAILURE;
	}
	
	return (s->top == NULL)? TRUE : FALSE;
}

int Push(Stack **s, int e)
{
	if(s == NULL)
	{
		return FAILURE;
	}

	if((*s) == NULL)
	{
		return FAILURE;
	}
	
	Node *p = (Node *)malloc(sizeof(Node));

	p -> date = e;
	p -> next = (*s) -> top;
	(*s) -> top = p;
	(*s) -> count++;

	return SUCCESS;

}

int GetTop(Stack *s)
{
	if(s == NULL || s->top == NULL)
	{
		return FAILURE;
	}

	return s->top->date;
}

int Pop(Stack **s)
{
	if(s == NULL || (*s) == NULL)
	{
		return FAILURE;
	}
	
	Node *p = (*s) -> top;
	int e = (*s) -> top -> date;
	(*s) -> top = (*s) -> top -> next;
	(*s) -> count--;
	free(p);

	return e;


}

int LinkStackClear(Stack **s)
{
	if(s == NULL || (*s) == NULL)
	{
		return FAILURE;
	}
	Node *temp = (*s) -> top;

	while(temp != NULL)
	{
		(*s) -> top = temp -> next;
		free(temp);
		temp = (*s) -> top;
		(*s)->count--;
	}

	return SUCCESS;

}

int LinkStackDestory(Stack **s)
{

	if(s == NULL || (*s) == NULL)
	{
		return FAILURE;
	}
	
	free(*s);

	(*s) = NULL;
	
	return SUCCESS;

}










 













