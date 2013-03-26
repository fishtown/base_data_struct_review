#include "sort.h"
void Sort()
{
		printf("-----Sort func libs-----\n");
		int length, max;
		int *array = NULL;
		int i;

		while (1) {
			printf("\n\n输入随机数个数及数值上限:\n");
			scanf("%d %d", &length, &max);

			if (length < 0 || max < 0)
			{
				printf("输入错误，长度和最大值必须大于0\n");
				return;
			}

			array = initarray(length, max);
			printf("产生长度为%d的随机序列：\n", length);

			for (i = 0; i < length; i ++)
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
			sort_times = 0;

			switch (i) {
					case BUBBLE_SORT: //O(n^2)
						 bubble_sort(array, length);
						 break;

					case INSERTION_SORT: //O(n^2)
						 insertion_sort(array, length);
						 break;

					case BINARY_INSERTION_SORT: //O(n^2)
						 binary_insertion_sort(array, length);
						 break;

					case MERGE_SORT: //O(nlogn),空间O(n)
						 merge_sort(array, 0, length - 1);
						 break;

					case SELECTION_SORT:
						 break;

					case RADIX_SORT:
						 break;

					case SHELL_SORT:
						 break;

					case QUICK_SORT: //O(nlogn) ~ O(n^2)
						 quick_sort(array, 0, length - 1);
						 break;

					case HEAP_SORT:
						 break;

/*------------------------other methods--------------------------------------------*/
					case BUCKET_SORT: //O(n)
						 bucket_sort(array, length, max);
						 break;

					case COUNTING_SORT: //O(n), 空间O(length + max)
						 counting_sort(array, length, max);
						 break;

					case SORT_END:
						 return;
					default:
							printf("wrong select...\n");
							continue;
			}
			if (i != COUNTING_SORT)
			dump_sorted(array, length);
			free(array);
}
}
