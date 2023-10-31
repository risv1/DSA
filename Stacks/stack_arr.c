#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 100 // Define a maximum size for the stack
 
int stack[MAX_SIZE]; // Array to store the stack elements
int top = -1; // Initialize top to -1 to indicate an empty stack
int stackSize = 0; // Initialize stackSize to 0
 
void push() {
    int val;
 
    if (top == stackSize - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("Item pushed");
    }
}
 
void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        printf("Item popped: %d\n", stack[top--]);
    }
}
 
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
 
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}
 
int isFull() {
    return top == stackSize - 1;
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
                if (!isFull()) {
                    push();
                } else {
                    printf("Stack is full. Cannot push.\n");
                }
                break;
            }
            case 2: {
                pop();
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