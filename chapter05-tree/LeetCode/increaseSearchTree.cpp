/**
 * @Description 递增顺序搜素树
 * @Version 1.0.0
 * @Date 2024/4/17 8:58
 * @Author Kenton
 */

#include "vector"
#include "../tree-Hero/head/binarySearchTree.h"

 void inorder(TreeNode<int>* root,std::vector<int>& ret){
     if (root){
         inorder(root->left,ret);
         ret.push_back(root->val);
         inorder(root->right,ret);
     }
 }

 TreeNode<int>* increasingBST(TreeNode<int>* root){
     std::vector<int> ret;
     inorder(root,ret);
     TreeNode head = new TreeNode<int>(-1);
     TreeNode curr = head;

     for (int i = 0; i < ret.size(); ++i) {
         TreeNode t = new TreeNode<int>(ret[i]);
         curr.right = &t;
         curr = t;
     }
     return reinterpret_cast<TreeNode<int> *>(head.right);
 }