/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/15 15:59
 * @Author Kenton
 */


#include "../head/linkBinaryTree.h"

linkBinaryTree::linkBinaryTree() {
    root = nullptr; // 初始化根节点为空指针
}

linkBinaryTree::~linkBinaryTree() {
    destroyTree(root); // 调用辅助函数销毁树
}

void linkBinaryTree::destroyTree(TreeNode *root) {
    if (root != nullptr) {
        destroyTree(root->left); // 递归销毁左子树
        destroyTree(root->right); // 递归销毁右子树
        delete root; // 删除当前节点
    }
}

void linkBinaryTree::preOrder() {
    preOrderTraversal(root); // 调用辅助函数
    std::cout << std::endl;
}

void linkBinaryTree::inOrder() {
    inOrderTraversal(root); // 调用辅助函数
    std::cout << std::endl;
}

void linkBinaryTree::postOrder() {
    postOrderTraversal(root); // 调用辅助函数
    std::cout << std::endl;
}

void linkBinaryTree::insert(int data) {
    if (root == nullptr) { // 如果树为空，则创建根节点
        root = new TreeNode(data);
        return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    // 寻找插入位置
    while (current != nullptr) {
        parent = current;
        if (data < current->data) {
            if (!current->leftThread) // 如果左子节点不是线索，继续向左子树搜索
                current = current->left;
            else
                break;
        } else {
            if (!current->rightThread) // 如果右子节点不是线索，继续向右子树搜索
                current = current->right;
            else
                break;
        }
    }

    // 创建新节点并插入到树中
    TreeNode* newNode = new TreeNode(data);
    if (data < parent->data) { // 插入左子树
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = false; // 更新父节点的左线索标记
        parent->left = newNode; // 更新父节点的左子节点
    } else { // 插入右子树
        newNode->left = parent;
        newNode->right = parent->right;
        parent->rightThread = false; // 更新父节点的右线索标记
        parent->right = newNode; // 更新父节点的右子节点
    }
}

void linkBinaryTree::inOrderTraversal(TreeNode *root) {
    TreeNode* current = root;
    while (current != nullptr && !current->leftThread) // 找到中序遍历的起始节点
        current = current->left;

    while (current != nullptr) { // 从起始节点开始中序遍历
        std::cout << current->data << " ";
        if (current->rightThread) // 如果当前节点的右子节点是线索，则直接跳转到后继节点
            current = current->right;
        else { // 否则，找到当前节点的右子树中最左边的节点
            current = current->right;
            while (current != nullptr && !current->leftThread)
                current = current->left;
        }
    }
}

void linkBinaryTree::postOrderTraversal(TreeNode *root) {
    std::stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* prev = nullptr;

    do {
        while (current != nullptr && !current->leftThread) { // 遍历左子树
            stk.push(current);
            current = current->left;
        }

        while (current != nullptr && current->rightThread) { // 处理线索
            std::cout << current->data << " ";
            prev = current;
            if (stk.empty())
                return;
            current = stk.top();
            stk.pop();
        }

        if (current != nullptr && !current->rightThread && current->right != prev) { // 处理右子树
            stk.push(current);
            current = current->right;
        }

    } while (!stk.empty());
}

void linkBinaryTree::inOrderThread(TreeNode *root, TreeNode *&prev) {
    if (root == nullptr)
        return;

    inOrderThread(root->left, prev); // 递归处理左子树

    if (root->left == nullptr) { // 处理左线索
        root->left = prev;
        root->leftThread = true;
    }

    if (prev != nullptr && prev->right == nullptr) { // 处理右线索
        prev->right = root;
        prev->rightThread = true;
    }

    prev = root; // 更新 prev 指针

    inOrderThread(root->right, prev); // 递归处理右子树
}

void linkBinaryTree::inOrderThreaded() {
    TreeNode* prev = nullptr;
    inOrderThread(root, prev); // 调用辅助函数
}

void linkBinaryTree::postOrderThreaded() {
    TreeNode* prev = nullptr;
    postOrderThread(root, prev); // 调用辅助函数
}

void linkBinaryTree::postOrderThread(TreeNode *root, TreeNode *&prev) {
    if (root == nullptr)
        return;

    postOrderThread(root->left, prev); // 递归处理左子树
    postOrderThread(root->right, prev); // 递归处理右子树

    if (root->left == nullptr) { // 处理左线索
        root->left = prev;
        root->leftThread = true;
    }

    if (prev != nullptr && prev->right == nullptr) { // 处理右线索
        prev->right = root;
        prev->rightThread = true;
    }

    prev = root; // 更新 prev 指针
}

void linkBinaryTree::preOrderThread(TreeNode *root, TreeNode *&prev) {
    if (root == nullptr)
        return;

    if (root->left == nullptr) { // 处理左线索
        root->left = prev;
        root->leftThread = true;
    }

    if (prev != nullptr && prev->right == nullptr) { // 处理右线索
        prev->right = root;
        prev->rightThread = true;
    }

    prev = root; // 更新 prev 指针

    if (!root->leftThread) // 处理左子树
        preOrderThread(root->left, prev);

    if (!root->rightThread) // 处理右子树
        preOrderThread(root->right, prev);
}

void linkBinaryTree::preOrderThreaded() {
    TreeNode* prev = nullptr;
    preOrderThread(root, prev); // 调用辅助函数
}

void linkBinaryTree::preOrderTraversal(TreeNode *root) {
    if (root == nullptr)
        return;

    std::stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* current = stk.top();
        stk.pop();
        std::cout << current->data << " ";

        // 先将右子节点压栈，再将左子节点压栈
        if (current->right != nullptr && !current->rightThread)
            stk.push(current->right);
        if (current->left != nullptr && !current->leftThread)
            stk.push(current->left);
    }
}

