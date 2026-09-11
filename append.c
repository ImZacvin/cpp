#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* append(Node *head, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    Node *current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;

    return head;
}

Node* prepend(Node *head, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = head;

    return newNode;
}

int search(Node *head, int target) {
    Node *current = head;
    while(current != NULL) {
        if(current->value == target) return 1;
        current = current->next;
    }

    return 0;
}

Node* deleteValue(Node *head, int value) {
    if(head == NULL) {
        return NULL;
    }
    if(head->value == value) {
        Node *newNode = head->next;
        free(head);
        return newNode;
    }
    
    Node *current = head;
    while(current->next != NULL) {
        if(current->next->value == value) {
            Node *toDelete = current->next;
            current->next = toDelete->next;
            free(toDelete);
            return head;
        }

        current = current->next;
    }

    return head;
}

int main() {
    Node *first = malloc(sizeof(Node));
    first->value = 10;
    first->next = NULL;

    first = append(first, 20);
    first = append(first, 30);

    Node *current = first;

    while(current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}