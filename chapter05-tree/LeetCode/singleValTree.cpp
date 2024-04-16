/**
 * @Description 单值二叉树
 * @Version 1.0.0
 * @Date 2024/4/16 17:10
 * @Author Kenton
 */

#include "../tree-Hero/head/binaryTree_Hero.h"

bool isUnivalTree(TreeNode<int>* root){
    if (root == nullptr){
        return true;
    }
    if (root->left){
        if (root->val != root->left->val){
            return false;
        }
        if (!isUnivalTree(root->left)){
            return false;
        }
    }
    if (root->right){
        if (root->val != root->right->val){
            return false;
        }
        if (!isUnivalTree(root->right)){
            return false;
        }
    }
    return true;
}