#include "Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d\n", GetQueueFront(&q));
	printf("%d\n", GetQueueBack(&q));
	QueuePop(&q);
	printf("%d\n", GetQueueFront(&q));
	printf("%d\n", GetQueueBack(&q));
	QueueDestroy(&q);
	return 0;
}