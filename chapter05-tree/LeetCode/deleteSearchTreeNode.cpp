/**
 * @Description 删除二叉搜索树中的结点
 * @Version 1.0.0
 * @Date 2024/4/17 10:21
 * @Author Kenton
 */
#include "vector"
#include "../tree-Hero/head/binarySearchTree.h"

class Solution {
private:
    int findMin(TreeNode<int> *root) {
        if (root->left) {
            return findMin(root->left);
        }
        return root->val;
    }


    TreeNode<int> *delRoot(TreeNode<int> *root) {
        if (root->left == nullptr) {
            TreeNode<int> *delNode = root;
            TreeNode<int> *retNode = root->right;
            delete delNode;
            return retNode;
        } else if (root->right == nullptr) {
            TreeNode<int> *delNode = root;
            TreeNode<int> *retNode = root->left;
            delete delNode;
            return retNode;
        } else {
            TreeNode<int> *retNode = new TreeNode(0);
            retNode->val = findMin(root->right);
            retNode->right = deleteNode(root->right, retNode->val);
            retNode->left = root->left;
            return retNode;
        }
        return nullptr;
    }

public:
    TreeNode<int> *deleteNode(TreeNode<int> *root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            return delRoot(root);
        }
    }
};






