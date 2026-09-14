#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

Node* append(Node *head, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    if(head == NULL) {
        newNode->prev = NULL;

        return newNode;
    }

    Node *current = head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

Node* prepend(Node *head, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;

    if(head == NULL) {
        newNode->next = NULL;

        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

void printForward(Node *head) {
    if(head == NULL) {
        printf("No Data");
        return;
    }

    Node *current = head;
    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void printBackward(Node *head) {
    if(head == NULL) {
        printf("No Data");
        return;
    }

    Node *current = head;
    while(current->next != NULL) {
        current = current->next;
    }

    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->prev;
    }
}

Node* deleteList(Node *head, int value) {
    if(head == NULL) {
        return NULL;
    }

    Node *current = head;

    while(current != NULL) {
        if(current->value == value) break;
        current = current->next;
    }

    if(current == NULL) return head;

    if(current->prev == NULL) {
        head = current->next;
        if(head == NULL) return NULL;
        head->prev = NULL;
        free(current);
        return head;
    }

    if(current->next == NULL) {
        current->prev->next = NULL;
        
        return head;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return head;
}

void freeList(Node *head) {
    if(head == NULL) return;
    
    Node *current = head;

    while(current != NULL) {
        Node *toDelete = current;
        current = current->next;
        free(toDelete);
    }

    return;
}

int main() {
    Node *list = NULL;

    list = append(list, 10);
    list = append(list, 20);
    list = append(list, 30);
    list = prepend(list, 5);

    printf("Forward: ");
    printForward(list);    // expect: 5 10 20 30

    printf("Backward: ");
    printBackward(list);   // expect: 30 20 10 5

    list = deleteList(list, 20);   // delete a middle node
    printf("After deleting 20 (forward): ");
    printForward(list);    // expect: 5 10 30

    list = deleteList(list, 5);    // delete the head
    printf("After deleting 5 (forward): ");
    printForward(list);    // expect: 10 30

    list = deleteList(list, 30);   // delete the tail
    printf("After deleting 30 (forward): ");
    printForward(list);    // expect: 10

    list = deleteList(list, 99);   // value not in list — should be a no-op
    printf("After deleting 99 (forward): ");
    printForward(list);    // expect: 10 (unchanged)

    freeList(list);
    return 0;
}