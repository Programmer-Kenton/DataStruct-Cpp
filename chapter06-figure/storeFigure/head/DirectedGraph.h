/**
 * @Description TODO 有向图的邻接矩阵法存储
 * @Version 1.0.0
 * @Date 2024/4/17 22:25
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_DIRECTEDGRAPH_H
#define INC_08WANGDAO_DIRECTEDGRAPH_H

#include <iostream>
#include <vector>

class DirectedGraph {

private:
    // 图的顶点数量
    int numVertices;
    // 邻接矩阵表示图的边
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    // 构造函数 初始化图的顶点数量和邻接矩阵
    DirectedGraph(int numVertices);

    // 添加有向边
    void addEdge(int from, int to);

    // 打印邻接矩阵
    void printMatrix();
};


#endif //INC_08WANGDAO_DIRECTEDGRAPH_H
