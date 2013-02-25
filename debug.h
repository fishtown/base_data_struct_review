#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include <stdlib.h>
void pr_ln()
{
		printf("vi %s + %d\n",__func__,__LINE__);
}

#endif
