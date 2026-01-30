#include "Stack.h"

void StackInit(ST* ps) {
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	ps->top = 0;//top指向栈顶元素的下一个位置,也可以设定指向栈顶元素，不过要改变初始化的值为-1
	ps->capacity = 4;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->top == ps->capacity) {
		STDataType* pNew = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (pNew != NULL) {
			ps->a = pNew;
			ps->capacity *= 2;
		}
		else {
			printf("realloc fail\n");
			exit(-1);
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDataType StackTop(ST* ps) {
		assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];

}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}

void StackPrint(ST* ps) {
	assert(ps);
	for (int i = 0; i < ps->top; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}