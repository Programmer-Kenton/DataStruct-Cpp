/**
 * @Description 英雄课程 二叉树的实现
 * @Version 1.0.0
 * @Date 2024/4/16 16:22
 * @Author Kenton
 */

#ifndef INC_08WANGDAO_BINARYTREE_HERO_H
#define INC_08WANGDAO_BINARYTREE_HERO_H

#include "iostream"

template<typename T>
struct TreeNode{
    T val;

    TreeNode *left;

    TreeNode *right;

    TreeNode():val(0),left(nullptr),right(nullptr){};

    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
};

template<typename T>
class binaryTree_Hero {
private:
    TreeNode<T> *nodes;

    TreeNode<T> *root;

    size_t nodeSize;

    TreeNode<T>* Create(T a[],int size,int nodeId,T nullNode);

    void visit(TreeNode<T> *node);

    void preOrder(TreeNode<T> *node);

    void inOrder(TreeNode<T> *node);

    void postOrder(TreeNode<T> *node);

public:
    binaryTree_Hero();

    binaryTree_Hero(int maxNodes);

    ~binaryTree_Hero();

    TreeNode<T>* GetTreeNode(int id);

    void CreateTree(T a[],int size,T nullNode);

    void preOrderTraversal();

    void inOrderTraversal();

    void postOrderTraversal();
};

template<typename T>
void binaryTree_Hero<T>::postOrderTraversal() {
    postOrder(root);
}

template<typename T>
void binaryTree_Hero<T>::inOrderTraversal() {
    inOrder(root);
}

template<typename T>
void binaryTree_Hero<T>::preOrderTraversal() {
    postOrder(root);
}

template<typename T>
TreeNode<T> *binaryTree_Hero<T>::Create(T *a, int size, int nodeId, T nullNode) {
    if (nodeId >= size || a[nodeId] == nullNode){
        return nullptr;
    }
    TreeNode<T> *currNode = GetTreeNode(nodeId);
    currNode->val = a[nodeId];
    currNode->left = Create(a,size,nodeId * 2,nullNode);
    currNode->right = Create(a,size,nodeId * 2 + 1,nullNode);
    return currNode;
}

template<typename T>
void binaryTree_Hero<T>::CreateTree(T *a, int size, T nullNode) {
    root = Create(a,size,1,nullNode);
}

template<typename T>
void binaryTree_Hero<T>::postOrder(TreeNode<T> *node) {
    if (node){
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

template<typename T>
void binaryTree_Hero<T>::inOrder(TreeNode<T> *node) {
    if (node){
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

template<typename T>
void binaryTree_Hero<T>::preOrder(TreeNode<T> *node) {
    if (node){
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

template<typename T>
TreeNode<T> *binaryTree_Hero<T>::GetTreeNode(int id) {
    return &nodes[id];
}

template<typename T>
void binaryTree_Hero<T>::visit(TreeNode<T> *node) {
    std::cout << node->val;
}

template<typename T>
binaryTree_Hero<T>::~binaryTree_Hero() {
    delete[] nodes;
}

template<typename T>
binaryTree_Hero<T>::binaryTree_Hero(int maxNodes) {
    nodeSize = maxNodes;
    nodes = new TreeNode<T>[nodeSize];
}

template<typename T>
binaryTree_Hero<T>::binaryTree_Hero() {
    nodeSize = 100001;
    nodes = new TreeNode<T>(nodeSize);
}


#endif //INC_08WANGDAO_BINARYTREE_HERO_H
