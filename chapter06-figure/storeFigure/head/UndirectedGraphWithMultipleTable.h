/**
 * @Description TODO C++邻接多重表存储无向图
 * @Version 1.0.0
 * @Date 2024/4/18 11:16
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_UNDIRECTEDGRAPHWITHMULTIPLETABLE_H
#define INC_08WANGDAO_UNDIRECTEDGRAPHWITHMULTIPLETABLE_H

#include <iostream>
#include <vector>

// 边结点
struct EdgeNode_MultipleTable {
    // 与当前顶点相邻的顶点
    int vertex;
    // 指向下一条与当前顶点相邻的边的指针
    EdgeNode_MultipleTable* nextEdge;
    // 边是否已被访问
    bool visited;

    EdgeNode_MultipleTable(int vertex) : vertex(vertex), nextEdge(nullptr), visited(false) {}
};


// 顶点结点
struct VertexNode_MultipleTable {
    // 顶点编号
    int vertex;
    // 指向第一条与该顶点相邻的边的指针
    EdgeNode_MultipleTable* firstEdge;

    VertexNode_MultipleTable(int vertex) : vertex(vertex), firstEdge(nullptr) {}
};

class UndirectedGraphWithMultipleTable {
private:
    // 图的顶点数量
    int numVertices;
    // 存储顶点的数组
    std::vector<VertexNode_MultipleTable*> vertices;

public:
    // 构造函数，初始化图的顶点数量
    UndirectedGraphWithMultipleTable(int numVertices);

    // 添加无向边
    void addEdge(int from, int to);

    // 打印邻接多重表
    void printList();
};


#endif //INC_08WANGDAO_UNDIRECTEDGRAPHWITHMULTIPLETABLE_H
