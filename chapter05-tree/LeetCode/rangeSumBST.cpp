/**
 * @Description 二叉搜索树的范围和
 * @Version 1.0.0
 * @Date 2024/4/16 20:37
 * @Author Kenton
 */

#include "../tree-Hero/head/binarySearchTree.h"

int rangeSumBST(TreeNode<int>* root,int low,int high){

    if (root == nullptr) return 0;

    int sum = 0;
    if (low <= root->val && root->val <= high){
        sum += root->val;
    }

    sum += rangeSumBST(root->left,low,high);
    sum += rangeSumBST(root->right,low,high);
    return sum;
}