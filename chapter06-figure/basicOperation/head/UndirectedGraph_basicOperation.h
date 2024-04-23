/**
 * @Description TODO 带权无向图的基本操作
 * @Version 1.0.0
 * @Date 2024/4/18 17:22
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_UNDIRECTEDGRAPH_BASICOPERATION_H
#define INC_08WANGDAO_UNDIRECTEDGRAPH_BASICOPERATION_H

#include <iostream>
#include <vector>


class UndirectedGraph_basicOperation {
private:
    // 图的顶点数量
    int numVertices;
    // 邻接矩阵表示图的边
    std::vector<std::vector<int>> adjacencyMatrix;
    // 记录顶点是否存在
    std::vector<bool> vertices;

public:
    // 构造函数，初始化图的顶点数量和邻接矩阵
    UndirectedGraph_basicOperation(int numVertices);

    // 判断图是否存在边(x,y)
    bool Adjacent(int x, int y);

    // 列出图与结点x邻接的边
    void Neighbors(int x);

    // 在图中插入顶点x
    void InsertVertex(int x);

    // 从图中删除顶点x
    void DeleteVertex(int x);

    // 若无向边(x,y)不存在则向图中添加该边
    void AddEdge(int x, int y);

    // 若无向图存在(x,y)从图中删除
    void RemoveEdge(int x, int y);

    // 求图中顶点x的第一个邻接点，若有则返回顶点号，若没有邻接点或图中不存在x则返回-1
    int FirstNeighbor(int x);

    // 假设图中顶点y是顶点x的下一个邻接点，返回除y之外顶点的下一个邻接点的顶点号，若y是x的最后一个邻接点则返回-1
    int NextNeighbor(int x, int y);

    // 获取图(x,y)对应的权值
    int Get_edge_value(int x, int y);

    // 设置图中边(x,y)对应的权值y
    void Set_edge_value(int x, int y, int weight);
};


#endif //INC_08WANGDAO_UNDIRECTEDGRAPH_BASICOPERATION_H
