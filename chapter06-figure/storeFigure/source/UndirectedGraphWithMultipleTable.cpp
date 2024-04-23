/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 11:16
 * @Author Kenton
 */

#include "../head/UndirectedGraphWithMultipleTable.h"

UndirectedGraphWithMultipleTable::UndirectedGraphWithMultipleTable(int numVertices) {
    // ��ʼ����������
    vertices.resize(numVertices, nullptr);
    // ����ÿ��������
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = new VertexNode_MultipleTable(i);
    }
}

void UndirectedGraphWithMultipleTable::addEdge(int from, int to) {
    // ����һ�����������յ�ı�
    EdgeNode_MultipleTable* newEdge = new EdgeNode_MultipleTable(to);
    // ������ӵ����ı�������
    newEdge->nextEdge = vertices[from]->firstEdge;
    vertices[from]->firstEdge = newEdge;

    // ����һ�������յ�����ı�
    newEdge = new EdgeNode_MultipleTable(from);
    // ������ӵ��յ�ı�������
    newEdge->nextEdge = vertices[to]->firstEdge;
    vertices[to]->firstEdge = newEdge;
}

void UndirectedGraphWithMultipleTable::printList() {
    std::cout << "�ڽӶ��ر�" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "���� " << i << " ���ھ�: ";
        EdgeNode_MultipleTable* edge = vertices[i]->firstEdge;
        while (edge != nullptr) {
            std::cout << edge->vertex << " ";
            edge = edge->nextEdge;
        }
        std::cout << std::endl;
    }
}
