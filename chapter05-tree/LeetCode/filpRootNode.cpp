/**
 * @Description 翻转根结点
 * @Version 1.0.0
 * @Date 2024/4/16 18:43
 * @Author Kenton
 */


#include "../tree-Hero//head/binaryTree_Hero.h"

TreeNode<int>* invertTree(TreeNode<int>* root){
    if (root == nullptr) return nullptr;

    TreeNode<int>* left = invertTree(root->left);
    TreeNode<int>* right = invertTree(root->right);

    root->left = right;
    root->right = left;
    return root;
}