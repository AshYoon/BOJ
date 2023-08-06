#include "circularQueue.h"

void beforeExit() {
	getchar();
}


void init(Queue* q)
{
	q->front = 0;
	q->rear = -1;
	q->size = 0;
}

bool isFull(Queue* q)
{
	return (q->size == MAX_SIZE);
}

bool isEmpty(Queue* q)
{

	return (q->size == 0);
}

void enQueue(Queue* q, TreeElement data)
{
	if (isFull(q))
	{
		printf("Error : queue Empty \n");
		exit(1);
	}

	q->rear = (q->rear + 1) % MAX_SIZE; //rear �κ� + 1 ���ֱ� max size �ȳѾ�� 
	q->queue[q->rear] = data; // data �߰� 
	q->size++; //size ++ 






}

TreeElement deQueue(Queue* q)
{
	if (isEmpty(q))
	{
		printf("Error : Queue is Empty \n");
		exit(1);
	}


	TreeElement e;
	e = q->queue[q->front]; // q�� front �ϴ� ���� 
	q->front = (q->front + 1) % MAX_SIZE;// q front �� maxsize �ȳѾ�� front �������� ���� 
	q->size--; // ������ -- ; 
	return e;

}

//TreeElement peep(Queue* q)
//{
//	if (isEmpty(q))
//	{
//		return NULL;
//	}
//	return q->queue[(q->front + 1) % MAX_SIZE];
//}
