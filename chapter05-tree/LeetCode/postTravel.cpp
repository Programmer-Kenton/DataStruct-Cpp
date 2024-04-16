/**
 * @Description 二叉树的后序遍历
 * @Version 1.0.0
 * @Date 2024/4/16 18:38
 * @Author Kenton
 */

#include "../tree-Hero//head/binaryTree_Hero.h"
#include "vector"

void postorder(TreeNode<int>* root,std::vector<int>& ret){
    if (root){
        postorder(root->left,ret);
        postorder(root->right,ret);
        ret.push_back(root->val);
    }
}

std::vector<int> postorderTraversal(TreeNode<int> *root){
    std::vector<int> ret;
    postorder(root,ret);
    return ret;
}