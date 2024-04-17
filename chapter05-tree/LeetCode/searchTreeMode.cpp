/**
 * @Description 二叉搜索树中的众数
 * @Version 1.0.0
 * @Date 2024/4/17 9:37
 * @Author Kenton
 */

#include "vector"
#include "../tree-Hero/head/binarySearchTree.h"

std::vector<int>  ret;
int pre;
int cnt,maxcnt;

void visit(TreeNode<int>* root){
    if (root->val == pre){
        cnt++;
    } else{
        pre = root->val;
        cnt = 1;
    }
    if (cnt > maxcnt){
        maxcnt = cnt;
        ret.clear();
        ret.push_back(root->val);
    } else if (cnt == maxcnt){
        ret.push_back(root->val);
    }
}

void inorder(TreeNode<int>* root){
    if (root){
        inorder(root->left);
        visit(root);
        inorder(root->right);
    }
}

std::vector<int> findMode(TreeNode<int>* root){
    ret.clear();
    pre = -10000000;
    maxcnt = cnt = 0;
    inorder(root);
    return ret;
}