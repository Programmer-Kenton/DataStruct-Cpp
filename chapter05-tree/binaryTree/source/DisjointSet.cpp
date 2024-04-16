/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/15 22:01
 * @Author Kenton
 */
#include "../head/DisjointSet.h"

DisjointSet::DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n);
    // 初始时每个节点的父节点是自己，秩为0
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSet::find(int x) {
    if (x != parent[x]) {
        // 路径压缩，将当前节点的父节点设置为根节点
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void DisjointSet::unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return; // 已经在同一集合中

    // 按秩合并，将秩较小的树合并到秩较大的树中
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

bool DisjointSet::isConnected(int x, int y) {
    return find(x) == find(y);
}

void DisjointSet::mergeTrees(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return; // 已经在同一集合中

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        // 如果两个树的深度相同，则任意选择一个作为根，并将另一个树的根指向它
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
