#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertElement(struct Node** front, struct Node** rear, int element);
void deleteElement(struct Node** front, struct Node** rear);
void displayQueue(struct Node* front);
void freeQueue(struct Node** front);

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, element;

    do {
        printf("\nQueue using Linked List Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertElement(&front, &rear, element);
                break;
            case 2:
                deleteElement(&front, &rear);
                break;
            case 3:
                displayQueue(front);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    freeQueue(&front);

    return 0;
}

void insertElement(struct Node** front, struct Node** rear, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Unable to insert element.\n");
        return;
    }

    newNode->data = element;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("Element %d inserted successfully.\n", element);
}

void deleteElement(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }

    struct Node* temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    printf("Element %d deleted successfully.\n", temp->data);
    free(temp);
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        while (front != NULL) {
            printf("%d ", front->data);
            front = front->next;
        }
        printf("\n");
    }
}

void freeQueue(struct Node** front) {
    while (*front != NULL) {
        struct Node* temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}
