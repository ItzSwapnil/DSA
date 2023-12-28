/*
12) WAP to implement a linear queue using array and perform the following: 1:
insertion element, 2: delete an element, 3: display the queue, 4: exit. You can take
user input based on the given choices
*/

#include <stdio.h>

#define MAX_SIZE 10

void insertElement(int queue[], int *rear, int element);
void deleteElement(int queue[], int *front, int *rear);
void displayQueue(int queue[], int front, int rear);

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;
    int choice, element;

    do {
        printf("\nLinear Queue Menu:\n");
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
                insertElement(queue, &rear, element);
                break;
            case 2:
                deleteElement(queue, &front, &rear);
                break;
            case 3:
                displayQueue(queue, front, rear);
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

void insertElement(int queue[], int *rear, int element) {
    if (*rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        (*rear)++;
        queue[*rear] = element;
        printf("Element %d inserted successfully.\n", element);
    }
}

void deleteElement(int queue[], int *front, int *rear) {
    if (*front == *rear) {
        printf("Queue is empty. Cannot delete element.\n");
    } else {
        (*front)++;
        printf("Element %d deleted successfully.\n", queue[*front]);
    }
}

void displayQueue(int queue[], int front, int rear) {
    if (front == rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front + 1; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
