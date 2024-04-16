/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/16 16:23
 * @Author Kenton
 */

#include "../head/binaryTree_Hero.h"

int main(){
    const char nullNode = '-';
    char a[15] = {
            nullNode,'a','b','c','d',
            nullNode,'e','f','g','h',
            nullNode,nullNode,nullNode,nullNode,'i'
    };

    binaryTree_Hero<char> tree(15);
    tree.CreateTree(a,15,nullNode);
    tree.preOrderTraversal();
    std::cout << std::endl;

    tree.inOrderTraversal();
    std::cout << std::endl;

    tree.postOrderTraversal();
    std::cout << std::endl;
}