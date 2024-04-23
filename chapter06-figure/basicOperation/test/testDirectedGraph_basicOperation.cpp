/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:31
 * @Author Kenton
 */
 
#include "../head/DirectedGraph_basicOperation.h"

int main(){
    // ����һ������5�����������ͼ
    DirectedGraph_basicOperation graph(5);

    // ��������
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 4);

    // �ж�ͼ�Ƿ���ڱ�(0,1)
    std::cout << "��(0,1)�Ƿ����: " << graph.Adjacent(0, 1) << std::endl;

    // �г�ͼ����0�ڽӵı�
    graph.Neighbors(0);

    // ��ͼ�в��붥��5
    graph.InsertVertex(5);

    // ɾ������2������صı�
    graph.DeleteVertex(2);

    // ��ӡ�ڽӾ���
    std::cout << "�ڽӾ���" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << graph.Get_edge_value(i, j) << " ";
        }
        std::cout << std::endl;
    }
}