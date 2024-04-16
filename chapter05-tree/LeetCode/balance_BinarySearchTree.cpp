/**
 * @Description TODO 将有序数组转换为二叉搜索树
 * @Version 1.0.0
 * @Date 2024/4/16 20:46
 * @Author Kenton
 */

#include "../tree-Hero/head/binarySearchTree.h"
#include "vector"

TreeNode<int>* sortedArray(TreeNode<int>* root,std::vector<int> nums,int left,int right){
    if (left > right){
        return NULL;
    }
    int mid = (left + right) / 2;
    root->left = sortedArray(root,nums,left,mid - 1);
    root->right = sortedArray(root,nums,mid + 1,right);
    return root;
}

TreeNode<int>* sortedArrayToBST(TreeNode<int>* root,std::vector<int>& nums){
    return sortedArray(root,nums,0,nums.size() - 1);
}