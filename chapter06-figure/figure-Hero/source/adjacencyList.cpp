/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:57
 * @Author Kenton
 */
#include "../head/adjacencyList.h"

adjacencyList::adjacencyList(int vertices) {
    this->vertices = vertices;
    this->nodes = new VertexNode[vertices];
    for (int i = 0; i < vertices; ++i) {
        nodes[i].vertex = i;
        nodes[i].firstEdge = nullptr;
    }
}

adjacencyList::~adjacencyList() {
    for (int i = 0; i < vertices; ++i) {
        EdgeNode *curr = nodes[i].firstEdge;
        while (curr){
            EdgeNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] nodes;
}

void adjacencyList::addEdge(int u, int v, int w) {
    EdgeNode *newNode = new EdgeNode;
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = nodes[u].firstEdge;
    nodes[u].firstEdge = newNode;
}

void adjacencyList::printGraph() {
    for (int i = 0; i < vertices; ++i) {
        EdgeNode *curr = nodes[i].firstEdge;
        std::cout << "Vertex " << i << ":";
        while (curr){
            std::cout << curr->vertex << "(" << curr->weight << ")";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}
