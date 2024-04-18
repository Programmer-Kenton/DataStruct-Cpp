/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 22:25
 * @Author Kenton
 */
#include "../head/DirectedGraph.h"

DirectedGraph::DirectedGraph(int numVertices) : numVertices(numVertices) {
    // ��ʼ��l�ڽӾ���Ϊȫ0
    adjacencyMatrix.resize(numVertices,std::vector<int>(numVertices,0));
}

void DirectedGraph::addEdge(int from, int to) {
    // ���ڽӾ����У��������ߵ���㵽�յ�Ĺ�ϵ
    adjacencyMatrix[from][to] = 1;
}

void DirectedGraph::printMatrix() {
    std::cout << "�ڽӾ���" << std::endl;
    // �����ڽӾ������ÿ��Ԫ��
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
