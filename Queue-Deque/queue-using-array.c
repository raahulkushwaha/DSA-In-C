#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct queue
{
    int arr[MAX];
    int front;
    int rear;
};

void Initialize(struct queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int IsEmpty(struct queue *q)
{
    return (q->front == -1 || q->rear == -1);
}

int IsFull(struct queue *q)
{
    return q->rear == MAX - 1;
}

int main()
{
    struct queue myQueue;
    Initialize(&myQueue);

    return 0;
}