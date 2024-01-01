#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int size = 0;

// Function to display the list
void displayList() {
    if (size == 0) {
        printf("The list is empty.\n");
    } else {
        printf("List elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}

// Function to insert an element at the end of the list
void insertElement(int element) {
    if (size < MAX_SIZE) {
        list[size] = element;
        size++;
        printf("Element %d inserted successfully.\n", element);
    } else {
        printf("List is full. Cannot insert element %d.\n", element);
    }
}

// Function to delete an element from the list
void deleteElement(int element) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            found = 1;
            for (int j = i; j < size - 1; j++) {
                list[j] = list[j + 1];
            }
            size--;
            printf("Element %d deleted successfully.\n", element);
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the list. Deletion failed.\n", element);
    }
}

// Function to search for an element in the list
void searchElement(int element) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            found = 1;
            printf("Element %d found at position %d.\n", element, i + 1);
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the list.\n", element);
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\nList ADT Operations:\n");
        printf("1. Display List\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList();
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(element);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
