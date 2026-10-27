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
	QNode* front;//队头
	QNode* rear;//队尾
	int size;
}Queue;


void QueueInit(Queue* pq) ;//pq是point to quque，意为指向queue的指针

void QueuePush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType GetQueueFront(Queue* pq);

QDataType GetQueueBack(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePrint(Queue* pq);

void QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);
