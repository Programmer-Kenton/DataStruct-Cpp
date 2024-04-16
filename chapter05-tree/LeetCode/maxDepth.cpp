/**
 * @Description 树的最大深度
 * @Version 1.0.0
 * @Date 2024/4/16 15:49
 * @Author Kenton
 */

#include "../binaryTree/head/staticBinaryTree.h"

int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int lmax = maxDepth(root->left);
    int rmax = maxDepth(root->right);
    return 1 + std::max(lmax,rmax);
}