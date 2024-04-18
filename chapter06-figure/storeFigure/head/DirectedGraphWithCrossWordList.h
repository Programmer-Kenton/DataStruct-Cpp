/**
 * @Description TODO C++实现十字链表存储有向图
 * @Version 1.0.0
 * @Date 2024/4/18 10:01
 * @Author Kenton
 */

#ifndef INC_08WANGDAO_DIRECTEDGRAPHWITHCROSSWORDLIST_H
#define INC_08WANGDAO_DIRECTEDGRAPHWITHCROSSWORDLIST_H

#include <iostream>
#include <vector>

// 边结点
struct EdgeNode{
    // 边的终点
    int endVertex;

    // 指向下一条边的指针
    EdgeNode* nextEdge;

    EdgeNode(int endVertex);
};

// 顶点结点
struct VertexNode{
    // 顶点编号
    int vertex;

    // 指向第一条以该顶点为起点的边的指针
    EdgeNode* firstEdge;

    // 指向第一条以该顶点为终点的边的指针
    EdgeNode* firstReverseEdge;

    VertexNode(int vertex);
};

class DirectedGraphWithCrossWordList {
private:
    // 图的顶点数量
    int numVertices;
    // 存储顶点的数组
    std::vector<VertexNode*> vertices;

public:
    // 构造函数，初始化图的顶点数量
    DirectedGraphWithCrossWordList(int numVertices);

    // 添加有向边
    void addEdge(int from, int to);

    // 打印十字链表
    void printList();
};


#endif //INC_08WANGDAO_DIRECTEDGRAPHWITHCROSSWORDLIST_H
