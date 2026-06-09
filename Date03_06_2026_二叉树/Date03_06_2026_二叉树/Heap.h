#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS 1
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
}HP;

void HPInit();
void HPDestroy();
void HPPush();
void HPPop();
void shiftupMin(HeapDataType* a, int child);
void shiftdownMin(HeapDataType* a, int size, int parent);
void shiftupMax(HeapDataType* a, int child);
void shiftdownMax(HeapDataType* a, int size, int parent);

void HPTop(HP* php, HeapDataType* x);
void Swap(HeapDataType* a, HeapDataType* b);
void HPEmpty(HP* php);