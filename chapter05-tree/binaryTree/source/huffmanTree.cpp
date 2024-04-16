/**
 * @Description C++实现哈夫曼树
 * @Version 1.0.0
 * @Date 2024/4/15 21:32
 * @Author Kenton
 */
#include "../head/huffmanTree.h"

bool Compare::operator()(HuffmanNode *a, HuffmanNode *b) {
    return a->frequency > b->frequency;
}

huffmanTree::huffmanTree() : root(nullptr){

}

huffmanTree::~huffmanTree() {
    clear(root);
}

void huffmanTree::clear(HuffmanNode *node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void huffmanTree::buildTree(vector<char> &characters, vector<int> &frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // 将每个字符和其对应的频率作为叶子节点插入优先队列
    for (int i = 0; i < characters.size(); ++i) {
        HuffmanNode* node = new HuffmanNode(characters[i], frequencies[i]);
        pq.push(node);
    }

    // 不断合并优先队列中的两个最小频率节点，直到只剩下一个节点，即根节点
    while (pq.size() != 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // 根据优先队列中的最后一个节点构建树
    root = pq.top();
}

void huffmanTree::printCodes(HuffmanNode *node, string code) {
    if (node == nullptr)
        return;

    // 叶子节点时，打印字符和其对应的编码
    if (node->data != '$') {
        cout << node->data << " : " << code << endl;
    }

    // 递归遍历左子树和右子树，构建编码
    printCodes(node->left, code + "0");
    printCodes(node->right, code + "1");
}

void huffmanTree::printHuffmanCodes() {
    cout << "Huffman Codes:" << endl;
    printCodes(root, "");
}
