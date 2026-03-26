#include "Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HPPush(HP* php, HeapDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HeapDataType* temp = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * newcapacity);
		if (temp == NULL)
		{
			perror("realloc fail");
		}
		php->a = temp;
		php->capacity = newcapacity;

	}
	php->a[php->size] = x;
	php->size++;
}

void shiftup(HP* a, int child)
{
	int parent = (child - 1) / 2;
	while (parent>=0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], a[parent]);
			child = parent;
			parent = (child - 1) / 2;

		}
		else
		{
			break;
		}
	}

}