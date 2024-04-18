/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 22:14
 * @Author Kenton
 */
#include "../head/UndirectedGraph.h"

UndirectedGraph::UndirectedGraph(int numVertices) : numVertices(numVertices){
    // 初始化邻接矩阵全为0
    adjacencyMatrix.resize(numVertices,std::vector<int>(numVertices,0));
}

void UndirectedGraph::addEdge(int from, int to) {
    // 由于是无向图，所以需要同时在两个顶点间建立边的关系
    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;
}

void UndirectedGraph::printMatrix() {
    std::cout << "邻接矩阵:" << std::endl;
    // 遍历邻接矩阵并输出每个元素
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
