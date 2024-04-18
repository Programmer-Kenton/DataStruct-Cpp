/**
 * @Description
 * @Version 1.0.0
 * @Date 2024/4/17 22:26
 * @Author Kenton
 */

#include "../head/DirectedGraph.h"

int main(){
    // 创建一个包含5个顶点的有向图
    DirectedGraph graph(5);

    // 添加有向边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // 打印邻接矩阵
    graph.printMatrix();
}