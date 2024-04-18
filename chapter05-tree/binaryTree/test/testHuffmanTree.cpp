/**
 * @Description 哈夫曼树实现
 * @Version 1.0.0
 * @Date 2024/4/15 21:37
 * @Author Kenton
 */

#include "../head/huffmanTree.h"

int main() {
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    // 创建哈夫曼树对象
    huffmanTree tree;

    // 构建哈夫曼树
    tree.buildTree(characters, frequencies);

    // 打印哈夫曼编码
    tree.printHuffmanCodes();

    return 0;
}