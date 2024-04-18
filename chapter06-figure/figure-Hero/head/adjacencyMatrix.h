/**
 * @Description 邻接矩阵
 * @Version 1.0.0
 * @Date 2024/4/17 20:46
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_ADJACENCYMATRIX_H
#define INC_08WANGDAO_ADJACENCYMATRIX_H

#define inf -1

#include "iostream"

class adjacencyMatrix {
private:
    int vertices;

    int ** edges;

public:

    adjacencyMatrix(int vertices);

    ~adjacencyMatrix();

    void addEdge(int u,int v,int w);

    void printGraph();
};


#endif //INC_08WANGDAO_ADJACENCYMATRIX_H
