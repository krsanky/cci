#include <stdio.h>

#include "lib1.h"

void
f1()
{
	printf("f1()....call..f2()....\n");
	f2();
}

void
f2()
{
	printf("f2()........\n");
}
