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

	q->rear = (q->rear + 1) % MAX_SIZE; //rear 부분 + 1 해주기 max size 안넘어가게 
	q->queue[q->rear] = data; // data 추가 
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
	e = q->queue[q->front]; // q의 front 일단 저장 
	q->front = (q->front + 1) % MAX_SIZE;// q front 가 maxsize 안넘어가게 front 다음꺼로 변경 
	q->size--; // 사이즈 -- ; 
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
