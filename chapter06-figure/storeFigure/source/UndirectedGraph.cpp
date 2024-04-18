/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 22:14
 * @Author Kenton
 */
#include "../head/UndirectedGraph.h"

UndirectedGraph::UndirectedGraph(int numVertices) : numVertices(numVertices){
    // ��ʼ���ڽӾ���ȫΪ0
    adjacencyMatrix.resize(numVertices,std::vector<int>(numVertices,0));
}

void UndirectedGraph::addEdge(int from, int to) {
    // ����������ͼ��������Ҫͬʱ����������佨���ߵĹ�ϵ
    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;
}

void UndirectedGraph::printMatrix() {
    std::cout << "�ڽӾ���:" << std::endl;
    // �����ڽӾ������ÿ��Ԫ��
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
