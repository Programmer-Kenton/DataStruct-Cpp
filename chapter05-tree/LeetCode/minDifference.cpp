/**
 * @Description TODO 二叉搜索树的最小差值
 * @Version 1.0.0
 * @Date 2024/4/17 9:17
 * @Author Kenton
 */

#include "vector"
#include "../tree-Hero/head/binarySearchTree.h"

void inorder(TreeNode<int>* root,int& pre,int& ret){
    if (root){
        inorder(root->left,pre,ret);
        ret = std::min(ret,(root->val - pre));
        pre = root->val;
        inorder(root->right,pre,ret);
    }
}

int getMinimumDifference(TreeNode<int>* root){
    int pre = -10000000;
    int ret = 100000000;

    inorder(root,pre,ret);
    return ret;
}