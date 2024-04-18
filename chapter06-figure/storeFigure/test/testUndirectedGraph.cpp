/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/17 22:15
 * @Author Kenton
 */

#include "../head/UndirectedGraph.h"

int main(){
    // 创建一个包含5个顶点的无向图
    UndirectedGraph graph(5);

    // 添加边，连接顶点
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // 打印邻接矩阵
    graph.printMatrix();
}