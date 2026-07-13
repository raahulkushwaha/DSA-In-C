#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Push(struct node **top, int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    // newNode->next = NULL;

    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

int Pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    struct node *temp = *top;
    int poppedItem = temp->data;

    *top = temp->next;
    free(temp);

    return poppedItem;
}

int Peek(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void DisplayStack(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    struct node *temp = top;
    printf("\n--- Current Stack (Top to Bottom) ---\n");
    while (temp != NULL)
    {
        printf("|  %d  |\n", temp->data);
        printf("-------\n");
        temp = temp->next;
    }
    printf("   NULL\n\n");
}

int main()
{
    struct node *stackTop = NULL;

    Push(&stackTop, 10);
    Push(&stackTop, 20);
    Push(&stackTop, 30);
    Push(&stackTop, 10);
    Push(&stackTop, 20);
    Push(&stackTop, 30);

    DisplayStack(stackTop);

    printf("Top element (Peek): %d\n", Peek(stackTop));

    printf("Popped value: %d\n", Pop(&stackTop));
    printf("Popped value: %d\n", Pop(&stackTop));

    DisplayStack(stackTop);
}
