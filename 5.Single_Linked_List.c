#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addAtBeginning(struct Node **head, int data) {
    struct Node *newNodeToAdd = newNode(data);
    newNodeToAdd->next = *head;
    *head = newNodeToAdd;
}

void addAtEnd(struct Node **head, int data) {
    struct Node *newNodeToAdd = newNode(data);
    struct Node *temp = *head;
    if (*head == NULL) {
        *head = newNodeToAdd;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNodeToAdd;
}

struct Node *createLinkedList(int values[], int length) {
    struct Node *head = NULL;
    for (int i = 0; i < length; i++) {
        addAtEnd(&head, values[i]);
    }
    return head;
}

void addAtPosition(struct Node **head, int data, int position) {
    if (position == 0) {
        addAtBeginning(head, data);
        return;
    }
    struct Node *newNodeToAdd = newNode(data);
    struct Node *temp = *head;
    int i = 0;
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (i == position - 1) {
        newNodeToAdd->next = temp->next;
        temp->next = newNodeToAdd;
    }
}

void inputEightValues(struct Node **head) {
    int data;
    printf("Enter 8 values:\n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &data);
        addAtEnd(head, data);
    }
}

void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        return;
    }
    struct Node *temp = *head;
    if ((*head)->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(struct Node **head, int position) {
    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }
    struct Node *temp = *head;
    int i = 0;
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (i == position - 1) {
        struct Node *nextNode = temp->next->next;
        free(temp->next);
        temp->next = nextNode;
    }
}

void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    *head = prev;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data, position;
    do {
        printf("Enter your choice: \n");
        printf("1. Create a list containing 8 values/nodes\n");
        printf("2. Display the list\n");
        printf("3. Add/insert a node at the beginning\n");
        printf("4. Add/insert a node at the end\n");
        printf("5. Add/insert node at a particular position/location\n");
        printf("6. Delete a node from the beginning\n");
        printf("7. Delete a node from the end\n");
        printf("8. Delete a node from a particular position/location\n");
        printf("9. Reverse the list\n");
        printf("10. Exit\n");
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
                    head = createLinkedList(values, 8);
                    printf("List created successfully.\n");
                } else {
                    printf("List already exists. Please choose another option.\n");
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                addAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                addAtEnd(&head, data);
                break;
            case 5:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the position for adding the node: ");
                scanf("%d", &position);
                addAtPosition(&head, data, position);
                break;
            case 6:
                deleteFromBeginning(&head);
                break;
            case 7:
                deleteFromEnd(&head);
                break;
            case 8:
                printf("Enter the position for deleting the node: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 9:
                reverse(&head);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 10);
    return 0;
}
