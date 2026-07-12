#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct stack
{
    int arr[MAX];
    int top;
};

void Initialize(struct stack *s)
{
    s->top = -1;
}

int IsFull(struct stack *s)
{
    return s->top == MAX - 1;
}

int IsEmpty(struct stack *s)
{
    return s->top == -1;
}

void Display(struct stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("\n--- Current Stack (Top to Bottom) ---\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("|  %d  |\n", s->arr[i]);
        printf("-------\n");
    }
    printf("\n");
}

int main()
{
    struct stack myStack;
    Initialize(&myStack);
    Display(&myStack);
}
