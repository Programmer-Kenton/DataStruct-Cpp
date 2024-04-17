/**
 * @Description 两数之和 输入二叉搜索树
 * @Version 1.0.0
 * @Date 2024/4/17 9:28
 * @Author Kenton
 */

#include "vector"
#include "../tree-Hero/head/binarySearchTree.h"

void inorder(TreeNode<int>* root,std::vector<int>& ret){
    if (root){
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
    }
}

bool findTarget(TreeNode<int>* root,int k){
    std::vector<int> ret;
    inorder(root,ret);
    int left = 0,right = ret.size() - 1;
    while (left < right){
        int sum = ret[left] + ret[right];
        if (sum > k){
            --right;
        }else if (sum < k){
            ++left;
        } else{
            return true;
        }
    }
}