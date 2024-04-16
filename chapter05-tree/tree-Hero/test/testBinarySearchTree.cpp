/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/16 19:10
 * @Author Kenton
 */

#include "../head/binarySearchTree.h"

int main(){
    binarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(80);
    bst.insert(80);
    bst.insert(80);
    bst.insert(60);
    bst.insert(100);

    bst.inOrderTraversal();


    bst.remove(70);
    bst.inOrderTraversal();

    bst.insert(65);
    bst.inOrderTraversal();

    bst.search(65);
}