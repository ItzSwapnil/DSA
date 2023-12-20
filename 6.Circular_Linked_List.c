/*
6) WAP to create a Circular Linked List and perform the following operations: (Options:
1: create a list containing 08 values/nodes, 2:display the list, 3: add/insert a node at
the beginning, 4: add/insert a node at the end, 5: add/insert node at a particular
position/location, 6: delete a node from the beginning, 7: delete a node from the
end, 8: delete a node from a particular position/location, 9: reverse the list, 10:exit).
You can take user input based on the given choices
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularList(int values[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct Node* head = createNode(values[0]);
    struct Node* tail = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = createNode(values[i]);
        tail->next = newNode;
        tail = newNode;
    }

    tail->next = head;

    return head;
}

void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;
    return newNode;
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

    for (int i = 1; i < position - 1 && current->next != head; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head->next;

    if (temp == head) {
        free(temp);
        return NULL;
    }

    head->next = temp->next;
    free(temp);

    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = head;
        free(current);
    } else {
        free(current);
        return NULL;
    }

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
    struct Node* prev = NULL;

    for (int i = 1; i < position && current->next != head; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Position out of bounds.\n");
        return head;
    }

    prev->next = current->next;
    free(current);

    return head;
}

struct Node* reverseList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;

    return prev;
}

void freeList(struct Node* head) {
    if (!head) {
        return;
    }

    struct Node* current = head;
    struct Node* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
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
                    int values[8];
                    printf("Enter 8 values: ");
                    for (int i = 0; i < 8; i++) {
                        scanf("%d", &values[i]);
                    }
                    head = createCircularList(values, 8);
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
