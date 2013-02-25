#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
typedef enum {
		LINKLIST = 0,
		STACK,
		QUEUE,
		ARRAY,
		TREE,
		GRAPH,
		SEARCH,
		SORT,
		END = 8,
}DSType;
struct DS_Tips {
		DSType type;
		char str[20];
} ds_tips[END + 1] =
{
		{ LINKLIST, "linklist"},
		{ STACK, "stack"},
		{ QUEUE, "queue"},
		{ ARRAY, "array"},
		{ TREE, "tree"},
		{ GRAPH, "graph"},
		{ SEARCH, "search"},
		{ SORT, "sort"},
		{ END, "end"},
};
