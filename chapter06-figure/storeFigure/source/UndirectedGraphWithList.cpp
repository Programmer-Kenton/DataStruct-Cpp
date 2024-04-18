/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 9:25
 * @Author Kenton
 */
#include "../head/UndirectedGraphWithList.h"

UndirectedGraphWithList::UndirectedGraphWithList(int numVertices) : numVertices(numVertices){
    // ��ʼ���ڽӱ�
    adjacencyList.resize(numVertices);
}

void UndirectedGraphWithList::addEdge(int from, int to) {
    // ����������ͼ��������Ҫ�������յ���ڽӱ��зֱ���Ӷ�Ӧ�Ķ���
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from);
}

void UndirectedGraphWithList::printList() {
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
