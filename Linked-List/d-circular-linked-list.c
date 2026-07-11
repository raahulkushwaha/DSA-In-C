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
    struct node *newNode;
    newNode = CreateNode(data);

    if (*h == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        *h = newNode;
        return;
    }

    newNode->next = *h;
    newNode->prev = (*h)->prev;

    (*h)->prev = newNode;
    newNode->prev->next = newNode;
}

void Display(struct node *h)
{
    if (h == NULL)
    {
        printf("List is Empty");
        return;
    }

    struct node *temp = h;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;

    } while (temp != h);

    printf("\n");
}

void DisplayBackward(struct node *h)
{
    if (h == NULL)
    {
        printf("List is Empty");
        return;
    }

    struct node *temp = h;
    
    printf("Backward: ");
    do
    {
        temp = temp->prev;
        printf("%d\t", temp->data);

    } while (temp != h);

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
    Display(head);
    DisplayBackward(head);
}