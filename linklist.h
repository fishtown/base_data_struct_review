#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "debug.h"
void LinkList();
static void  SListEntry();
static void  DListEntry();

/*单链表结构定义及函数实现*/
typedef enum {
		SCREATE = 0,
		SDUMP,
		SINSERT,
		SDELETE,
		SREVERSE,
		SEND_SLIST,
}SListFunc;

static struct SList_Func_Tips {
		SListFunc type;
		char str[50];
} SListFuncTips[SEND_SLIST + 1] =
{
		{ SCREATE, "create(创建)"},
		{ SDUMP, "dump(输出)"},
		{ SINSERT, "insert(插入)"},
		{ SDELETE, "delete(删除)"},
		{ SREVERSE, "reverse(逆序)"},
		{ SEND_SLIST, "end"},
};

typedef struct SListNode {
		struct SListNode * next;
		int data;
} SListNode, *SLinkList;

static void slist_create(SLinkList *plist)
{
		int data;
		SLinkList  list, head;
		head = (SListNode*)malloc(sizeof(SListNode));
		head->data = -1;
		head->next = NULL;
		list = head;
		printf("input list nodes(输入-1终止):\n");

		scanf("%d",&data);
		int i = 0;
		while (data != -1)
		{
			SListNode *  tmp = (SListNode *)malloc(sizeof(SListNode));
			tmp->next = NULL;
			tmp->data = data;
			list->next = tmp;
			list = list->next;
			scanf("%d",&data);
		}
		*plist = head;
}
static void slist_dump(SLinkList head)
{
		if (head->next == NULL)
		{
			printf("list is empty\n");
			return;
		}
		do {
			head = head->next;
			printf("%d ",head->data);
		} while (head->next != NULL);
		printf("\n\n");
}
static void slist_insert(SLinkList head)
{
		int loc,value;
		int i = 0;
		SLinkList list = head;
		printf("当前链表为：\n");
		slist_dump(head);
		printf("输入插入的位置（从0开始，第几个之后）及其值为：\n");
		scanf("%d %d", &loc, &value);

		SListNode *  tmp = (SListNode *)malloc(sizeof(SListNode));
		tmp->next = NULL;
		tmp->data = value;

		while (list->next != NULL && i < loc)
		{
			list = list->next;
			i++;
		}
		if ( i < loc )
		{
			printf("输入位置超出链表总长度！\n");
			return;
		}

		if (list->next == NULL)
		{
			list->next = tmp;
			return;
		}
		tmp->next = list->next;
		list->next = tmp;

		printf("插入后链表为：\n");
		slist_dump(head);
}
static void slist_delete(SLinkList head)
{
		int loc, i = 0;
		SLinkList list = head;
		SLinkList pre;

		printf("当前链表为：\n");
		slist_dump(head);
		printf("输入删除的节点位置(从1开始）：\n");
		scanf("%d",&loc);

		while (list->next != NULL && i < loc)
		{
			pre = list;
			list = list->next;
			i++;
		}

		if (i < loc)
		{
			printf("输入位置超出链表总长度！\n");
			return;
		}

		if (list->next == NULL)
		{
			pre->next = NULL;
		} else {
			pre->next = list->next;
		}
		free(list);
		printf("删除节点后链表为：\n");
		slist_dump(head);
}
static void slist_reverse(SLinkList * phead)
{
	    SLinkList head,cur,after;
		head = *phead;

		printf("当前链表为：\n");
		slist_dump(head);
		if (head->next == NULL || head->next->next == NULL)
			return;
		//init
		cur = head->next;
		after = cur->next;
		head = NULL;
		//loop
		while (after->next != NULL)
		{
				cur->next = head;
				head = cur;
				cur = after;
				after = after->next;
		}

		//complete
		cur->next = head;
		after->next = cur;
		head = after;
		//re-init new head
		after = *phead;
		after->next = head;
		after->data = -1;
		head = after;
		printf("逆序后链表为：\n");
		slist_dump(head);
		phead =& head;
}
/*循环双链表结构定义及函数实现*/
typedef enum{
		DCREATE = 0,
		DDUMP,
		DINSERT,
		DDELETE,
		DEND_DLIST,
}DListFunc;

static struct DList_Func_Tips {
		DListFunc type;
		char str[50];
} DListFuncTips[DEND_DLIST + 1] =
{
		{ DCREATE, "create(创建)"},
		{ DDUMP, "dump(输出)"},
		{ DINSERT, "insert(插入)"},
		{ DDELETE, "delete(删除)"},
		{ DEND_DLIST, "end"},
};

typedef struct DListNode {
		struct DListNode * pre;
		struct DListNode * next;
		int data;
} DListNode, *DLinkList;

/*只定义一个头节点的双向循环链表*/
static void dlist_create(DLinkList *pdlist)
{
		int data;
		DLinkList  list, head;
		head = (DListNode*)malloc(sizeof(DListNode));
		head->data = -1;
		head->next = head;
		head->pre = head;
		list = head;
		printf("input list nodes(输入-1终止):\n");

		scanf("%d",&data);
		int i = 0;
		while (data != -1)
		{
			DListNode *  tmp = (DListNode *)malloc(sizeof(DListNode));
			tmp->data = data;
			tmp->next = head;
			tmp->pre = list;
			list->next = tmp;
			head->pre = tmp;
			list = list->next;
			scanf("%d",&data);
		}
		*pdlist = head;
}
static void dlist_dump(DLinkList head)
{
		DLinkList cur = head->next;
		printf("正向输出序列为：\n");
		while(cur->next != head)
		{
				printf("%d  ",cur->data);
				cur = cur->next;
		}
		printf("%d  ",cur->data);
		printf("\n\n");

		printf("反向输出序列为：\n");
		cur = head->pre;
		while(cur->pre != head)
		{
				printf("%d  ",cur->data);
				cur = cur->pre;
		}
		printf("%d  ",cur->data);
		printf("\n\n");
}
static void dlist_insert(DLinkList head)
{
		int loc,value;
		int i = 0;
		DLinkList list = head;
		printf("当前链表为：\n");
		dlist_dump(head);
		printf("输入插入的位置（从0开始，第几个之后）及其值为：\n");
		scanf("%d %d", &loc, &value);

		DListNode *  tmp = (DListNode *)malloc(sizeof(DListNode));
		tmp->next = NULL;
		tmp->pre = NULL;
		tmp->data = value;

		for (i = 0; i < loc && list->next != head; i ++)
		{
				list = list->next;
		}
		if (i < loc )
		{
			printf("输入位置超出链表总长度！\n");
		}

		tmp->next = list->next;
		tmp->pre = list;
		list->next->pre = tmp;
		list->next = tmp;
		printf("插入后链表为：\n");
		dlist_dump(head);
}
static void dlist_delete(DLinkList head)
{
		int loc, i = 0;
		DLinkList list = head;

		printf("当前链表为：\n");
		dlist_dump(head);
		printf("输入删除的节点位置(从1开始）：\n");
		scanf("%d",&loc);

		while (list->next != head && i < loc)
		{
			list = list->next;
			i++;
		}

		if (i < loc)
		{
			printf("输入位置超出链表总长度！\n");
			return;
		}

		list->pre->next = list->next;
		list->next->pre = list->pre;
		list->pre = NULL;
		list->next = NULL;
		free(list);

		printf("删除节点后链表为：\n");
		dlist_dump(head);
}
