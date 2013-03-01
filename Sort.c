#include "sort.h"
void Sort()
{
		printf("-----Sort func libs-----\n");
		int length, max;
		int *array;
		int i;

		while (1) {
			printf("\n\n输入随机数个数及数值上限:\n");
			scanf("%d %d", &length, &max);

			array = initarray(length,max);
			printf("产生长度为%d的随机序列：\n", length);

			for(i = 0; i < length; i ++)
			{
				if (!(i % 15))
						printf("\n");
				printf("%4d ", array[i]);
			}
			printf("\n\n");

			printf("选择使用排序方式:\n\n");
			for (i = 0; i < SORT_END + 1; i ++)
					printf("%d.%s\n", i, SortFuncTips[i].tips);
			printf("\n\n");
			scanf("%d", &i);

			switch (i) {
					case BUBBLE_SORT:
						 bubble_sort(array,length);
						 break;
					case INSERTION_SORT:
						 break;
					case BUCKET_SORT:
						 break;
					case COUNTING_SORT:
						 break;
					case MERGE_SORT:
						 break;
					case BINARY_TREE_SORT:
						 break;
					case SHELL_SORT:
						 break;
					case QUICK_SORT:
						 break;
					case HEAP_SORT:
						 break;
					case SORT_END:
						 return;
					default:
							printf("wrong select...\n");
							continue;
			}
}
}
