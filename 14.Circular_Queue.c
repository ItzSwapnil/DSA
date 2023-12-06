#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Node {
    int data;
    struct Node* next;
};

void insertElement(struct Node** rear, int element);
void deleteElement(struct Node** front, struct Node** rear);
void displayQueue(struct Node* front, struct Node* rear);

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, element;

    do {
        printf("\nCircular Queue Menu:\n");
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
                insertElement(&rear, element);
                break;
            case 2:
                deleteElement(&front, &rear);
                break;
            case 3:
                displayQueue(front, rear);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

void insertElement(struct Node** rear, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Unable to insert element.\n");
        return;
    }

    newNode->data = element;
    newNode->next = NULL;

    if (*rear == NULL) {
        *rear = newNode;
        (*rear)->next = *rear;
    } else {
        newNode->next = (*rear)->next;
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

    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
        (*rear)->next = *front;
    }

    printf("Element %d deleted successfully.\n", temp->data);
    free(temp);
}

void displayQueue(struct Node* front, struct Node* rear) {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = front;

        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != front);

        printf("\n");
    }
}
