#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#ifndef DEBUG
#define DEBUG
#endif
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

void dump_sorted(int *a, int len)
{
	int i;

	printf("排序后序列为:\n");
	for (i = 0; i < len; i++)
	{
		if(!(i % 15))
			printf("\n");
		printf("%4d ",a[i]);
	}
	printf("\n");
}
void dump_progress(int *a, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%d ",a[i]);
	}
}
int swap(int *a, int *b)
{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;

		return 1;
}

/* O(n^2) */
void bubble_sort(int *a, int len)
{
	int i, j = 0;
	int mov = 0;
	for (i = 1; i < len; i++)
	{
			for (j = 0; j < len - i; j++)
			{
					mov += (a[j] > a[j+1]) ? swap(a+j, a+j+1) : 0;
			}
	}
	dump_sorted(a,len);
	printf("移动次数为 %d\n",mov);
}

int partition(int *a, int low, int high)
{
		int pivot = low;
		int pivotkey = a[low];

		while (low < high)
		{
			while(low < high && a[high] >= pivotkey)
				high --;
			a[low] = a[high];

			while(low < high && a[low] <= pivotkey)
				low ++;
			a[high] = a[low];
		}
		a[low] = pivotkey;
		return low;
}
static int qsort_times = 0;
void quick_sort(int *a, int low,  int high)
{
	int pivot;
	if (low < high) {
			pivot = partition(a, low, high);
#ifdef DEBUG
			printf("第%d次-分割后为{",++qsort_times);
			dump_progress(a+low, pivot-low );
			printf("} -[%d]- {",*(a+pivot));
			dump_progress(a+pivot+1, high-pivot);
			printf("}\n");
#endif
			quick_sort(a, low, pivot-1);
			quick_sort(a, pivot+1, high);
	}
}
