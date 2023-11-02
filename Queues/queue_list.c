#include <stdio.h>
#include <stdlib.h>
 
// Structure for storing queue data
struct node {
    int data;
    struct node *next;
};
 
struct node *front = NULL;
struct node *rear = NULL;
 
int queueSize = 0; // Initialize the queue size to 0
 
void displayQueue() {
    struct node *current = front;
    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }
 
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}
 
void enqueue(int data) {
    if (queueSize > 0) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Queue is full. Cannot enqueue.\n");
            return;
        }
        newNode->data = data;
        newNode->next = NULL;
 
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
 
        queueSize--;
        printf("Enqueued Successfully\n");
        displayQueue();
    } else {
        printf("Queue is full. Cannot enqueue.\n");
    }
}
 
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
 
    struct node *temp = front;
    int dequeued = temp->data;
 
    front = front->next;
    free(temp);
 
    if (front == NULL) {
        rear = NULL;
    }
 
    queueSize++;
    displayQueue();
    return dequeued;
}
 
int main() {
    int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
 
    printf("\nEnter the size of the queue: ");
    scanf("%d", &queueSize);
 
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            printf("Dequeued element is: %d\n", dequeue());
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