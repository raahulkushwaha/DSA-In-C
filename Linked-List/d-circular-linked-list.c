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

void InsertAtStart(struct node **h, int data)
{
    InsertAtEnd(h, data);
    *h = (*h)->prev;
}

void InsertAfterValue(struct node **h, int data, int positionData)
{
    struct node *newNode, *temp;
    temp = *h;

    do
    {
        if (temp->data == positionData)
        {
            newNode = CreateNode(data);
            newNode->next = temp->next;
            newNode->prev = temp;

            temp->next = newNode;
            newNode->next->prev = newNode;
            return;
        }
        temp = temp->next;

    } while (temp != *h);
}

void DeleteByValue(struct node **h, int value)
{
    struct node *temp = *h;

    do
    {
        if (temp->data == value)
        {
            // if only one node, head need to point to NULL
            if (temp->next == temp)
            {
                free(temp);
                *h = NULL;
                return;
            }

            if (temp == *h)
                *h = temp->next; // move ahead before deletion

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            free(temp);
            return;
        }

        temp = temp->next;

    } while (temp != *h);
}

void FreeList(struct node **h)
{
    struct node *temp, *curr, *nextNode;
    curr = *h;
    temp = *h;

    do
    {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;

    } while (curr != temp);
    
    *h = NULL;
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
    // InsertAtStart(&head, 1);
    // InsertAfterValue(&head, 60, 50);
    // DeleteByValue(&head, 10);
    FreeList(&head);
    Display(head);
    DisplayBackward(head);
}