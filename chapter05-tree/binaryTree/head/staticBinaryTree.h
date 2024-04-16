/**
 * @Description TODO 二叉树的静态存储
 * @Version 1.0.0
 * @Date 2024/4/15 14:14
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICBINARYTREE_H
#define INC_08WANGDAO_STATICBINARYTREE_H

#include "iostream"
#include "queue"
#include "algorithm"

// 定义二叉树节点的结构
struct TreeNode{
    // 节点中存储的数据
    int data;
    // 左子节点指针
    TreeNode* left;
    // 右子节点指针
    TreeNode* right;
};

class staticBinaryTree {
private:
    // 树的根节点指针
    TreeNode* root;

    // 插入节点的辅助函数
    TreeNode* insertNode(TreeNode* root, int data);

    // 删除节点的辅助函数
    // TODO 刘依纯 这个功能 学完平衡二叉树的左旋和右旋 你就理解了
    TreeNode* deleteNode(TreeNode* root, int data);

    // 在子树中找到最小节点的辅助函数
    TreeNode* findMin(TreeNode* node);

    // 销毁树
    void destroyTree(TreeNode* root);

    // 前序遍历的辅助函数
    void preOrderTraversal(TreeNode* root);

    // 中序遍历
    void inOrderTraversal(TreeNode* root);

    // 后序遍历
    void postOrderTraversal(TreeNode* root);

    // 获取树的高度
    int getHeight(TreeNode* root);

    // 判断树是否为空
    bool isEmpty(TreeNode* root);

    // 获取树的大小和树的高度功能一致
    int getSize(TreeNode* root);

    // TODO 辅助函数：根据前序遍历序列和中序遍历序列构建二叉树
    TreeNode* buildTreeFromPreIn(std::vector<int>& preorder,std::vector<int>& inorder,int preStart,int inStart,int inEnd);

    // TODO 辅助函数：根据后序遍历序列和中序遍历序列构建二叉树
    TreeNode* buildTreeFromPostIn(std::vector<int>& postorder, std::vector<int>& inorder, int postStart, int inStart, int inEnd);

    // TODO 辅助函数：根据层序遍历序列和中序遍历序列构建二叉树
    TreeNode* buildTreeFromLevelIn(std::vector<int>& levelorder, std::vector<int>& inorder);

public:
    staticBinaryTree();

    ~staticBinaryTree();

    // 插入节点的公共函数
    void insert(int data);

    // 删除节点的公共函数
    void remove(int data);

    // 前序遍历的公共函数
    void preOrder();

    // 中序遍历
    void inOrder();

    // 后序遍历
    void postOrder();

    // 查找节点
    bool search(int data);

    // 获取树的高度
    int getHeight();

    // 判断树是否为空
    bool isEmpty();

    // 获取树的大小
    int getSize();

    // 查找左子节点
    TreeNode* getLeftChild(TreeNode* node);

    // 查找右子节点
    TreeNode* getRightChild(TreeNode *node);

    // 获取根节点
    TreeNode* getRoot();

    // 层序遍历二叉树
    void levelOrder();

    // 根根据前序遍历序列和中序遍历序列构建二叉树的公共函数
    staticBinaryTree* buildTreeFromPreIn(std::vector<int>& preorder, std::vector<int>& inorder);

    // 根据后序遍历序列和中序遍历序列构建二叉树的公共函数
    staticBinaryTree* buildTreeFromPostIn(std::vector<int>& postorder, std::vector<int>& inorder);
};


#endif //INC_08WANGDAO_STATICBINARYTREE_H
