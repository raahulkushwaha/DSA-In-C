#include <stdio.h>

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
    return (q->front == -1 || q->front > q->rear);
}

int IsFull(struct queue *q)
{
    return (q->front == 0 || q->rear == MAX - 1);
}

void InsertRear(struct queue *q, int data)
{
    if (IsFull(q))
    {
        printf("Queue Overflow! Cannot insert rear %d\n", data);
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = data;
    printf("Inserted Rear %d\n", data);
}

int DeleteFront(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue Underflow! Nothing to delete from front\n");
        return -1;
    }

    int deletedVal = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return deletedVal;
}
