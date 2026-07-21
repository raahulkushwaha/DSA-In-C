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
    return (q->front == 0 && q->rear == MAX - 1);
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

void InsertFront(struct queue *q, int data)
{
    if (IsFull(q) || q->front == 0)
    {
        printf("Queue Overflow! Cannot insert front %d\n", data);
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->front--;
    }

    q->arr[q->front] = data;
    printf("Inserted Front %d\n", data);
}

int DeleteRear(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue Underflow! Nothing to delete\n");
        return -1;
    }

    int deletedVal = q->arr[q->rear];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->rear--;
    }
    
    return deletedVal;
}

void Display(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Current Deque: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("[%d] ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue myDeque;
    Initialize(&myDeque);

    // Populate from the rear first to open up space
    InsertRear(&myDeque, 20);
    InsertRear(&myDeque, 30);
    InsertRear(&myDeque, 40);
    Display(&myDeque);

    // Delete from the front to open up slot index 0
    printf("Dequeued Front: %d\n", DeleteFront(&myDeque)); // Removes 20
    Display(&myDeque);

    // Now index 0 is open, we can call InsertFront
    InsertFront(&myDeque, 10);
    Display(&myDeque);

    // Remove from the back
    printf("Dequeued Rear: %d\n", DeleteRear(&myDeque));  // Removes 40
    Display(&myDeque);

    return 0;
}