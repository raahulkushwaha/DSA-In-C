#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void Initialize(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int IsEmpty(struct queue *q)
{
    return q->front == NULL;
}

void Enqueue(struct queue *q, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    if (IsEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
        printf("Enqueued %d\n", data);
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d\n", data);
}

int Dequeue(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue Underflow! Cannot dequeue from an empty line.\n");
        return -1;
    }

    struct node *temp = q->front;
    int dequeuedValue = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

void Display(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = q->front;
    while (temp != NULL)
    {
        printf("[%d] --> ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    struct queue myQueue;
    Initialize(&myQueue);

    Enqueue(&myQueue, 10);
    Enqueue(&myQueue, 20);
    Enqueue(&myQueue, 30);
    
    Display(&myQueue);

    printf("Dequeued value: %d\n", Dequeue(&myQueue));
    printf("Dequeued value: %d\n", Dequeue(&myQueue));

    Display(&myQueue);

    return 0;
}