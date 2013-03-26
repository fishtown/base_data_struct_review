#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#ifndef DEBUG
#define DEBUG
#endif
#undef DEBUG //comment this line if need dump progress
void Sort();
static int sort_times = 0;
static int* initarray(int length, int max)
{
		int *result;

		result = (int *)malloc(sizeof(int) * length);
		int x = length;

		while (length --)
		{
				*result = rand() % max;
				result ++;
		}

		result -= x;
		return result;
}

typedef enum {
		BUBBLE_SORT = 0,//G
		INSERTION_SORT,//G
		BINARY_INSERTION_SORT,//G
		MERGE_SORT,//G
		SELECTION_SORT,//G
		RADIX_SORT,//G
		SHELL_SORT,//G
		QUICK_SORT,//G
		HEAP_SORT,//G
		COUNTING_SORT,
		SORT_END,
}SORTFUNC;
struct Sort_Func_Tips {
		SORTFUNC type;
		char     tips[50];
}SortFuncTips[SORT_END + 1] = {
		{BUBBLE_SORT, "bubble sort(冒泡排序)"},
		{INSERTION_SORT, "insertion sort(插入排序)"},
		{BINARY_INSERTION_SORT,"binary insertion sort(折半插入排序)"},
		{MERGE_SORT, "merge sort(归并排序)"},
		{SELECTION_SORT, "selection sort(选择排序)"},
		{RADIX_SORT, "radix sort (基数排序)"},
		{SHELL_SORT, "shell sort(希尔排序)"},
		{QUICK_SORT, "quick sort(快速排序)"},
		{HEAP_SORT, "heap sort(堆排序)"},
		{SORT_END, "exit(退出)"},
		{COUNTING_SORT, "counting sort(计数排序)"},
};

static void dump_sorted(int *a, int len)
{
	int i;

	printf("\n排序后序列为:\n");
	for (i = 0; i < len; i++)
	{
		if (!(i % 15))
			printf("\n");
		printf("%4d ", a[i]);
	}
	printf("\n");
}
static void dump_progress(int *a, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}
static int swap(int *a, int *b)
{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;

		return 1;
}

/* O(n^2) */
static void bubble_sort(int *a, int len)
{
	int i, j = 0;
	int mov = 0;
	for (i = 1; i < len; i++)
	{
			for (j = 0; j < len - i; j++)
			{
					mov += (a[j] > a[j+1]) ? swap(a+j, a+j+1) : 0;
			}
#ifdef DEBUG
					printf("\n第%d次冒泡后的序列为：", ++ sort_times);
					dump_progress(a, len);
#endif
	}
	printf("移动次数为 %d\n",mov);
}

static int partition(int *a, int low, int high)
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


/* O(nlogn) ~ O(n^2) */
static void quick_sort(int *a, int low,  int high)
{
	int pivot;
	if (low < high) {
			pivot = partition(a, low, high);
#ifdef DEBUG
			printf("第%d次-分割后为{", ++ sort_times);
			dump_progress(a + low, pivot - low );
			printf("} -[%d]- {", *(a + pivot));
			dump_progress(a + pivot + 1, high - pivot);
			printf("}\n");
#endif
			quick_sort(a, low, pivot - 1);
			quick_sort(a, pivot + 1, high);
	}
}
static int getbitlen(int k)
{
		int i = 0;
		while (k /= 10)
				i ++;
		return i+1;
}
static int getbitvalue(int k, int i)
{
		if (i < 1)
			return k % 10;

		while (i --)
			k /= 10;

		k %= 10;

		return k;
}

