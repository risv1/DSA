#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAX_NODES 100
 
int tree[MAX_NODES];
 
// Initialize the tree
void initTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = -1; // Initialize all elements to -1 (indicating empty)
    }
}
 
// Create a new node
void createNode(int value, int index) {
    tree[index] = value;
}
 
// Insert on the left of the node
void insertLeft(int parentIndex, int value) {
    int leftChildIndex = parentIndex * 2 + 1;
    createNode(value, leftChildIndex);
}
 
// Insert on the right of the node
void insertRight(int parentIndex, int value) {
    int rightChildIndex = parentIndex * 2 + 2;
    createNode(value, rightChildIndex);
}
 
// Inorder traversal
void inorderTraversal(int index) {
    if (tree[index] == -1) {
        return;
    }
    inorderTraversal(2 * index + 1); // Left child
    printf("%d -> ", tree[index]);
    inorderTraversal(2 * index + 2); // Right child
}
 
// Preorder traversal
void preorderTraversal(int index) {
    if (tree[index] == -1) {
        return;
    }
    printf("%d -> ", tree[index]);
    preorderTraversal(2 * index + 1); // Left child
    preorderTraversal(2 * index + 2); // Right child
}
 
// Postorder traversal
void postorderTraversal(int index) {
    if (tree[index] == -1) {
        return;
    }
    postorderTraversal(2 * index + 1); // Left child
    postorderTraversal(2 * index + 2); // Right child
    printf("%d -> ", tree[index]);
}
 
// Search for a value in the tree
bool search(int value, int index) {
    if (tree[index] == -1) {
        return false;
    }
    if (tree[index] == value) {
        return true;
    }
    return search(value, 2 * index + 1) || search(value, 2 * index + 2);
}
 
 
int main() {
    initTree();
 
    printf("Enter the root node value: ");
    int rootValue;
    scanf("%d", &rootValue);
    createNode(rootValue, 0);
 
    int choice;
    do {
        printf("\nBinary Tree Menu:\n");
        printf("1. Insert Left Child\n");
        printf("2. Insert Right Child\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter the parent node index: ");
                int parentIndex, leftValue;
                scanf("%d", &parentIndex);
                printf("Enter the value to insert on the left: ");
                scanf("%d", &leftValue);
                insertLeft(parentIndex, leftValue);
                break;
            case 2:
                printf("Enter the parent node index: ");
                int rightValue;
                scanf("%d", &parentIndex);
                printf("Enter the value to insert on the right: ");
                scanf("%d", &rightValue);
                insertRight(parentIndex, rightValue);
                break;
            case 3:
                printf("Enter the value to search: ");
                int searchValue;
                scanf("%d", &searchValue);
                if (search(searchValue, 0)) {
                    printf("%d found in the tree.\n", searchValue);
                } else {
                    printf("%d not found in the tree.\n", searchValue);
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(0);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorderTraversal(0);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorderTraversal(0);
                printf("\n");
                break;
            case 7:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
 
    return 0;
}
