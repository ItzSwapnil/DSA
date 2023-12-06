#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    int size;
    int capacity;
};

void initialize(struct Stack* stack, int capacity) {
    stack->top = NULL;
    stack->size = 0;
    stack->capacity = capacity;
}

int isFull(struct Stack* stack) {
    return stack->size == stack->capacity;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d\n", value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("%d pushed to the stack\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack\n");
        return -1;
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;

    return poppedValue;
}

int main() {
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    struct Stack stack;
    initialize(&stack, capacity);

    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
            case 2:
                printf("%d popped from the stack\n", pop(&stack));
            break;
            case 3:
                printf("Exiting program\n");
            break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3\n");
        }
    } while (choice != 3);

    return 0;
}