/*O(n)*/
static void radix_sort(int *a, int len, int max) //LSD
{
		int i,j,l,k = 0;
		int bkt[10][max];
		int max_bit = getbitlen(max);
		for (i = 0; i < max_bit; i ++)
		{
			memset(bkt, -1, sizeof(bkt));
			for (j = 0; j < len; j ++)
			{
				k = getbitvalue(a[j],i);
				//add2bkt(k,a[j]);
				if (bkt[k][0] == -1)
						bkt[k][0] = a[j];
				else
				{
					l = 0;
					while(bkt[k][l] != -1)
							l ++;
					bkt[k][l] = a[j];
				}
			}
#ifdef DEBUG
			printf("第%d次处理的桶状态：\n", ++ sort_times);
#endif
			l=0;
			for (j = 0; j < 10; j ++)
			{
#ifdef DEBUG
				printf("第%d个捅子内容为:  ", j);
#endif
				for (k = 0; bkt[j][k] != -1 && k < max; k++)
				{
#ifdef DEBUG
						printf("%d ", bkt[j][k]);
#endif
						a[l] = bkt[j][k];
						l ++;
				}
#ifdef DEBUG
				printf("\n");
#endif
			}
		}
}

//O(n^2)
static insertion_sort(int *a, int len)
{
		int i, j = 0;
		int k, _tmp = 0;

		for (i = 1; i < len; i ++)
		{
#if MMZ_OPT
			for (j = 0; j < i; j ++)
			{
				if (a[i] < a[j])
					swap(a + i, a + j);
			}
#else
			for (j = 0; j < i && a[i] > a[j]; j++);
			_tmp = a[i];
			for (k = i; k > j; k--)
					a[k] = a[k - 1];
			a[j] = _tmp;
#endif
		}
}

//O(n^2)
static binary_insertion_sort(int *a, int len)
{
		int i, j = 0;
		int mid, low, high = 0;
		int _tmp;

		for (i = 1; i < len; i ++)
		{
			low = 0;
			high = i -1 ;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (a[mid] < a[i])
					low = mid + 1;
				else
					high = mid - 1;
			}

			mid = high +1;//mid the shoot position, reverse resean is last "high = mid -1"
			_tmp = a[i];

			for (j = i; j > mid; j--)
				a[j] = a[j - 1];

			a[mid] = _tmp;
		}
}

//O(n)
static counting_sort(int *a, int len, int max)
{
		int b[len]; //b array is for sorted result
		int c[max]; //c array is for counting result
		int i, j, k = 0;

		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));

		for (i = 0; i < len; i ++)
			c[a[i]] += 1;
		for (i = 1; i < max; i ++)
		{
			c[i] = c[i-1] + c[i];
		}

		//反向遍历c数组才能保证排序的稳定性
		for (i = len - 1; i >= 0; i --)
		{
			b[c[a[i]] - 1] = a[i];
			c[a[i]] -= 1;
		}
		dump_sorted(b, len);
}

static merge(int *a, int left, int mid, int right)
{
		int i, j, k = 0;
		int *tmp;

		i = left;
		j = mid + 1;
		tmp = (int *)malloc(sizeof(int) * (right - left + 1));

		while (i <= mid && j <= right)
		{
			if (a[i] < a[j])
				tmp[k] = a[i++];
			else
				tmp[k] = a[j++];
			k++;
		}

		while(i <= mid)
			tmp[k++] = a[i++];

		while(j <= right)
			tmp[k++] = a[j++];

		for(i = left, k = 0; i <= right; i++, k++)
			a[i] = tmp[k];
}
//O(nlogn)
static merge_sort(int *a, int left, int right)
{
		int mid = 0;
		if (left < right)
		{
			mid = (left + right) / 2;
			merge_sort(a, left, mid);
			merge_sort(a, mid + 1, right);
			merge(a, left, mid, right);
		}
}

//O(n^2)
static selection_sort(int *a, int len)
{
	int i, j, k = 0;
	int _min = 0;

	for (i = 0; i < len; i ++)
	{
		_min = a[i];
		k = -1;
		for (j = i; j < len; j ++)
		{
			if (a[j] < _min)
			{
				k = j;
				_min = a[j];
			}
		}
		if (k != -1)
		swap(a + i, a + k);
	}
}
//Just use gap sequence(5,3,1)
static shell_sort(int *a, int len)
{
}
