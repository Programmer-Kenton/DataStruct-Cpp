/**
 * @Description 计算布尔二叉树的值
 * @Version 1.0.0
 * @Date 2024/4/16 16:02
 * @Author Kenton
 */

#include "../binaryTree/head/staticBinaryTree.h"

bool evaluateTree(TreeNode* root){
    if (root == nullptr){
        return false;
    }
    if (root->data == 0 || root->data == 1){
        return root->data == 1;
    }
    if (root->data == 2){
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
    return evaluateTree(root->left) && evaluateTree(root->right);
}