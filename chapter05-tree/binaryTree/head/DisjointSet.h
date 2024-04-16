/**
 * @Description 树的并查集
 * @Version 1.0.0
 * @Date 2024/4/15 22:01
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_DISJOINTSET_H
#define INC_08WANGDAO_DISJOINTSET_H

#include <iostream>
#include <vector>

class DisjointSet {
private:
    // 存储父节点的数组
    std::vector<int> parent;
    // 存储树的深度（秩）的数组
    std::vector<int> rank;

public:
    // 构造函数，初始化并查集
    DisjointSet(int n);

    // 查找元素所属的集合的根节点
    int find(int x);

    // 合并两个元素所在的集合
    void unionSets(int x, int y);

    // 判断两个元素是否属于同一集合
    bool isConnected(int x, int y);

    // 合并两个集合的树，确保小树并入大树
    void mergeTrees(int x, int y);
};


#endif //INC_08WANGDAO_DISJOINTSET_H
