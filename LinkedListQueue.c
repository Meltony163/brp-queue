#include<stdio.h>
#include<stdlib.h>
typedef struct stacknode{
    int data;
    struct stacknode* link;
}node;
typedef  struct stack{
node* front;
node* rear;
}Queue;
int IsEmpty(Queue q)
{
    if(q.front==NULL)
    {
        return 1;
    }
    return 0;
}
void InitQueue(Queue* pq)
{
    pq->front=NULL;
    pq->rear=NULL;
}
void Enqueue(Queue* pq,int num)
{
    node* temb=(node*)malloc(sizeof(node));
    temb->data=num;
    temb->link=NULL;
    if(IsEmpty(*pq))
    {
        pq->front=temb;
        pq->rear=temb;
        return;
    }
    pq->rear->link=temb;
    pq->rear=temb;
    return;
}
void Dequeue(Queue* pq)
{
    if(IsEmpty(*pq))
    {
        printf("Queue is Empty\n");
        return;
    }
    node* temb;
    temb=pq->front;
    pq->front=pq->front->link;
    free(temb);
    if(pq->front==NULL)
    {
        pq->rear=NULL;
    }
    return;
}
void DestoryQueue(Queue *pq)
{
    node* temb;
    while(pq->front!=NULL)
    {
        temb=pq->front;
        pq->front=pq->front->link;
        free(temb);
    }
    pq->rear=NULL;
    return;
}
void TraversQueue(Queue s)
{
    node* temb=s.front;
    while(temb!=NULL)
    {
        printf("%d\n",temb->data);
        temb=temb->link;
    }
    return;
}
int Peek(Queue* pq)
{
	if(IsEmpty(*pq))
	{
		printf("Empty Queue\n");
		return 0;
	}
	return pq->front->data;
}
