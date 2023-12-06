#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* createDoubleList(int values[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct Node* head = createNode(values[0]);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = createNode(values[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (!head) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (!head) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        return insertAtBeginning(head, value);
    }

    struct Node* newNode = createNode(value);
    struct Node* current = head;

    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (!current) {
        printf("Position out of bounds.\n");
        return head;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    free(head);

    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    return newHead;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    }

    free(current);

    return head;
}

struct Node* deleteFromPosition(struct Node* head, int position) {
    if (!head || position <= 0) {
        printf("Invalid position or list is empty.\n");
        return head;
    }

    if (position == 1) {
        return deleteFromBeginning(head);
    }

    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (!current) {
        printf("Position out of bounds.\n");
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);

    return head;
}

struct Node* reverseList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nOptions:\n");
        printf("1: Create a list containing 8 values/nodes\n");
        printf("2: Display the list\n");
        printf("3: Add/Insert a node at the beginning\n");
        printf("4: Add/Insert a node at the end\n");
        printf("5: Add/Insert node at a particular position/location\n");
        printf("6: Delete a node from the beginning\n");
        printf("7: Delete a node from the end\n");
        printf("8: Delete a node from a particular position/location\n");
        printf("9: Reverse the list\n");
        printf("10: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!head) {
                    printf("Enter 8 values to create the list: ");
                    int values[8];
                    for (int i = 0; i < 8; i++) {
                        scanf("%d", &values[i]);
                    }
                    head = createDoubleList(values, 8);
                    printf("List created successfully.\n");
                } else {
                    printf("List already exists. Please choose another option.\n");
                }
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                break;

            case 6:
                head = deleteFromBeginning(head);
                break;

            case 7:
                head = deleteFromEnd(head);
                break;

            case 8:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;

            case 9:
                head = reverseList(head);
                printf("List reversed successfully.\n");
                break;

            case 10:
                freeList(head);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 10);

    return 0;
}
