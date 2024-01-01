#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; 

void insertAtBeginning(int element) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = head;
    head = newNode;
    printf("Element %d inserted at the beginning.\n", element);
}

// Function to insert an element at the end of the linked list
void insertAtEnd(int element) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Element %d inserted at the end.\n", element);
}

// Function to insert an element at a specific position in the linked list
void insertAtPosition(int element, int position) {
    if (position <= 0) {
        printf("Invalid position. Element not inserted.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(element);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds. Element not inserted.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Element %d inserted at position %d.\n", element, position);
    }
}

// Function to delete an element from the linked list
void deleteElement(int element) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found. Deletion failed.\n", element);
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Element %d deleted successfully.\n", element);
    }
}

// Function to search for an element in the linked list
void searchElement(int element) {
    struct Node *temp = head;
    int position = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == element) {
            found = 1;
            printf("Element %d found at position %d.\n", element, position);
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("Element %d not found in the linked list.\n", element);
    }
}

// Function to display the linked list
void displayList() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("Linked List: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, element, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Display Linked List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtBeginning(element);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtEnd(element);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(element, position);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            case 6:
                displayList();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
