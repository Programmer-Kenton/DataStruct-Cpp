/**
 * @Description TODO 静态存储二叉树的测试用例
 * @Version 1.0.0
 * @Date 2024/4/15 15:59
 * @Author Kenton
 */

#include "../head/staticBinaryTree.h"
#include <iostream>
#include <vector>


int main() {
    // 创建二叉树对象
    staticBinaryTree tree;

    // 插入节点
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // 前序遍历
    std::cout << "Preorder traversal: ";
    tree.preOrder(); // 5 3 2 4 7 6 8

    // 中序遍历
    std::cout << "Inorder traversal: ";
    tree.inOrder(); // 2 3 4 5 6 7 8

    // 后序遍历
    std::cout << "Postorder traversal: ";
    tree.postOrder(); // 2 4 3 6 8 7 5

    // 层序遍历
    std::cout << "Levelorder traversal: ";
    tree.levelOrder(); // 5 3 7 2 4 6 8

    // 搜索节点
    int searchData = 6;
    if (tree.search(searchData)) {
        std::cout << searchData << " found in the tree-Hero." << std::endl;
    } else {
        std::cout << searchData << " not found in the tree-Hero." << std::endl;
    }

    // 获取树的高度
    std::cout << "Height of the tree-Hero: " << tree.getHeight() << std::endl;

    // 获取树的大小
    std::cout << "Size of the tree-Hero: " << tree.getSize() << std::endl;

    // 构建二叉树：根据前序遍历序列和中序遍历序列
    std::vector<int> preorder = {5, 3, 2, 4, 7, 6, 8};
    std::vector<int> inorder = {2, 3, 4, 5, 6, 7, 8};

    // 创建 staticBinaryTree 类的实例
    staticBinaryTree treeInstance;

    staticBinaryTree* treeFromPreIn = treeInstance.buildTreeFromPreIn(preorder, inorder);
    std::cout << "Levelorder traversal of tree-Hero built from preorder and inorder: ";
    treeFromPreIn->levelOrder(); // 5 3 7 2 4 6 8

    // 构建二叉树：根据后序遍历序列和中序遍历序列
    std::vector<int> postorder = {2, 4, 3, 6, 8, 7, 5};
    staticBinaryTree* treeFromPostIn = treeInstance.buildTreeFromPostIn(postorder, inorder);
    std::cout << "Levelorder traversal of tree-Hero built from postorder and inorder: ";
    treeFromPostIn->levelOrder(); // 5 3 7 2 4 6 8

    // 释放动态分配的内存
    delete treeFromPreIn;
    delete treeFromPostIn;

    return 0;
}



