#include <stdio.h>

#define MAX 5

struct queue
{
    int arr[5];
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
    return q->front == -1;
}

int IsFull(struct queue *q)
{
    return q->front == (q->rear + 1) % MAX;
}

void Enqueue(struct queue *q, int data)
{
    if (IsFull(q))
    {
        printf("Queue Overflow! Cannot be Enqued %d\n", data);
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;
    printf("Enqued %d\n", data);
}

int Dequeue(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue Underflow! Nothing to delete\n");
        return -1;
    }

    int dequeuedVal = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    return dequeuedVal;
}

