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