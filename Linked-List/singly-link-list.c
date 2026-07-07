#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
}; 

void InsertAtLast(struct node **start, int data)
{
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = data;
    newNode->next = NULL;

    if (*start == NULL)
    { 
        *start = newNode;
    }
    else
    {
        temp = *start;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void DeleteFromStart(struct node **s)
{

    if (*s == NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *temp;
    temp = *s;
    *s = temp->next;
    free(temp);
}

void FreeList(struct node **s)
{
    struct node *curr, *nextNode;
    curr = *s;
    while (curr)
    {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    *s = NULL;
}

void DeleteByValue(struct node **s, int target)
{   struct node *curr, *prev = NULL;
    curr = *s;

    if (curr->item == target)
    {
        *s = curr->next;
        return;
    }
    
    while (curr)
    {
        if (curr->item == target)
        {
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    printf("Value %d not found in the list.\n", target);
}

void ReverseList(struct node **s){
    if (*s == NULL || (*s)->next == NULL)
    {
        return;
    }
    
    struct node *prev = NULL;
    struct node *curr = *s;
    struct node *nextNode = NULL;
    
    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    *s = prev;
}

void Display(struct node *s)
{
    struct node *temp = s;
    printf("\n");
    while (temp)
    {
        printf("%d\t", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *start = NULL;
    InsertAtLast(&start, 20);
    InsertAtLast(&start, 50);
    InsertAtLast(&start, 50);
    InsertAtLast(&start, 40);
    InsertAtLast(&start, 60);
    Display(start);
    DeleteByValue(&start,60);
    Display(start);
    ReverseList(&start);
    Display(start);
}
