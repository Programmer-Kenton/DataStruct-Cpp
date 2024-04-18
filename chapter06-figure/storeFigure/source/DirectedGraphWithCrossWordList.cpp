/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 10:01
 * @Author Kenton
 */
#include "../head/DirectedGraphWithCrossWordList.h"

EdgeNode::EdgeNode(int endVertex) : endVertex(endVertex), nextEdge(nullptr) {

}

VertexNode::VertexNode(int vertex) : vertex(vertex), firstEdge(nullptr), firstReverseEdge(nullptr){

}

DirectedGraphWithCrossWordList::DirectedGraphWithCrossWordList(int numVertices) {
    // ��ʼ����������
    vertices.resize(numVertices, nullptr);
    // ����ÿ��������
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = new VertexNode(i);
    }
}

void DirectedGraphWithCrossWordList::addEdge(int from, int to) {
    // ����һ������㵽�յ�ı�
    EdgeNode* newEdge = new EdgeNode(to);
    // ������ӵ����ı�������
    newEdge->nextEdge = vertices[from]->firstEdge;
    vertices[from]->firstEdge = newEdge;

    // ����һ�����յ㵽���ķ����
    EdgeNode* newReverseEdge = new EdgeNode(from);
    // ���������ӵ��յ�ķ����������
    newReverseEdge->nextEdge = vertices[to]->firstReverseEdge;
    vertices[to]->firstReverseEdge = newReverseEdge;
}

void DirectedGraphWithCrossWordList::printList() {
    std::cout << "����ĳ��ߣ�" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "���� " << i << " �ĳ���: ";
        EdgeNode* edge = vertices[i]->firstEdge;
        while (edge != nullptr) {
            std::cout << edge->endVertex << " ";
            edge = edge->nextEdge;
        }
        std::cout << std::endl;
    }

    std::cout << "�������ߣ�" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "���� " << i << " �����: ";
        EdgeNode* reverseEdge = vertices[i]->firstReverseEdge;
        while (reverseEdge != nullptr) {
            std::cout << reverseEdge->endVertex << " ";
            reverseEdge = reverseEdge->nextEdge;
        }
        std::cout << std::endl;
    }
}
