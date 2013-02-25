#include "linklist.h"
void LinkList()
{
		printf("\n\nlinklist func libs:\n");
		printf("select linklist type:\n");
		printf("1.singlelist\n");
		printf("2.doublelist\n");

		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
				SListEntry();
				break;
		case 2:
				DListEntry();
				break;
		default:
				printf("wrong input....\n");
		}
}

static void SListEntry()
{
		int i;
		int type;

		SLinkList slist = (SListNode *)malloc(sizeof(SListNode));
		slist->data = -1;
		slist->next = NULL;
		SLinkList *pslist =& slist;

		while (1) {
		for (i = 0; i < SEND_SLIST + 1; i ++)
				printf("%d.%s\n",i, SListFuncTips[i].str);

		scanf("%d", &type);
			switch (type) {
			case SCREATE:
					slist_create(pslist);
					continue;
			case SDUMP:
					slist_dump(*pslist);
					continue;
			case SINSERT:
					slist_insert(*pslist);
					continue;
			case SDELETE:
					slist_delete(*pslist);
					continue;
			case SREVERSE:
					slist_reverse(pslist);
					continue;
			case SEND_SLIST:
					break;
			default:
				printf("wrong input\n");
				continue;
		}
			return;
	}
}
static void DListEntry()
{
		int i;
		int type;

		DLinkList dlist = (DListNode *)malloc(sizeof(DListNode));
		dlist->data = -1;
		dlist->next = NULL;
		DLinkList *pdlist =& dlist;

		while (1) {
		for (i = 0; i < DEND_DLIST + 1; i ++)
				printf("%d.%s\n",i, DListFuncTips[i].str);

		scanf("%d", &type);
			switch (type) {
			case DCREATE:
					dlist_create(pdlist);
					continue;
			case DDUMP:
					dlist_dump(*pdlist);
					continue;
			case DINSERT:
					dlist_insert(*pdlist);
					continue;
			case DDELETE:
					dlist_delete(*pdlist);
					continue;
			case DEND_DLIST:
					return;
			default:
				printf("wrong input\n");
				continue;
		}
	}
}
