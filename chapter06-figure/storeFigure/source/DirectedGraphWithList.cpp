/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 9:32
 * @Author Kenton
 */

#include "../head/DirectedGraphWithList.h"

DirectedGraphWithList::DirectedGraphWithList(int numVertices) : numVertices(numVertices) {
    // ��ʼ���ڽӱ�
    adjacencyList.resize(numVertices);
}

void DirectedGraphWithList::addEdge(int from, int to) {
    // �������ڽӱ�������յ�
    adjacencyList[from].push_back(to);
}

void DirectedGraphWithList::printList() {
    std::cout << "�ڽӱ�" << std::endl;
    // �����ڽӱ����ÿ��������ھ�
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "���� " << i << " ���ھ�: ";
        for (auto neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}
