/**
 * @Description 二叉树的前序遍历
 * @Version 1.0.0
 * @Date 2024/4/16 17:24
 * @Author Kenton
 */

#include "../tree-Hero//head/binaryTree_Hero.h"
#include "vector"


void preorder(TreeNode<int>* root,std::vector<int>& ret){
    if (root){
        ret.push_back(root->val);
        preorder(root->left,ret);
        preorder(root->right,ret);
    }
}
std::vector<int> preorderTraversal(TreeNode<int>* root){
    std::vector<int> ret;
    preorder(root,ret);
    return ret;
}