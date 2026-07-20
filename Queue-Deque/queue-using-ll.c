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
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the integer value to enqueue: ");
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
            Display(&myQueue);
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