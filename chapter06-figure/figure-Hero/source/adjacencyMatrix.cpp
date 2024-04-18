/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 20:46
 * @Author Kenton
 */
#include "../head/adjacencyMatrix.h"

adjacencyMatrix::adjacencyMatrix(int vertices) {
    this->vertices = vertices;
    edges = new int* [vertices];
    for (int i = 0; i < vertices; ++i) {
        edges[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j) {
            edges[i][j] = inf;
        }
    }
}

adjacencyMatrix::~adjacencyMatrix() {
    for (int i = 0; i < vertices; ++i) {
        delete[] edges[i];
    }
    delete[] edges;
}

void adjacencyMatrix::addEdge(int u, int v, int w) {
    edges[u][v] = w;
}

void adjacencyMatrix::printGraph() {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            std::cout << edges[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
