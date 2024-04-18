/**
 * @Description TODO C++实现无向图的邻接表法
 * @Version 1.0.0
 * @Date 2024/4/18 9:25
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_UNDIRECTEDGRAPHWITHLIST_H
#define INC_08WANGDAO_UNDIRECTEDGRAPHWITHLIST_H

#include <iostream>
#include <vector>
#include <list>

class UndirectedGraphWithList {
private:
    // 图的顶点数量
    int numVertices;
    // 邻接表 表示图的边
    std::vector<std::list<int>> adjacencyList;

public:
    // 构造函数，初始化图的顶点数量
    UndirectedGraphWithList(int numVertices);

    // 添加无向边
    void addEdge(int from, int to);

    // 打印邻接表
    void printList();
};


#endif //INC_08WANGDAO_UNDIRECTEDGRAPHWITHLIST_H
