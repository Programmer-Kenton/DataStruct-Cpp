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
    // 节点中存储的数据
    int data;

    // 左子节点指针
    TreeNode* left;

    // 右子节点指针
    TreeNode* right;

    // 左线索标记
    bool leftThread;

    // 右线索标记
    bool rightThread;

    // 构造函数
    TreeNode(int val) : data(val), left(nullptr), right(nullptr), leftThread(false), rightThread(false) {}
};


class linkBinaryTree {

private:
    // 树的根节点指针
    TreeNode* root;

    // 辅助函数
    // 销毁树的辅助函数
    void destroyTree(TreeNode* root);

    // 前序遍历的辅助函数
    void preOrderTraversal(TreeNode* root);

    // 中序遍历的辅助函数
    void inOrderTraversal(TreeNode* root);

    // 后序遍历的辅助函数
    void postOrderTraversal(TreeNode* root);

    // 中序线索化的辅助函数
    void inOrderThread(TreeNode* root, TreeNode*& prev);

    // 后序线索化的辅助函数
    void postOrderThread(TreeNode* root, TreeNode*& prev);

    // 先序线索化的辅助函数
    void preOrderThread(TreeNode* root, TreeNode*& prev);

    // 辅助函数：找到以给定节点为根的子树中的最左边的节点
    TreeNode* leftmost(TreeNode* node);

    // 辅助函数：找到以给定节点为根的子树中的最右边的节点
    TreeNode* rightmost(TreeNode* node);

public:
    // 构造函数和析构函数
    // 构造函数
    linkBinaryTree();

    // 析构函数
    ~linkBinaryTree();

    // 公共成员函数
    // 插入节点的公共函数
    void insert(int data);

    // 删除节点的公共函数
    void remove(int data);

    // 前序遍历的公共函数
    void preOrder();

    // 中序遍历的公共函数
    void inOrder();

    // 后序遍历的公共函数
    void postOrder();

    // 建立中序线索二叉树的公共函数
    void inOrderThreaded();

    // 建立后序线索二叉树的公共函数
    void postOrderThreaded();

    // 建立先序线索二叉树的公共函数
    void preOrderThreaded();

    // 在中序线索二叉树中查找给定节点的中序后继
    TreeNode* findInOrderSuccessor(TreeNode* node);

    // 在中序线索二叉树中查找给定节点的中序前继
    TreeNode* findInOrderPredecessor(TreeNode* node);

    // 在先序线索二叉树中查找给定节点的先序后继
    TreeNode* findPreOrderSuccessor(TreeNode* node);

    // 在先序线索二叉树中查找给定节点的先序前继
    TreeNode* findPreOrderPredecessor(TreeNode* node);

    // 在后序线索二叉树中查找给定节点的后序前驱
    TreeNode* findPostOrderPredecessor(TreeNode* node);

    // 在后序线索二叉树中查找给定节点的后序后继
    TreeNode* findPostOrderSuccessor(TreeNode* node);
};


#endif //INC_08WANGDAO_LINKBINARYTREE_H
