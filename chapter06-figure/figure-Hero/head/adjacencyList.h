/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:57
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_ADJACENCYLIST_H
#define INC_08WANGDAO_ADJACENCYLIST_H

#include "iostream"

class adjacencyList {
private:
    struct EdgeNode{
        int vertex;
        int weight;
        EdgeNode *next;
    };

    struct VertexNode{
        int vertex;
        EdgeNode *firstEdge;
    };

    int vertices;

    VertexNode *nodes;

public:
    adjacencyList(int vertices);

    ~adjacencyList();

    void addEdge(int u,int v,int w);

    void printGraph();
};


#endif //INC_08WANGDAO_ADJACENCYLIST_H
