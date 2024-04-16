/**
 * @Description 二叉搜索树
 * @Version 1.0.0
 * @Date 2024/4/16 19:09
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_BINARYSEARCHTREE_H
#define INC_08WANGDAO_BINARYSEARCHTREE_H

#include "iostream"

template<typename T>
struct TreeNode{
    T val;

    TreeNode *left;

    TreeNode *right;

    TreeNode():val(0),left(nullptr),right(nullptr){}

    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
};

template<typename T>
class binarySearchTree {
private:
    TreeNode<T> *root;

    TreeNode<T>* insertNode(TreeNode<T> *node,T value);

    TreeNode<T>* removeNode(TreeNode<T> *node,T value);

    bool searchNode(TreeNode<T> *node,T value);

    void inOrder(TreeNode<T> *node);

public:
    binarySearchTree();

    ~binarySearchTree();

    void insert(T value);

    void remove(T value);

    bool search(T value);

    void inOrderTraversal();

    TreeNode<T> getRoot();
};

template<typename T>
TreeNode<T> binarySearchTree<T>::getRoot() {
    return reinterpret_cast<TreeNode<int> &&>(root);
}

template<typename T>
void binarySearchTree<T>::inOrder(TreeNode<T> *node) {
    if(node){
        inOrder(node->left);
        std::cout << node->val << ' ';
        inOrder(node->right);
    }
}

template<typename T>
TreeNode<T> *binarySearchTree<T>::removeNode(TreeNode<T> *node, T value) {
    if (node == nullptr) return nullptr;

    if (value < node->val){
        node->left = removeNode(node->left,value);
    }else if (value > node->val){
        node->right = removeNode(node->right,value);
    } else{
        if (node->left == NULL && node->right == NULL){
            // 叶子结点直接删除
            delete[] node;
        } else if (node->left == NULL){
            // 右子树为空 保存右子树结点
            TreeNode<T> *rightChild = node->right;
            delete[] node;
            // 右子树结点为新的根节点
            return rightChild;
        } else if (node->right == NULL){
            TreeNode<T> *leftChild = node->left;
            delete[] node;
            // 左子树为新的根节点
            return leftChild;
        } else{
            // 左右子树都存在
            // 删除指定节点值 整棵树始终要保持平衡
            TreeNode<T> *replacement = node->right;
            while (replacement->left){
                replacement = replacement->left;
            }
            node->val = replacement->val;
            // 将右子树的最后一个左子树删除并更新右子树的根节点
            node->right = removeNode(node->right,replacement->val);
        }
    }
    return node;
}

template<typename T>
bool binarySearchTree<T>::searchNode(TreeNode<T> *node, T value) {
    if (node == nullptr) return false;

    if (value < node->val){
        return searchNode(node->left,value);
    } else if (value > node->val){
        return searchNode(node->right,value);
    }
    return true;
}

template<typename T>
TreeNode<T> *binarySearchTree<T>::insertNode(TreeNode<T> *node, T value) {
    // 头结点为空 创建头结点并赋值
    if (node == nullptr) return node = new TreeNode<T>(value);

    if (value < node->val){
        node->left = insertNode(node->left,value);
    } else if (value > node->val){
        node->right = insertNode(node->right,value);
    }
    return node;
}

template<typename T>
void binarySearchTree<T>::inOrderTraversal() {
    inOrder(root);
    std::cout << std::endl;
}

template<typename T>
bool binarySearchTree<T>::search(T value) {
    return searchNode(root,value);
}

template<typename T>
void binarySearchTree<T>::remove(T value) {
    root = removeNode(root,value);
}

template<typename T>
void binarySearchTree<T>::insert(T value) {
    root = insertNode(root,value);
}

template<typename T>
binarySearchTree<T>::~binarySearchTree() {
    while (root){
        remove(root->val);
    }
}

template<typename T>
binarySearchTree<T>::binarySearchTree() : root(nullptr){

}


#endif //INC_08WANGDAO_BINARYSEARCHTREE_H
