/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 9:25
 * @Author Kenton
 */
#include "../head/UndirectedGraphWithList.h"

UndirectedGraphWithList::UndirectedGraphWithList(int numVertices) : numVertices(numVertices){
    // 初始化邻接表
    adjacencyList.resize(numVertices);
}

void UndirectedGraphWithList::addEdge(int from, int to) {
    // 由于是无向图，所以需要在起点和终点的邻接表中分别添加对应的顶点
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from);
}

void UndirectedGraphWithList::printList() {
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
