/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 10:01
 * @Author Kenton
 */

#include "../head/DirectedGraphWithCrossWordList.h"

int main(){
    // 创建一个包含5个顶点的有向图
    DirectedGraphWithCrossWordList graph(5);

    // 添加有向边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // 打印十字链表
    graph.printList();
}