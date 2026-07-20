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

    int choice, value;

    while (1)
    {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter integer value to enqueue: ");
            scanf("%d", &value);
            Enqueue(&myQueue, value);
            break;

        case 2:
            value = Dequeue(&myQueue);
            if (value != -1)
            {
                printf("Dequeued value: %d\n", value);
            }
            break;

        case 3:
            value = Peek(&myQueue);
            if (value != -1)
            {
                printf("Peek Element: %d\n", value);
            }
            break;

        case 4:
            printf("Exiting program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice! Please select a valid menu option (1-4).\n");
        }
    }

    return 0;
}