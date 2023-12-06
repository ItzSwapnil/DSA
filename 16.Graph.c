#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d: ", i);
        struct Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
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
        addEdge(graph, src, dest);
    }

    printf("\nGraph Information:\n");
    printGraph(graph);

    free(graph);
    return 0;
}



/*
       OUTPUT
Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (src dest):
0 1
0 2
1 3
3 4

Graph Information:
Vertex 0: 2 -> 1 -> NULL
Vertex 1: 3 -> 0 -> NULL
Vertex 2: 0 -> NULL
Vertex 3: 4 -> 1 -> NULL
Vertex 4: 3 -> NULL

*/
