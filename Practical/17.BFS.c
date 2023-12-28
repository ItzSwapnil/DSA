/*
17) WAP to implement Breadth First Search.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    int front, rear;
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
    struct Graph* graph = (struct Graph*)calloc(1, sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyList = (struct Node**)calloc(vertices, sizeof(struct Node*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        fprintf(stderr, "Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->array[++queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

void bfs(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue(graph->vertices);
    int visited[graph->vertices];
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("Breadth-First Search starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    int n, e;
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    free(graph);
    return 0;
}