#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define the structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to perform enqueue operation
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued: %d\n", data);
}

// Function to perform dequeue operation
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1; // Return a sentinel value for underflow
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        // Only one element in the queue
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

// Function to traverse and print elements of the queue
void traverseQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    struct QueueNode* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse the elements of the queue using recursion
void reverseQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }

    int data = dequeue(queue);
    reverseQueue(queue);
    enqueue(queue, data);
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    traverseQueue(&myQueue);

    int dequeuedElement = dequeue(&myQueue);
    if (dequeuedElement != -1) {
        printf("Dequeued: %d\n", dequeuedElement);
    }

    traverseQueue(&myQueue);

    // Trying to dequeue from an empty queue (underflow)
    dequeue(&myQueue);

    // Reverse the elements of the queue
    reverseQueue(&myQueue);

    printf("Queue after reversal:\n");
    traverseQueue(&myQueue);

    return 0;
}
