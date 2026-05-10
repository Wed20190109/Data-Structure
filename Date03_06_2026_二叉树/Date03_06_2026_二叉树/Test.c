#include "Heap.h"


//降序建小堆
//升序建大堆

void HeapSort(int* a, int n)
//排序原理:先建好堆，然后堆头和堆尾互换，再缩减未排序的堆里元素的范围
{ 
	for (int i = 0; i < n; i++)
	{
		shiftupMin(a, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		shiftdownMin(a, end, 0);
		end--;//因为已经排序好的元素已经处于末尾了，所以未处理的元素范围为[0,end-1]
	}
}

void Test_sort()
{
	int a[] = { 55,6,3,9,1,4,999,33,2 };
	HeapSort(a, sizeof(a) / sizeof(a[1]));
	for (int i = 0;i < sizeof(a) / sizeof(a[1]);i++)
	{
		printf("%d ", a[i]);
	}
};

int main()
{
	Test_sort();
}