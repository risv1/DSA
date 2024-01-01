#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int val;
    struct node *next;
};
 
struct node *head = NULL; // Initialize the head to NULL
int stackSize = 0; // Initialize stackSize to 0
 
 
void push() {
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
 
    if (ptr == NULL) {
        printf("Error");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        ptr->val = val;
        ptr->next = head;
 
        head = ptr;
        printf("Item pushed");
    }
}
 
void pop() {
    int item;
    struct node *ptr;
 
    if (head == NULL) {
        printf("Underflow");
    } else {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");
    }
}
 
void display() {
    struct node *ptr = head;
 
    if (ptr == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}
 
void peek() {
    if (head == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", head->val);
    }
}
 
int main() {
    int choice = 0;
 
    printf("Enter the size of the stack: ");
    scanf("%d", &stackSize);
 
    while (choice != 5) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: {
                if (stackSize > 0) {
                    push();
                    stackSize--;
                } else {
                    printf("Stack is full. Cannot push.\n");
                }
                break;
            }
            case 2: {
                pop();
                stackSize++;
                break;
            }
            case 3: {
                peek();
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                printf("Exit");
                break;
            }
            default: {
                printf("Invalid");
            }
        }
    }
 
    return 0;
}