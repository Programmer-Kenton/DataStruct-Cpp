/**
 * @Description TODO 实现链式树
 * @Version 1.0.0
 * @Date 2024/4/15 10:53
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_TREE_H
#define INC_08WANGDAO_TREE_H

#include "iostream"

// 默认创建树时节点的最大数量
#define defaultNum 100001

// 链表中的一个节点
template<typename T>
struct ListNode {
    T data;

    // 指向链表中下一个节点的指针
    ListNode *next;

    ListNode(T data) : data(data), next(nullptr) {}
};


// 树中的一个节点
template<typename T>
struct TreeNode {
    T data;

    // 指向一个链表的头节点，该链表用于存储当前节点的所有子节点
    // 链表节点的类型是 ListNode<TreeNode<T> *>
    // 每个节点的 data 成员是一个 TreeNode<T> 类型的指针，指向实际的子节点。
    ListNode<TreeNode<T> *> *childrenHead;

    TreeNode();

    // 向当前节点添加子节点
    void AddChild(TreeNode<T> *node);
};

template<typename T>
TreeNode<T>::TreeNode() {
    childrenHead = nullptr;
}

// 接收一个 TreeNode<T> 类型的指针 node，将其作为子节点添加到当前节点的子节点链表中
template<typename T>
void TreeNode<T>::AddChild(TreeNode<T> *node) {
    ListNode<TreeNode<T> *> *childNode = new ListNode<TreeNode<T> *>(node);
    // 如果当前节点的 childrenHead 为空（即没有子节点），则直接将 childNode 设置为新的子节点链表头。
    if (childrenHead == nullptr) {
        childrenHead = childNode;
    } else {
        // 头插法
        childNode->next = childrenHead;
        childrenHead = childNode;
    }
}

template<typename T>
class Tree {
private:
    // 用于存储所有的树节点
    TreeNode<T> *nodes;
    // 指向根节点的指针
    TreeNode<T> *root;

public:
    Tree();

    // 接受最大节点数
    Tree(int maxNodes);

    // 释放 nodes 数组所占的内存
    ~Tree();

    // 根据给定的节点ID返回对应的 TreeNode 对象
    TreeNode<T> *GetTreeNode(int id);

    // 设置树的根节点
    void SetRoot(int rootId);

    // 在父节点（由 parentId 指定）下添加子节点（由 sonId 指定）
    void AddChild(int parentId, int sonId);

    // 给指定节点（由 nodeId 指定）设置数据。
    void AssignData(int nodeId, T data);

    // 打印树的结构，从指定节点开始（默认为根节点）。
    void Print(TreeNode<T> *node = nullptr);
};

template<typename T>
void Tree<T>::Print(TreeNode<T> *node) {
    // 如果传入的 node 参数为 nullptr，则将 node 设置为根节点 root，表示从根节点开始打印。
    if (node == nullptr) {
        node = root;
    }
    std::cout << node->data;
    // 初始化一个临时指针 tmp，指向当前节点的子节点链表头
    ListNode<TreeNode<T> *> *tmp = node->childrenHead;
    // 对于每一个子节点，递归调用 Print() 函数，打印其子树结构。
    while (tmp) {
        Print(tmp->data);
        // 按照深度优先搜索（DFS）的方式打印整棵树的结构。
        tmp = tmp->next;
    }
}

template<typename T>
void Tree<T>::AssignData(int nodeId, T data) {
    // 传入 nodeId 参数，获取对应节点。
    GetTreeNode(nodeId)->data = data;
}

template<typename T>
void Tree<T>::AddChild(int parentId, int sonId) {
    // 传入 parentId 和 sonId 参数，获取父节点和子节点。
    TreeNode<T> *parentNode = GetTreeNode(parentId);
    TreeNode<T> *sonNode = GetTreeNode(sonId);
    // 调用父节点的 AddChild() 方法，传入子节点作为参数，将子节点添加到父节点的子节点链表中。
    parentNode->AddChild(sonNode);
}

template<typename T>
void Tree<T>::SetRoot(int rootId) {
    // 传入 rootId 参数，获取指定节点。
    // 将获取到的节点赋值给类成员变量 root，设置为树的根节点
    root = GetTreeNode(rootId);
}

template<typename T>
TreeNode<T> *Tree<T>::GetTreeNode(int id) {
    // 直接返回 nodes 数组中索引为 id 的元素地址
    return &nodes[id];
}

template<typename T>
Tree<T>::~Tree() {
    delete[] nodes;
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
    nodes = new TreeNode<T>[maxNodes];
}

template<typename T>
Tree<T>::Tree() {
    nodes = new TreeNode<T>[defaultNum];
}


#endif //INC_08WANGDAO_TREE_H
