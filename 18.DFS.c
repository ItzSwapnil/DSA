/*
18) WAP to implement Depth First Search.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void dfsUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            dfsUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int startVertex) {
    int visited[graph->vertices];
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    printf("Depth-First Search starting from vertex %d: ", startVertex);
    struct Stack* stack = createStack(graph->vertices);
    push(stack, startVertex);

    while (!isStackEmpty(stack)) {
        int currentVertex = pop(stack);
        if (!visited[currentVertex]) {
            dfsUtil(graph, currentVertex, visited);
        }
    }

    printf("\n");
}

int main() {
    int n, e; // n = number of vertices, e = number of edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < e; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        struct Node* newNode = createNode(dest);
        newNode->next = graph->adjacencyList[src];
        graph->adjacencyList[src] = newNode;
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    dfs(graph, startVertex);

    return 0;
}
