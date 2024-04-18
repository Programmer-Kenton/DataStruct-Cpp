/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 20:46
 * @Author Kenton
 */

#include "../head/adjacencyMatrix.h"

int main(){
    int vertices = 5;
    adjacencyMatrix graph(vertices);

    graph.addEdge(0,1,1);
    graph.addEdge(0,2,3);
    graph.addEdge(1,2,2);
    graph.addEdge(2,3,7);
    graph.addEdge(3,4,9);
    graph.addEdge(4,0,4);
    graph.addEdge(4,2,5);

    graph.printGraph();
}