void linkBinaryTree::remove(int data) {
    TreeNode* current = root;
    TreeNode* parent = nullptr;

    // 寻找待删除节点及其父节点
    while (current != nullptr) {
        if (data == current->data) // 找到待删除节点
            break;

        parent = current;
        if (data < current->data) { // 向左子树搜索
            if (!current->leftThread)
                current = current->left;
            else
                break;
        } else { // 向右子树搜索
            if (!current->rightThread)
                current = current->right;
            else
                break;
        }
    }

    if (current == nullptr) // 树中不存在待删除节点
        return;

    // 情况1：待删除节点是叶子节点
    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr) // 待删除节点是根节点且没有子节点
            root = nullptr;
        else if (current == parent->left) { // 待删除节点是父节点的左子节点
            parent->left = current->left;
            parent->leftThread = true;
        } else { // 待删除节点是父节点的右子节点
            parent->right = current->right;
            parent->rightThread = true;
        }
        delete current;
    }
        // 情况2：待删除节点有一个子节点
    else if (current->left == nullptr || current->right == nullptr) {
        TreeNode* child = (current->left != nullptr) ? current->left : current->right;
        if (parent == nullptr) // 待删除节点是根节点且只有一个子节点
            root = child;
        else if (current == parent->left) { // 待删除节点是父节点的左子节点
            parent->left = child;
            parent->leftThread = false;
        } else { // 待删除节点是父节点的右子节点
            parent->right = child;
            parent->rightThread = false;
        }
        delete current;
    }
        // 情况3：待删除节点有两个子节点
    else {
        // 找到待删除节点的右子树中的最小节点
        TreeNode* successor = current->right;
        while (successor->left != nullptr && !successor->leftThread)
            successor = successor->left;

        int temp = current->data;
        current->data = successor->data;
        successor->data = temp;

        // 递归删除后继节点
        remove(successor->data);
    }
}

TreeNode *linkBinaryTree::leftmost(TreeNode *node) {
    if (node == nullptr)
        return nullptr;
    while (node->left != nullptr && !node->leftThread)
        node = node->left;
    return node;
}

TreeNode *linkBinaryTree::rightmost(TreeNode *node) {
    if (node == nullptr)
        return nullptr;
    while (node->right != nullptr && !node->rightThread)
        node = node->right;
    return node;
}

