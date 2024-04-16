/**
 * @Description 从根到叶的二进制数之和
 * @Version 1.0.0
 * @Date 2024/4/16 18:53
 * @Author Kenton
 */


#include "../tree-Hero//head/binaryTree_Hero.h"


int sum;

void sumRoot(TreeNode<int>* root,int pre){
    // 这里用到先序遍历 逐个拿取结点的值并计算
    if (!root->left && !root->right){
        sum += pre * 2 + root->val;
        return;
    }
    if (root->left){
        sumRoot(root->left,pre * 2 + root->val);
    }
    if (root->right){
        sumRoot(root->right,pre * 2 + root->val);
    }
}

int sumRootToLeaf(TreeNode<int>* root){
    sum = 0;
    sumRoot(root,0);
    return sum;
}