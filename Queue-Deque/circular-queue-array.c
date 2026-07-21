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

void Display(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (1)
    {
        printf("[%d] ", q->arr[i]);
        if (i == q->rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    struct queue q;
    Initialize(&q);

    // 1. Fill up the circular queue
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);
    Display(&q);

    // 2. Try to overflow
    Enqueue(&q, 60);

    // 3. Free up two slots from the front
    printf("Dequeued: %d\n", Dequeue(&q)); // Removes 10
    printf("Dequeued: %d\n", Dequeue(&q)); // Removes 20
    Display(&q);

    // 4. Watch it circularly wrap around to index 0 and 1!
    Enqueue(&q, 60);
    Enqueue(&q, 70);
    Display(&q);

    return 0;
}
