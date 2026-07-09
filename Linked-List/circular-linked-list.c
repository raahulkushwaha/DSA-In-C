#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *CreateNode(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void InsertAtLast(struct node **h, int data)
{
    struct node *newNode, *temp;
    newNode = CreateNode(data);

    if (*h == NULL)
    {
        newNode->next = newNode;
        *h = newNode;
        return;
    }

    temp = *h;
    while (temp->next != *h)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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

int main()
{
    struct node *head = NULL;
    InsertAtLast(&head, 10);
    InsertAtLast(&head, 20);
    InsertAtLast(&head, 30);
    InsertAtLast(&head, 40);
    Display(head);
}
