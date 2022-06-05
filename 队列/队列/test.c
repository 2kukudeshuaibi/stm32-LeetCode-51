#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

int main()
{
	queue p;
	QueueInit(&p);
	Queuepush(&p, 1);
	Queuepush(&p, 2);
	Queuepush(&p, 3);
	Queuepush(&p, 4);
	Queuepush(&p, 5);
	Queuepush(&p, 5);
	Queuepush(&p, 5);
	while (!QueueEmpty(&p))
	{
		printf("%d ", Queuefront(&p));
		Queuepop(&p);
	}
	return 0;
}