/**
 * @Description 计算二叉树的深度
 * @Version 1.0.0
 * @Date 2024/4/16 15:56
 * @Author Kenton
 */

#include "../binaryTree/head/staticBinaryTree.h"

int calculateDepth(staticBinaryTree& tree){
    return tree.getHeight();
}

int main(){
    staticBinaryTree tree;
    
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    int depth = calculateDepth(tree);
    std::cout << "depth = " << depth << std::endl;
}