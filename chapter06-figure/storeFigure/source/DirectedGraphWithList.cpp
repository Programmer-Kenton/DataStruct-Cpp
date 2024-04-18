/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 9:32
 * @Author Kenton
 */

#include "../head/DirectedGraphWithList.h"

DirectedGraphWithList::DirectedGraphWithList(int numVertices) : numVertices(numVertices) {
    // 初始化邻接表
    adjacencyList.resize(numVertices);
}

void DirectedGraphWithList::addEdge(int from, int to) {
    // 在起点的邻接表中添加终点
    adjacencyList[from].push_back(to);
}

void DirectedGraphWithList::printList() {
    std::cout << "邻接表：" << std::endl;
    // 遍历邻接表并输出每个顶点的邻居
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "顶点 " << i << " 的邻居: ";
        for (auto neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}
