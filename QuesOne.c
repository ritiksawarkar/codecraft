#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, int item) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = item;
    }
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return -1; // Indicating stack is empty
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(Stack* s, int item) {
    if (isEmpty(s)) {
        push(s, item);
    } else {
        int top = pop(s);
        insertAtBottom(s, item);
        push(s, top);
    }
}

// Function to reverse the stack
void reverseStack(Stack* s) {
    if (!isEmpty(s)) {
        int top = pop(s);
        reverseStack(s);
        insertAtBottom(s, top);
    }
}

// Function to print the stack
void printStack(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    // Example elements
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Original stack: ");
    printStack(&s);

    reverseStack(&s);

    printf("Reversed stack: ");
    printStack(&s);

    return 0;
}