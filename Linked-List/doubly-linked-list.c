#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *CreateNode(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void InsertAtEnd(struct node **h, int data)
{
    struct node *newNode, *temp;
    newNode = CreateNode(data);

    if (*h == NULL)
    {
        *h = newNode;
        return;
    }

    temp = *h;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void InsertAtStart(struct node **h, int data)
{
    struct node *newNode;
    newNode = CreateNode(data);

    if (*h == NULL)
    {
        *h = newNode;
        return;
    }

    newNode->next = *h;
    (*h)->prev = newNode;
    *h = newNode;
}

void InsertAfterData(struct node **h, int data, int positionData)
{
    struct node *newNode, *temp;

    temp = *h;
    while (temp->next)
    {
        if (temp->data == positionData)
            break;
        else
            temp = temp->next;
    }

    newNode = CreateNode(data);
    newNode->next = temp->next;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void Display(struct node *h)
{
    if (h == NULL)
    {
        printf("List is Empty");
        return;
    }

    struct node *temp = h;
    while (temp)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void DisplayBackward(struct node *h)
{
    if (h == NULL)
    {
        printf("List is Null");
        return;
    }

    struct node *temp = h;
    while (temp->next)
    {
        temp = temp->next;
    }

    printf("Backward: ");
    while (temp)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    InsertAtEnd(&head, 10);
    InsertAtEnd(&head, 20);
    InsertAtEnd(&head, 30);
    InsertAtEnd(&head, 40);
    InsertAtEnd(&head, 50);
    // InsertAtStart(&head, 90);
    InsertAfterData(&head, 90, 50);
    Display(head);
    DisplayBackward(head);
}
