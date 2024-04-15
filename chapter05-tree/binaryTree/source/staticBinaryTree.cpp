/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/15 14:14
 * @Author Kenton
 */

#include "../head/staticBinaryTree.h"


staticBinaryTree::staticBinaryTree() {
    // 初始化根节点为空指针
    root = nullptr;
}

staticBinaryTree::~staticBinaryTree() {
    destroyTree(root);
}

TreeNode *staticBinaryTree::insertNode(TreeNode *root, int data) {
    // 如果根节点为空，则创建一个新节点并返回
    if (root == nullptr) {
        TreeNode *newNode = new TreeNode();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // 否则，递归地将节点插入到适当的子树中
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void staticBinaryTree::insert(int data) {
    root = insertNode(root, data);
}

TreeNode *staticBinaryTree::deleteNode(TreeNode *root, int data) {
    // 如果根节点为空，则返回空
    if (root == nullptr) return root;

    // 查找要删除的节点
    if (data < root->data) {
        // 如果数据较小，则在左子树中查找
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        // 如果数据较大，则在右子树中查找
        root->right = deleteNode(root->right, data);
    } else {
        // 如果节点只有一个子节点或没有子节点
        if (root->left == nullptr) {
            TreeNode *temp = root->right;
            // 删除节点
            delete root;
            // 返回右子节点（可能为空）
            return temp;
        } else if (root->right == nullptr) {
            TreeNode *temp = root->left;
            // 删除节点
            delete root;
            // 返回左子节点（可能为空）
            return temp;
        }
        // 如果节点有两个子节点
        // 在右子树中找到最小节点
        TreeNode *temp = findMin(root->right);
        // 用最小节点的数据替换当前节点的数据
        root->data = temp->data;
        // 从右子树中删除最小节点
        root->right = deleteNode(root->right, temp->data);
    }
    // 返回更新后的根节点
    return root;
}

TreeNode *staticBinaryTree::findMin(TreeNode *node) {
    // 一直向左遍历，直到左子节点为空
    while (node->left != nullptr) {
        node = node->left;
    }
    // 返回具有最小值的节点
    return node;
}

void staticBinaryTree::remove(int data) {
    root = deleteNode(root, data);
}

void staticBinaryTree::preOrderTraversal(TreeNode *root) {
    if (root != nullptr) {
        // 打印当前节点
        std::cout << root->data << " ";
        // 遍历左子树
        preOrderTraversal(root->left);
        // 遍历右子树
        preOrderTraversal(root->right);
    }
}

void staticBinaryTree::preOrder() {
    inOrderTraversal(root);
    std::cout << std::endl;
}

void staticBinaryTree::inOrderTraversal(TreeNode *root) {
    if (root != nullptr) {
        // 遍历左子树
        inOrderTraversal(root->left);
        // 打印当前节点
        std::cout << root->data << " ";
        // 遍历右子树
        inOrderTraversal(root->right);
    }
}

void staticBinaryTree::inOrder() {
    inOrderTraversal(root);
    std::cout << std::endl;
}

void staticBinaryTree::postOrderTraversal(TreeNode *root) {
    if (root != nullptr) {
        // 遍历左子树
        postOrderTraversal(root->left);
        // 遍历右子树
        postOrderTraversal(root->right);
        // 打印当前节点
        std::cout << root->data << " ";
    }
}

void staticBinaryTree::postOrder() {
    postOrderTraversal(root); // 调用辅助函数
    std::cout << std::endl;
}

int staticBinaryTree::getHeight(TreeNode *root) {
    if (root == nullptr) return 0;
    // 返回左右子树中较大的高度加上1
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

int staticBinaryTree::getHeight() {
    return getHeight(root);
}

bool staticBinaryTree::isEmpty(TreeNode *root) {
    return root == nullptr;
}

bool staticBinaryTree::isEmpty() {
    return isEmpty(root);
}

int staticBinaryTree::getSize(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int staticBinaryTree::getSize() {
    return getSize(root);
}

bool staticBinaryTree::search(int data) {
    TreeNode *curr = root;
    while (curr != nullptr) {
        if (curr->data == data) {
            return true;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}

void staticBinaryTree::destroyTree(TreeNode *root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

TreeNode *staticBinaryTree::getLeftChild(TreeNode *node) {
    return node != nullptr ? node->left : nullptr;
}

TreeNode *staticBinaryTree::getRightChild(TreeNode *node) {
    return node != nullptr ? node->right : nullptr;
}

TreeNode *staticBinaryTree::getRoot() {
    return root;
}

void staticBinaryTree::levelOrder() {
    if (root == nullptr) return;

    // 创建一个队列用于层序遍历
    std::queue<TreeNode *> q;
    // 根结点入队
    q.push(root);

    while (!q.empty()) {
        // 获取队列头部结点
        TreeNode *curr = q.front();
        // 弹出队列头部结点
        q.pop();
        std::cout << curr->data << ' ';

        // 将当前结点的左右子节点入队
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    std::cout << std::endl;
}

TreeNode *staticBinaryTree::buildTreeFromPreIn(std::vector<int> &preorder, std::vector<int> &inorder, int preStart, int inStart,int inEnd) {
    // 边界情况处理
    if (preStart > preorder.size() - 1 || inStart > inEnd) return nullptr;

    // 创建当前节点
    TreeNode* root = new TreeNode();
    // 根据前序遍历序列确定当前节点的数据
    root->data = preorder[preStart];

    // 在中序遍历序列中找到当前节点的位置
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // 递归构建左子树和右子树
    root->left = buildTreeFromPreIn(preorder, inorder, preStart + 1, inStart, inIndex - 1); // 前序序列的下一个节点是左子树的根节点
    root->right = buildTreeFromPreIn(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd); // 前序序列中的右子树的根节点是当前节点的下一个节点

    return root;
}

staticBinaryTree *staticBinaryTree::buildTreeFromPreIn(std::vector<int> &preorder, std::vector<int> &inorder) {
    // 创建二叉树对象
    staticBinaryTree* tree = new staticBinaryTree();
    tree->root = buildTreeFromPreIn(preorder, inorder, 0, 0, inorder.size() - 1); // 调用辅助函数构建二叉树
    return tree;
}

TreeNode *staticBinaryTree::buildTreeFromPostIn(std::vector<int> &postorder, std::vector<int> &inorder, int postStart,int inStart, int inEnd) {
    // 边界情况处理
    if (postStart < 0 || inStart > inEnd) return nullptr;

    // 创建当前节点
    TreeNode* root = new TreeNode();
    // 根据后序遍历序列确定当前节点的数据
    root->data = postorder[postStart];

    // 在中序遍历序列中找到当前节点的位置
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // 递归构建左子树和右子树
    root->left = buildTreeFromPostIn(postorder, inorder, postStart - (inEnd - inIndex) - 1, inStart, inIndex - 1); // 后序序列的前一个节点是左子树的根节点
    root->right = buildTreeFromPostIn(postorder, inorder, postStart - 1, inIndex + 1, inEnd); // 后序序列中的右子树的根节点是当前节点的前一个节点

    return root;
}

staticBinaryTree *staticBinaryTree::buildTreeFromPostIn(std::vector<int> &postorder, std::vector<int> &inorder) {
    // 创建二叉树对象
    staticBinaryTree* tree = new staticBinaryTree();
    // 调用辅助函数构建二叉树
    tree->root = buildTreeFromPostIn(postorder, inorder, postorder.size() - 1, 0, inorder.size() - 1);
    return tree;
}

TreeNode *staticBinaryTree::buildTreeFromLevelIn(std::vector<int> &levelorder, std::vector<int> &inorder) {
    // 空序列的情况处理
    if (levelorder.empty() || inorder.empty()) return nullptr;

    // 根节点指针
    TreeNode* root = nullptr;
    // 辅助队列
    std::queue<TreeNode*> q;

    // 从层序遍历序列中取出第一个节点作为根节点
    root = new TreeNode();
    root->data = levelorder.front();
    // 删除已经处理过的节点
    levelorder.erase(levelorder.begin());
    // 将根节点入队
    q.push(root);

    while (!q.empty()) {
        // 获取队首节点
        TreeNode* current = q.front();
        // 弹出队首节点
        q.pop();

        // 在中序遍历序列中找到当前节点的位置
        int inIndex = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == current->data) {
                inIndex = i;
                break;
            }
        }

        // 构建左子树
        if (inIndex > 0 && std::find(levelorder.begin(), levelorder.end(), inorder[inIndex - 1]) != levelorder.end()) {
            current->left = new TreeNode();
            current->left->data = inorder[inIndex - 1];
            // 删除已处理的节点
            levelorder.erase(std::find(levelorder.begin(), levelorder.end(), inorder[inIndex - 1]));
            // 将左子节点入队
            q.push(current->left);
        }

        // 构建右子树
        if (inIndex < inorder.size() - 1 && std::find(levelorder.begin(), levelorder.end(), inorder[inIndex + 1]) != levelorder.end()) {
            current->right = new TreeNode();
            current->right->data = inorder[inIndex + 1];
            // 删除已处理的节点
            levelorder.erase(std::find(levelorder.begin(), levelorder.end(), inorder[inIndex + 1]));
            // 将右子节点入队
            q.push(current->right);
        }
    }

    return root;
}


