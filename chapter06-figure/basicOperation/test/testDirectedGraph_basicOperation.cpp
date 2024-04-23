/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:31
 * @Author Kenton
 */
 
#include "../head/DirectedGraph_basicOperation.h"

int main(){
    // 创建一个包含5个顶点的有向图
    DirectedGraph_basicOperation graph(5);

    // 添加有向边
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 4);

    // 判断图是否存在边(0,1)
    std::cout << "边(0,1)是否存在: " << graph.Adjacent(0, 1) << std::endl;

    // 列出图与结点0邻接的边
    graph.Neighbors(0);

    // 在图中插入顶点5
    graph.InsertVertex(5);

    // 删除顶点2及其相关的边
    graph.DeleteVertex(2);

    // 打印邻接矩阵
    std::cout << "邻接矩阵：" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << graph.Get_edge_value(i, j) << " ";
        }
        std::cout << std::endl;
    }
}