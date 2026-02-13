#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;//∂”Õ∑
	QNode* rear;//∂”Œ≤
	int size;
}Queue;


void QueueInit(Queue* pq) ;

void QueuePush(Queue* pq, QDataType x);


void QueuePop(Queue* pq);


QDataType GetQueueFront(Queue* pq);

QDataType GetQueueBack(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePrint(Queue* pq);



