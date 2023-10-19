void Enqueue(Stack *ps,int num)
{
    push(ps,num);
}
void Dequeue(Stack *ps)
{
    if(StackEmpty(*ps))
    {
        printf("Empty Queue\n");
        return;
    }
    Stack temb;
    InitStack(&temb);
    while(!StackEmpty(*ps))
    {
        push(&temb,StackTop(*ps));
        pop(ps);
    }
    pop(&temb);
    while(!StackEmpty(temb))
    {
        push(ps,StackTop(temb));
        pop(&temb);
    }
}
