#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
void Stack();
void OrderStackEntry();
void ChainStackEntry();
typedef enum {
		INIT = 0,
		PUSH,
		POP,
		GETTOP,
		EXIT,
}StackFunc;

static struct Stack_Func_Tips {
		StackFunc type;
		char tips[30];
} StackFuncTips[EXIT + 1] =
{
		{INIT, "initstack"},
		{PUSH, "push"},
		{POP, "pop"},
		{GETTOP, "get top elements"},
		{EXIT, "exit"},
};

typedef int ElementType ;
typedef struct CStackNode {
		ElementType data;
		struct CStackNode * next;
}CStackNode;
typedef struct {
		CStackNode *top;
}CStack;

static void  initstack(CStack *s)
{
		s->top = NULL;
}

//Note,must include stdbool.h for C99, otherwise casue compile issue.
static bool isEmpty(CStack *s)
{
		return (s->top == NULL? 1 : 0);
}


static void pushstack(CStack *s)
{
		ElementType data;
		printf("输入要压入的值:\n");
		scanf("%d", &data);

		CStackNode *p = (CStackNode *)malloc(sizeof(struct CStackNode));
		p->data = data;
		p->next = s->top;
		s->top = p;
}
static void gettop(CStack *s)
{
		if (isEmpty(s))
				printf("空栈！！\n");
		else
		printf("当前栈顶元素为：%d\n", s->top->data);
}

static void popstack(CStack *s)
{
		if(isEmpty(s)) {
				printf("已至栈底!\n");
				return;
		}

		CStackNode *tmp = s->top;
		s->top = s->top->next;
		printf("弹出数据为：%d\n", tmp->data);
		free(tmp);
}
