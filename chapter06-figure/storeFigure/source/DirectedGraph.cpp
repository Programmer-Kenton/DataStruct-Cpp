/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 22:25
 * @Author Kenton
 */
#include "../head/DirectedGraph.h"

DirectedGraph::DirectedGraph(int numVertices) : numVertices(numVertices) {
    // 初始化l邻接矩阵为全0
    adjacencyMatrix.resize(numVertices,std::vector<int>(numVertices,0));
}

void DirectedGraph::addEdge(int from, int to) {
    // 在邻接矩阵中，标记有向边的起点到终点的关系
    adjacencyMatrix[from][to] = 1;
}

void DirectedGraph::printMatrix() {
    std::cout << "邻接矩阵：" << std::endl;
    // 遍历邻接矩阵并输出每个元素
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
