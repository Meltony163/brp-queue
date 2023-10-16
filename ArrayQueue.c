#include<stdio.h>
#define MAX_SIZE 3
typedef struct queue
{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Queue;
int IsFull(Queue* pq)
{
    if(pq->rear==MAX_SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(Queue *pq)
{
    if((pq->front==-1)||(pq->front==pq->rear+1))
    {
        return 1;
    }
    return 0;
}
void InitQueue(Queue *pq)
{
    pq->front=-1;
    pq->rear=-1;
    return;
}
void Enqueue(Queue *pq,int num)
{
    if(pq->front==-1)
    {
        pq->front=0;
        pq->rear=0;
        pq->arr[pq->front]=num;
        return;
    }
    else if(IsFull(pq))
    {
        printf("Queue is FULL");
        return;
    }
    pq->rear++;
    pq->arr[pq->rear]=num;
    return;
}
void Dequeue(Queue *pq)
{
    if(IsEmpty(pq))
    {
        printf("Queue is Empty\n");
        return;
    }
    pq->front++;
    return;
}
void DestroyQueue(Queue *pq)
{
    pq->front=-1;
    pq->rear=-1;
    return;
}
void Traverse (Queue* pq)
{
    if(IsEmpty(pq))
    {
        printf("Empty Queue\n");
        return;
    }
    for(int i=pq->front;i<=pq->rear;i++)
    {
        printf("%d\n",pq->arr[i]);
    }
    return;
}
int Peek(Queue* pq)
{
	if(IsEmpty(pq))
	{
		printf("Empty Queue\n");
		return 0;
	}
	return pq->arr[pq->front];
}