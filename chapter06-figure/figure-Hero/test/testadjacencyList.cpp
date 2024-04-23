/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:57
 * @Author Kenton
 */

#include "../head/adjacencyList.h"

int main(){
    adjacencyList graph(5);
    graph.addEdge(0,1,4);
    graph.addEdge(0,2,2);
    graph.addEdge(1,2,3);
    graph.addEdge(2,3,4);
    graph.addEdge(3,4,2);

    graph.printGraph();
}