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
    return (q->front == -1 || q->front > q->rear);
}

int IsFull(struct queue *q)
{
    return q->rear == MAX - 1;
}

void Enqueue(struct queue *q, int data)
{
    if (IsFull(q))
    {
        printf("Queue Overflow! Cannot enqueue %d\n", data);
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = data;
    printf("Enqueued %d\n", data);
}

int Dequeue(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue Underflow! Nothing be dequeued\n");
        return -1;
    }

    int dequeuedVal = q->arr[q->front];
    q->front++;

    return dequeuedVal;
}

int Peek(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

int main()
{
    struct queue myQueue;
    Initialize(&myQueue);

    Enqueue(&myQueue, 10);
    Enqueue(&myQueue, 20);
    Enqueue(&myQueue, 30);
    Enqueue(&myQueue, 40);
    Enqueue(&myQueue, 50);
    Enqueue(&myQueue, 50);

    printf("Peek Element: %d\n", Peek(&myQueue));

    printf("Dequeued value: %d\n", Dequeue(&myQueue));
    printf("Dequeued value: %d\n", Dequeue(&myQueue));
    printf("Peek Element: %d\n", Peek(&myQueue));
    printf("Dequeued value: %d\n", Dequeue(&myQueue));
    printf("Dequeued value: %d\n", Dequeue(&myQueue));
    printf("Dequeued value: %d\n", Dequeue(&myQueue));
    printf("Dequeued value: %d\n", Dequeue(&myQueue));

    return 0;
}