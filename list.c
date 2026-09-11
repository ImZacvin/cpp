#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int main() {
    Node *first = malloc(sizeof(Node));
    first->value = 10;

    Node *second = malloc(sizeof(Node));
    second->value = 20;

    Node *third = malloc(sizeof(Node));
    third->value = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    Node *current = first;

    while(current != NULL) {
        printf("Value: %d\n", current->value);
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}