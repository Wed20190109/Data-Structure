#include "Stack.h"

int main() {
	ST s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPrint(&s);
	printf("top=%d\n", StackTop(&s));
	printf("size=%d\n", StackSize(&s));
	StackPop(&s);
	StackPrint(&s);
	printf("top=%d\n", StackTop(&s));
	printf("size=%d\n", StackSize(&s));
	StackDestroy(&s);
	return 0;
}