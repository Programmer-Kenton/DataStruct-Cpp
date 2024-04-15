/**
 * @Description TODO 二叉树的链式存储
 * @Version 1.0.0
 * @Date 2024/4/15 15:59
 * @Author Kenton
 */

#ifndef INC_08WANGDAO_LINKBINARYTREE_H
#define INC_08WANGDAO_LINKBINARYTREE_H

#include <iostream>
#include <stack>

// 定义二叉树节点的结构
struct TreeNode {
    int data; // 节点中存储的数据
    TreeNode* left; // 左子节点指针
    TreeNode* right; // 右子节点指针
    bool leftThread; // 左线索标记
    bool rightThread; // 右线索标记

    // 构造函数
    TreeNode(int val) : data(val), left(nullptr), right(nullptr), leftThread(false), rightThread(false) {}
};


class linkBinaryTree {

private:
    TreeNode* root; // 树的根节点指针

    // 辅助函数
    void destroyTree(TreeNode* root); // 销毁树的辅助函数
    void preOrderTraversal(TreeNode* root); // 前序遍历的辅助函数
    void inOrderTraversal(TreeNode* root); // 中序遍历的辅助函数
    void postOrderTraversal(TreeNode* root); // 后序遍历的辅助函数
    void inOrderThread(TreeNode* root, TreeNode*& prev); // 中序线索化的辅助函数
    void postOrderThread(TreeNode* root, TreeNode*& prev); // 后序线索化的辅助函数
    void preOrderThread(TreeNode* root, TreeNode*& prev); // 先序线索化的辅助函数

public:
    // 构造函数和析构函数
    linkBinaryTree(); // 构造函数
    ~linkBinaryTree(); // 析构函数

    // 公共成员函数
    void insert(int data); // 插入节点的公共函数
    void remove(int data); // 删除节点的公共函数
    void preOrder(); // 前序遍历的公共函数
    void inOrder(); // 中序遍历的公共函数
    void postOrder(); // 后序遍历的公共函数
    void inOrderThreaded(); // 建立中序线索二叉树的公共函数
    void postOrderThreaded(); // 建立后序线索二叉树的公共函数
    void preOrderThreaded(); // 建立先序线索二叉树的公共函数
};


#endif //INC_08WANGDAO_LINKBINARYTREE_H
