/**
 * @Description 验证二叉搜索树
 * 二叉搜索树中序遍历是单调递增的 注意这个特点
 * @Version 1.0.0
 * @Date 2024/4/16 21:11
 * @Author Kenton
 */

#include "../tree-Hero/head/binarySearchTree.h"
#include "vector"

void inOrder(TreeNode<int>* root,std::vector<int>& ret){
    if (root){
        inOrder(root->left,ret);
        ret.push_back(root->val);
        inOrder(root->right,ret);
    }
}

bool isValidBST(TreeNode<int>* root){
    std::vector<int> ret;
    inOrder(root,ret);
    for (int i = 0; i < ret.size(); ++i) {
        if (ret[i] <= ret[i-1]){
            return false;
        }
    }
    return true;
}