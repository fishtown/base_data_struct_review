#include "main.h"
int main(int argc ,char *argv[])
{
		int type;

		printf("-------------------------");
		printf("welcome to DS libbase");
		printf("-------------------------\n");
		printf("input your select:\n");
		while (1) {
		int i;
		for ( i = 0; i < END + 1; i ++ )
				printf("%d. %s\n", i, ds_tips[i].str);
		printf("---------\n");

		scanf("%d",&type);
		switch (type)
		{
			case LINKLIST:
					LinkList();
					break;
			case STACK:
					Stack();
					break;
			case QUEUE:
					Queue();
					break;
			case ARRAY:
					Array();
					break;
			case TREE:
					Tree();
					break;
			case GRAPH:
					Graph();
					break;
			case SEARCH:
					Search();
					break;
			case SORT:
					Sort();
					break;
			case END:
					return;
					break;
			default:
					printf("Wrong select,please input num 0~8\n");
					continue;
		}
		}
}
