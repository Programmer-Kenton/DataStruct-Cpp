/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 11:17
 * @Author Kenton
 */

#include "../head/UndirectedGraphWithMultipleTable.h"

int main(){
    // 创建一个包含5个顶点的无向图
    UndirectedGraphWithMultipleTable graph(5);

    // 添加无向边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // 打印邻接多重表
    graph.printList();
}