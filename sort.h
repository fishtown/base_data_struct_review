#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
void Sort();
static int* initarray(int length, int max)
{
		int *result;

		result = (int *)malloc(sizeof(int) * length);
		int x = length;

		while (length--)
		{
				*result = rand() % (max + 1);
				result ++;
		}

		result -= x;
		return result;
}

typedef enum {
		BUBBLE_SORT = 0,
		INSERTION_SORT,
		BUCKET_SORT,
		COUNTING_SORT,
		MERGE_SORT,
		BINARY_TREE_SORT,
		SHELL_SORT,
		QUICK_SORT,
		HEAP_SORT,
		SORT_END,
}SORTFUNC;
struct Sort_Func_Tips {
		SORTFUNC type;
		char     tips[50];
}SortFuncTips[SORT_END + 1] = {
		{BUBBLE_SORT, "bubble sort(冒泡排序)"},
		{INSERTION_SORT, "insertion sort(插入排序)"},
		{BUCKET_SORT, "bucket sort(桶排序)"},
		{COUNTING_SORT, "counting sort(计数排序)"},
		{MERGE_SORT, "merge sort(归并排序)"},
		{BINARY_TREE_SORT, "binary tree sort(二叉数排序)"},
		{SHELL_SORT, "shell sort(希尔排序)"},
		{QUICK_SORT, "quick sort(快速排序)"},
		{HEAP_SORT, "heap sort(堆排序)"},
		{SORT_END, "exit(退出)"},
};
