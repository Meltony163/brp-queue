#include<stdio.h>
#include<stdlib.h>
void push (Queue *pq,int num)
{
    Enqueue(pq,num);
}
void pop(Queue *pq)
{
    Queue temb;
    InitQueue(&temb);
    int first,second;
    if(IsEmpty(*pq))
    {
        printf("Empty Stack\n");
        return;
    }
    first=Peek(pq);
    Dequeue(pq);
    if(IsEmpty(*pq))
    {
        return;
    }
    second=Peek(pq);
    Dequeue(pq);
    while(!IsEmpty(*pq))
    {
        Enqueue(&temb,first);
        first=second;
        second=Peek(pq);
        Dequeue(pq);
    }
    Enqueue(&temb,first);
    DestoryQueue(pq);
    while(!IsEmpty(temb))
    {
        first=Peek(&temb);
        Enqueue(pq,first);
        Dequeue(&temb);
    }
    DestoryQueue(&temb);
    return;
}


