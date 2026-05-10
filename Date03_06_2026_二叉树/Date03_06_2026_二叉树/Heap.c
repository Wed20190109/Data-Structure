#include "Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void Swap(HeapDataType* a, HeapDataType* b)
{
	HeapDataType temp = *a;
	*a = *b;
	*b = temp;
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

	shiftupMin(php->a, php->size - 1);
}

void pop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	shiftdownMin(php->a, php->size, 0);
};

void shiftupMin(HeapDataType* a, int child)//child是新插入元素的下标
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

void shiftupMax(HeapDataType* a, int child)//child是新插入元素的下标
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

void shiftdownMin(HeapDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;//现在情况是parent为最大的parent就是下标为0，现在找左孩子的下标
	while (child < size)//判断孩子下标是否小于size最大下标
	{
		if (child + 1 < size && a[child + 1] < a[child])//（child+1为右孩子）如果右孩子存在，并且右孩子比左孩子小，那么就让child指向右孩子
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;//原child位置的元素已经交换到parent位置了，所以parent下标要更新为child
			child = parent * 2 + 1;//继续寻找下一层的孩子
		}
		else
		{
			break;
		}
	}
};

void shiftdownMax(HeapDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)//判断孩子下标是否小于size最大下标
	{
		if (child + 1 < size && a[child + 1] > a[child])//如果右孩子存在，并且右孩子比左孩子大，那么就让child指向右孩子
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;//原child位置的元素已经交换到parent位置了，所以parent下标要更新为child
			child = parent * 2 + 1;//继续寻找下一层的孩子
		}
		else
		{
			break;
		}
	}
};

void HPTop(HP* php)
{
	assert(php);
	return php->a[0];
}

void HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
