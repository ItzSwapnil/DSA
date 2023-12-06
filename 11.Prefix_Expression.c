#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int evaluatePrefix(char expression[]) {
    int i, operand1, operand2, result;
    char symbol;

    for (i = strlen(expression) - 1; i >= 0; i--) {
        symbol = expression[i];
        if (isdigit(symbol))
            push(symbol - '0');
        else if (isOperator(symbol)) {
            operand1 = pop();
            operand2 = pop();
            switch (symbol) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
            }
        }
    }

    result = pop();
    return result;
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter the prefix expression: ");
    fgets(expression, MAX_SIZE, stdin);

    int result = evaluatePrefix(expression);
    printf("Result: %d\n", result);

    return 0;
}
