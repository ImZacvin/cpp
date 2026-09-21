#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* push(Node *top, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    
    newNode->next = top;

    return newNode;
}

Node* pop(Node *top, int *poppedValue) {
    if(top == NULL) {
        *poppedValue = 0;
        return NULL;
    }
    
    *poppedValue = top->value;

    Node *current = top->next;
    free(top);

    return current;
}

int main() {
    Node *stack = NULL;

    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);

    printStack(stack);   // uncomment once you've written this — expect: 30 20 10

    int value;
    stack = pop(stack, &value);
    printf("Popped: %d\n", value);   // expect: 30

    stack = pop(stack, &value);
    printf("Popped: %d\n", value);   // expect: 20

    stack = pop(stack, &value);
    printf("Popped: %d\n", value);   // expect: 10

    stack = pop(stack, &value);      // popping an empty stack
    printf("Popped from empty: %d\n", value);   // expect: 0 (your sentinel)

    return 0;
}