CC = gcc
ds_func: linklist.h LinkList.c main.h main.c
	$(CC)  -o test main.c main.h \
			linklist.h LinkList.c \
            stack.h Stack.c \
			queue.h Queue.c \
			array.h Array.c \
			tree.h Tree.c \
			graph.h Graph.c \
			search.h Search.c \
			sort.h Sort.c
clean:
	-rm test

