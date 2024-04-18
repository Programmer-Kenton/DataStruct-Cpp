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
    // 初始化顶点数组
    vertices.resize(numVertices, nullptr);
    // 创建每个顶点结点
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = new VertexNode(i);
    }
}

void DirectedGraphWithCrossWordList::addEdge(int from, int to) {
    // 创建一条从起点到终点的边
    EdgeNode* newEdge = new EdgeNode(to);
    // 将边添加到起点的边链表中
    newEdge->nextEdge = vertices[from]->firstEdge;
    vertices[from]->firstEdge = newEdge;

    // 创建一条从终点到起点的反向边
    EdgeNode* newReverseEdge = new EdgeNode(from);
    // 将反向边添加到终点的反向边链表中
    newReverseEdge->nextEdge = vertices[to]->firstReverseEdge;
    vertices[to]->firstReverseEdge = newReverseEdge;
}

void DirectedGraphWithCrossWordList::printList() {
    std::cout << "顶点的出边：" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "顶点 " << i << " 的出边: ";
        EdgeNode* edge = vertices[i]->firstEdge;
        while (edge != nullptr) {
            std::cout << edge->endVertex << " ";
            edge = edge->nextEdge;
        }
        std::cout << std::endl;
    }

    std::cout << "顶点的入边：" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "顶点 " << i << " 的入边: ";
        EdgeNode* reverseEdge = vertices[i]->firstReverseEdge;
        while (reverseEdge != nullptr) {
            std::cout << reverseEdge->endVertex << " ";
            reverseEdge = reverseEdge->nextEdge;
        }
        std::cout << std::endl;
    }
}
