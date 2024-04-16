/**
 * @Description 二叉搜索树的搜索
 * @Version 1.0.0
 * @Date 2024/4/16 20:08
 * @Author Kenton
 */

#include "../tree-Hero/head/binarySearchTree.h"

TreeNode<int>* searchBST(TreeNode<int>* root,int val){
    if (root == nullptr) return nullptr;

    if (val < root->val){
        return searchBST(root->left,val);
    } else if (val > root->val){
        return searchBST(root->right,val);
    }

    return root;
}

