#include "stack.h"
void Stack()
{
		int type;
		printf("\n\n-----Stack func libs\n");
		printf("选择栈类型:\n0.顺序栈\n1.链栈\n");
		scanf("%d", &type);
		
		switch (type) {
				case 0:
						OrderStackEntry();
						break;
				case 1:
						ChainStackEntry();
						break;
				default:
						printf("wrong select,select again...\n");
		}
}

void OrderStackEntry()
{

}

void ChainStackEntry()
{
		int type, i;

		CStackNode *snode = (CStackNode *)malloc(sizeof(CStackNode));
		snode->data = -1;
		snode->next = NULL;
		CStack *s;
		s = (CStack *)&snode;

		while (1) {
			for (i = 0; i < EXIT +1; i ++)
					printf("%d.%s\n", i, StackFuncTips[i].tips);
		scanf("%d", &type);
		switch (type) {
				case INIT:
						initstack(s);
						break;
				case PUSH:
						pushstack(s);
						break;
				case POP:
						popstack(s);
						break;
				case GETTOP:
						gettop(s);
						break;
				case EXIT:
						return;
		}
		}
}
