#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *back;
} Queue;

void enqueue(Queue *q, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;

    if(q->front == NULL) {
        q->front = newNode;
        q->back = newNode;
        newNode->next = NULL;
        
        return;
    }

    newNode->next = NULL;
    q->back->next = newNode;
    q->back = newNode;

    return;
}

int dequeue(Queue *q) {
    if(q->front == NULL) {
        return 0;
    }

    int value = q->front->value;

    if(q->front == q->back) {
        free(q->front); //or back, it is the same
        q->front = NULL;
        q->back = NULL;

        return value;
    }

    Node *onDelete = q->front;

    q->front = onDelete->next;

    free(onDelete);

    return value;
}

int main() {
    Queue q;
    q.front = NULL;
    q.back = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // printQueue(&q);   // uncomment once written — expect: 10 20 30

    int value;

    value = dequeue(&q);
    printf("Dequeued: %d\n", value);   // expect: 10

    value = dequeue(&q);
    printf("Dequeued: %d\n", value);   // expect: 20

    value = dequeue(&q);
    printf("Dequeued: %d\n", value);   // expect: 30 (also empties the queue — front/back both NULL now)

    value = dequeue(&q);   // dequeuing an empty queue
    printf("Dequeued from empty: %d\n", value);   // expect: 0 (your sentinel)

    return 0;
}