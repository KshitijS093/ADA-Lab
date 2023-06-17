#include <stdio.h>

#define MAX_VERTICES 100


typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}


typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int source, int destination) {
    g->adjMatrix[source][destination] = 1;
}

void displayAdjMatrix(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void bfs(Graph* g, int startNode) {
    int visited[MAX_VERTICES] = { 0 };
    Queue q;
    initQueue(&q);

    visited[startNode] = 1;
    enqueue(&q, startNode);

    printf("BFS traversal starting from node %d: ", startNode);

    while (!isEmpty(&q)) {
        int currentNode = dequeue(&q);
        printf("%d ", currentNode);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}


void dfsUtil(Graph* g, int node, int visited[]) {
    visited[node] = 1;

    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[node][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}


int dfs(Graph* g, int startNode) {
    int visited[MAX_VERTICES] = { 0 };
    dfsUtil(g, startNode, visited);

    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Graph g;
    int vertices, edges, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&g, source, destination);
    }

    displayAdjMatrix(&g);

    printf("Enter the starting node for BFS and DFS: ");
    scanf("%d", &source);

    bfs(&g, source);

    int connected = dfs(&g, source);
    if (connected) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
