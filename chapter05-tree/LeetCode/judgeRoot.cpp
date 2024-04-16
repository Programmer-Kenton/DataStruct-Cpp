/**
 * @Description 判断根节点是否等于子节点之和
 * @Version 1.0.0
 * @Date 2024/4/15 14:07
 * @Author Kenton
 */


#include "../binaryTree/head/staticBinaryTree.h"

bool checkTree(TreeNode* root){
    return root->data == root->left->data + root->right->data;
}

