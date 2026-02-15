#include "Queue.h"
void QueueInit(Queue* pq) {
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->rear == NULL)
	{
		pq->front = pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->front);
	QNode* newnode = pq->front->next;//只能头节点被删除，所以直接把头节点的下一个节点保存起来，最后把头节点free掉就行了
	free(pq->front);
	pq->front = newnode;
	if (pq->front == NULL)//也可以在开头判断是不是只有一个节点，如果是一个节点，直接free掉就行了
	{
		pq->rear = NULL;
	}
	pq->size--;
}

QDataType GetQueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->front);
	return pq->front->data;
}

QDataType GetQueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->rear);
	return pq->rear->data;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;
	pq->size = 0;
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->front;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
