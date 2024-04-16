/**
 * @Description 完全二叉树的结点个数
 * @Version 1.0.0
 * @Date 2024/4/16 17:19
 * @Author Kenton
 */

#include "../tree-Hero/head/binaryTree_Hero.h"

int countNodes(TreeNode<int>* root){
    if (root == nullptr) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}