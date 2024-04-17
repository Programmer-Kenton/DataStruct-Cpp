/**
 * @Description TODO 恢复二叉搜索树
 * @Version 1.0.0
 * @Date 2024/4/17 9:56
 * @Author Kenton
 */

#include "vector"
#include "../tree-Hero/head/binarySearchTree.h"

std::vector<TreeNode<int>*> ret;

void inorder(TreeNode<int>* root){
    if (root){
        inorder(root->left);
        ret.push_back(root);
        inorder(root->right);
    }
}

void recoverTree(TreeNode<int>* root){
    ret.clear();
    inorder(root);
    TreeNode<int> *x = nullptr;
    TreeNode<int> *y = nullptr;
    for (int i = 0; i < ret.size() - 1; ++i) {
        if (ret[i]->val > ret[i+1]->val){
            y = ret[i+1];
            if (x == nullptr){
                x = ret[i];
            }
        }
    }
    if (x && y){
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
}