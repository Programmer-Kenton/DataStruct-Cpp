/**
 * @Description C++实现哈夫曼树
 * @Version 1.0.0
 * @Date 2024/4/15 21:32
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_HUFFMANTREE_H
#define INC_08WANGDAO_HUFFMANTREE_H

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 定义哈夫曼树的节点结构
struct HuffmanNode {
    // 存储字符
    char data;
    // 字符出现的频率
    int frequency;
    // 左右子节点
    HuffmanNode *left, *right;

    // 构造函数
    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// 比较器，用于优先队列排序
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b);
};


class huffmanTree {

private:
    HuffmanNode* root;

public:
    // 构造函数
    huffmanTree();

    // 析构函数
    ~huffmanTree();

    // 清空树
    void clear(HuffmanNode* node);

    // 构建哈夫曼树
    void buildTree(vector<char>& characters, vector<int>& frequencies);

    // 打印哈夫曼编码
    void printCodes(HuffmanNode* node, string code);

    // 打印哈夫曼编码的入口函数
    void printHuffmanCodes();
};


#endif //INC_08WANGDAO_HUFFMANTREE_H
