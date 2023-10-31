#include <stdio.h>
#include <stdlib.h>
 
int MAX_SIZE = 100; // Define a maximum size for the queue
 
int queue[100]; // Array to store the queue elements
int front = -1; // Initialize front and rear to -1 to indicate an empty queue
int rear = -1;
int queueSize = 0; // Initialize the queue size to 0
 
int isFull() {
    return queueSize == MAX_SIZE;
}
 
int isEmpty() {
    return front == -1;
}
 
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
 
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d -> ", queue[i]);
    }
    printf("\n");
}
 
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
 
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
 
    queue[rear] = data;
    queueSize++;
    printf("Enqueued Successfully\n");
    displayQueue();
}
 
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
 
    int dequeued = queue[front];
 
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
 
    queueSize--;
    displayQueue();
    return dequeued;
}
 
int main() {
    int choice, value;
    printf("\nImplementation of Queue using Array\n");
 
    printf("\nEnter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);
 
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (!isFull()) {
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
            } else {
                printf("Queue is full. Cannot enqueue.\n");
            }
            break;
        case 2:
            if (!isEmpty()) {
                printf("Dequeued element is: %d\n", dequeue());
            } else {
                printf("Queue is empty. Cannot dequeue.\n");
            }
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}