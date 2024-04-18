/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 9:33
 * @Author Kenton
 */

#include "../head/DirectedGraphWithList.h"

int main(){
    // 创建一个包含5个顶点的有向图
    DirectedGraphWithList graph(5);

    // 添加有向边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // 打印邻接表
    graph.printList();
}