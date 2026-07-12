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

void Push(struct stack *s, int data)
{
    if (IsFull(s))
    {
        printf("Stack Overflow! %d cannot be pushed\n", data);
        return;
    }

    s->top++;
    s->arr[s->top] = data;
    printf("Pushed %d onto the stack\n", data);
}

int Pop(struct stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack Underflow!");
        return -1;
    }

    int popped = s->arr[s->top];
    s->top--;
    return popped;
}

int Peek(struct stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack is empty \n");
        return -1;
    }

    return s->arr[s->top];
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

    Push(&myStack, 10);
    Push(&myStack, 20);
    Push(&myStack, 30);
    Push(&myStack, 40);
    Push(&myStack, 50);
    Push(&myStack, 60);

    Display(&myStack);

    printf("Popped value: %d\n", Pop(&myStack));

    printf("Top element (Peek): %d\n", Peek(&myStack));

    Display(&myStack);
}
