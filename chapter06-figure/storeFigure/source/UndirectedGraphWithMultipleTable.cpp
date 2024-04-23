/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 11:16
 * @Author Kenton
 */

#include "../head/UndirectedGraphWithMultipleTable.h"

UndirectedGraphWithMultipleTable::UndirectedGraphWithMultipleTable(int numVertices) {
    // 初始化顶点数组
    vertices.resize(numVertices, nullptr);
    // 创建每个顶点结点
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = new VertexNode_MultipleTable(i);
    }
}

void UndirectedGraphWithMultipleTable::addEdge(int from, int to) {
    // 创建一条连接起点和终点的边
    EdgeNode_MultipleTable* newEdge = new EdgeNode_MultipleTable(to);
    // 将边添加到起点的边链表中
    newEdge->nextEdge = vertices[from]->firstEdge;
    vertices[from]->firstEdge = newEdge;

    // 创建一条连接终点和起点的边
    newEdge = new EdgeNode_MultipleTable(from);
    // 将边添加到终点的边链表中
    newEdge->nextEdge = vertices[to]->firstEdge;
    vertices[to]->firstEdge = newEdge;
}

void UndirectedGraphWithMultipleTable::printList() {
    std::cout << "邻接多重表：" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "顶点 " << i << " 的邻居: ";
        EdgeNode_MultipleTable* edge = vertices[i]->firstEdge;
        while (edge != nullptr) {
            std::cout << edge->vertex << " ";
            edge = edge->nextEdge;
        }
        std::cout << std::endl;
    }
}
