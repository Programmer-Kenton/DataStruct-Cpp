/**
 * @Description 二叉树的中序遍历
 * @Version 1.0.0
 * @Date 2024/4/16 17:40
 * @Author Kenton
 */


#include "../tree-Hero//head/binaryTree_Hero.h"
#include "vector"

void inorder(TreeNode<int>* root,std::vector<int>& ret){
    if (root){
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
    }
}

std::vector<int> preorderTraversal(TreeNode<int>* root){
    std::vector<int> ret;
    inorder(root,ret);
    return ret;
}