TreeNode *linkBinaryTree::findInOrderSuccessor(TreeNode *node) {
    // 如果节点为空，返回空指针
    if (node == nullptr)
        return nullptr;

    // 如果节点有右子树，返回右子树中的最左边的节点
    if (!node->rightThread)
        return leftmost(node->right);

    // 如果节点是其父节点的左子树，则后继为其父节点
    if (node->rightThread && node->right != nullptr)
        return node->right;

    // 否则，沿着父节点向上查找，直到找到一个节点是其父节点的左子节点为止
    TreeNode* current = node;
    while (current->rightThread && current->right != nullptr)
        current = current->right;
    if (current->right != nullptr)
        return current->right;
    return nullptr;
}

TreeNode *linkBinaryTree::findInOrderPredecessor(TreeNode *node) {
    // 如果节点为空，返回空指针
    if (node == nullptr)
        return nullptr;

    // 如果节点有左子树，返回左子树中的最右边的节点
    if (!node->leftThread)
        return rightmost(node->left);

    // 如果节点是其父节点的右子树，则前继为其父节点
    if (node->leftThread && node->left != nullptr)
        return node->left;

    // 否则，沿着父节点向上查找，直到找到一个节点是其父节点的右子节点为止
    TreeNode* current = node;
    while (current->leftThread && current->left != nullptr)
        current = current->left;
    if (current->left != nullptr)
        return current->left;
    return nullptr;
}

TreeNode *linkBinaryTree::findPreOrderSuccessor(TreeNode *node) {
    // 如果节点为空，返回空指针
    if (node == nullptr)
        return nullptr;

    // 如果节点有左子树，返回左子树中的最左边的节点
    if (!node->leftThread)
        return leftmost(node->left);

    // 如果节点有右子树，返回右子树的根节点
    if (!node->rightThread)
        return node->right;

    // 否则，沿着父节点向上查找，直到找到一个节点是其父节点的左子节点且其父节点有右子树
    TreeNode* current = node;
    while (current->rightThread && current->right != nullptr) {
        if (!current->rightThread && current->right != nullptr)
            return current->right;
        current = current->right;
    }
    return nullptr;
}

TreeNode *linkBinaryTree::findPreOrderPredecessor(TreeNode *node) {
    // 如果节点为空，返回空指针
    if (node == nullptr)
        return nullptr;

    // 如果节点是其父节点的右子树，返回其父节点
    if (node->left == nullptr && !node->leftThread)
        return node->right;

    // 如果节点有左子树，返回左子树的根节点
    if (!node->leftThread)
        return node->left;

    // 否则，沿着父节点向上查找，直到找到一个节点是其父节点的左子节点且其父节点有右子树
    TreeNode* current = node;
    while (current->rightThread && current->right != nullptr) {
        if (!current->rightThread && current->right != nullptr)
            return current->right;
        current = current->right;
    }
    return nullptr;
}

TreeNode *linkBinaryTree::findPostOrderPredecessor(TreeNode *node) {
    // 如果节点为空，返回空指针
    if (node == nullptr)
        return nullptr;

    // 如果节点是其父节点的左子树，返回其父节点
    if (node->right == nullptr && !node->rightThread)
        return node->left;

    // 如果节点有右子树，返回右子树的根节点
    if (!node->rightThread)
        return node->right;

    // 否则，沿着父节点向上查找，直到找到一个节点是其父节点的右子节点且其父节点有左子树
    TreeNode* current = node;
    while (current->leftThread && current->left != nullptr) {
        if (!current->leftThread && current->left != nullptr)
            return current->left;
        current = current->left;
    }
    return nullptr;
}

TreeNode *linkBinaryTree::findPostOrderSuccessor(TreeNode *node) {
    // 如果节点为空，返回空指针
    if (node == nullptr)
        return nullptr;

    // 如果节点有左子树，返回左子树中的最右边的节点
    if (!node->leftThread)
        return rightmost(node->left);

    // 如果节点是其父节点的右子树，返回其父节点
    if (node->right == nullptr && !node->rightThread)
        return node->right;

    // 否则，沿着父节点向上查找，直到找到一个节点是其父节点的右子节点且其父节点有左子树
    TreeNode* current = node;
    while (current->leftThread && current->left != nullptr) {
        if (!current->leftThread && current->left != nullptr)
            return current->left;
        current = current->left;
    }
    return nullptr;
}

