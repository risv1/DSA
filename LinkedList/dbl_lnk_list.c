#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct DoublyLinkedList {
    struct Node* head;
};

struct DoublyLinkedList* initList() {
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    list->head = NULL;
    return list;
}

struct Node* search(struct DoublyLinkedList* list, int data) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insert(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void delete(struct DoublyLinkedList* list, int data) {
    struct Node* nodeToDelete = search(list, data);
    if (nodeToDelete == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        list->head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    free(nodeToDelete);
}

struct Node* findNext(struct DoublyLinkedList* list, int data) {
    struct Node* currentNode = search(list, data);
    if (currentNode != NULL) {
        return currentNode->next;
    }
    return NULL;
}

struct Node* findPrevious(struct DoublyLinkedList* list, int data) {
    struct Node* currentNode = search(list, data);
    if (currentNode != NULL) {
        return currentNode->prev;
    }
    return NULL;
}

void printList(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Search for an element\n");
    printf("4. Find the next element\n");
    printf("5. Find the previous element\n");
    printf("6. Print the list\n");
    printf("7. Exit\n");
}

int main() {
    struct DoublyLinkedList* list = initList();
    int choice, data;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(list, data);
                printf("Element %d inserted.\n", data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete(list, data);
                printf("Element %d deleted.\n", data);
                break;
            case 3:
                printf("Enter the element to search for: ");
                scanf("%d", &data);
                if (search(list, data) != NULL) {
                    printf("Element %d found in the list.\n", data);
                } else {
                    printf("Element %d not found in the list.\n", data);
                }
                break;
            case 4:
                printf("Enter the element to find the next element for: ");
                scanf("%d", &data);
                struct Node* next = findNext(list, data);
                if (next != NULL) {
                    printf("Next element: %d\n", next->data);
                } else {
                    printf("No next element found.\n");
                }
                break;
            case 5:
                printf("Enter the element to find the previous element for: ");
                scanf("%d", &data);
                struct Node* prev = findPrevious(list, data);
                if (prev != NULL) {
                    printf("Previous element: %d\n", prev->data);
                } else {
                    printf("No previous element found.\n");
                }
                break;
            case 6:
                printf("Current list: ");
                printList(list);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
