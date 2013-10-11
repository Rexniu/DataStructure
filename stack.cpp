#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,* PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,* PSTACK; //PSTACK等价于struct STACK *

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK,int *);
bool empty(PSTACK);
void clear(PSTACK);

int main(void)
{
	STACK S; //STACK 等价于struct Stack
	int val;

	init(&S); //造出一个空栈
	push(&S,1);//压栈
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	traverse(&S);

	clear(&S);
	traverse(&S);
/*	if(pop(&S,&val))
	{
		printf("出栈成功\n");
		printf("出栈数据为：%d \n",val);
	}
	else printf("出栈失败\n");
	traverse(&S);
*/
	return 0;
}

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL; //or pS->Bottom->pNext = NULL
	}
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop; //why pS->pTop ?not pS->pbottom
	pS->pTop = pNew;

	return;
}

void traverse(PSTACK pS)
{
	PNODE p = pS -> pTop;
	while(p!=pS->pBottom)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

//pS栈，出栈一次，把出栈的元素存入pVal
bool pop(PSTACK pS,int * pVal)
{
	if ( empty(pS) )   //pS中本来就是S的地址
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;

		return true;
	}
}

//clear 清空
void clear(PSTACK pS)
{
	if(empty(pS))
	{
		return;
	}
	else 
	{
		PNODE p = pS ->pTop;
		PNODE q = p->pNext;

		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}