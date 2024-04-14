/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/11 21:52
 * @Author Kenton
 */

#include "../head/linkString.h"

void linkString::InitStr() {
    head = new StringNode;
    if (!head) {
        throw std::runtime_error("Memory allocation failed for head node!");
    }
    head->next = nullptr;
    // 初始化头结点为空字符串
    head->ch[0] = '\0';
}

linkString::linkString() : head(nullptr) {
    InitStr();
}

/**
 * 赋值操作 将当前串的内容赋值给chars字符数组
 * @param chars
 */
void linkString::StrAssign(char *chars) const {
    size_t len = strnlen(chars, std::numeric_limits<size_t>::max());
    if (len == 0) {
        // 如果chars是空字符串 直接返回
        return;
    }
    StringNode *curr = head->next;
    size_t copied = 0;
    while (curr && copied < len) {
        size_t nodeLen = strnlen(curr->ch, 4);
        strncpy(chars + copied, curr->ch, nodeLen);
        copied += nodeLen;
        curr = curr->next;
    }
    // 如果chars数组足够大 确保它以null结尾
    chars[std::min(len, copied)] = '\0';
}

void linkString::StrCopy(linkString &T) {
    // 清空当前串
    ClearString();
    StringNode *p = T.head->next;
    while (p) {
        StringNode *newNode = new StringNode;
        if (!newNode) {
            throw std::runtime_error("Memory allocation failed for new node!");
        }
        // 假设p->ch已经以null结尾
        strncpy(newNode->ch, p->ch, 4);
        newNode->next = head->next;
        head->next = newNode;
        p = p->next;
    }
}

bool linkString::StrEmpty() {
    return head->next == nullptr;
}

size_t linkString::StrLength() {
    size_t length = 0;
    StringNode *p = head->next;
    while (p){
        // 累加每个节点的字符数（不包括结尾的null）
        length += strnlen(p->ch, 4);
        p = p->next;
    }
    return length;
}

void linkString::ClearString() {
    StringNode *p = head->next;
    while (p){
        StringNode *tmp = p;
        p = p->next;
        delete tmp;
    }
    // 将头结点的next指向null
    head->next = nullptr;
}

linkString::~linkString() {
    // 释放所有节点
    ClearString();
    // 释放头结点
    delete head;
}

void linkString::Concat(linkString &T, linkString S2) {
    StringNode *p = S2.head->next;
    while (p){
        StringNode *newNode = new StringNode;
        if (!newNode){
            throw std::runtime_error("Memory allocation failed for concatenation!");
        }
        // 复制S2的当前结点
        strncpy(newNode->ch,p->ch,4);
        newNode->next = nullptr;

        // 查找T的末尾
        StringNode *q = T.head;
        while (q->next){
            q->next;
        }
        // 将新节点添加到T的末尾
        q->next = newNode;
        // 继续处理S2的下一个节点
        p = p->next;
    }
}

bool linkString::SubString(linkString &Sub, int pos, int len) {
    if (pos < 1 || len <= 0 || pos + len - 1 > StrLength()){
        // 位置或长度无效
        return false;
    }
    // 初始化字串
    Sub.InitStr();
    StringNode *curr = head->next;
    // 移动到开始位置
    for (int i = 0; i < pos - 1; ++i) {
        if (!curr) return false;
        curr = curr->next;
    }
    for (int i = 0; i < len && curr; ++i) {
        StringNode *newNode = new StringNode;
        if (!newNode){
            throw std::runtime_error("Memory allocation failed for substring!");
        }
        // 每个节点至多4个字符
        strncpy(newNode->ch,curr->ch,4);
        // 确保字符串以null结尾
        newNode->ch[4] = '\0';
        newNode->next = Sub.head->next;
        Sub.head->next = newNode;
        curr = curr->next;
    }
    return true;
}

int linkString::StrCompare(linkString T) const {
    StringNode *p1 = this->head->next;
    StringNode *p2 = T.head->next;
    while (p1 && p2){
        int cmp = strncmp(p1->ch,p2->ch,3);
        if (cmp != 0){
            return cmp;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    // 如果一个字符串是另一个字符串的前缀，则较短的字符串较小
    return (p1 == nullptr) ? (p2 == nullptr) ? 0 : -1 : 1;
}

int linkString::Index(linkString T) {
    StringNode *p = this->head->next;
    StringNode *q = T.head->next;
    while (p) {
        StringNode *p_temp = p;
        StringNode *q_temp = q;
        bool found = true;
        while (q_temp && p_temp) {
            if (strncmp(p_temp->ch, q_temp->ch, 3) != 0) {
                found = false;
                break;
            }
            p_temp = p_temp->next;
            q_temp = q_temp->next;
        }
        if (found && !q_temp) {
            // 如果找到了与T匹配的子串
            return (p == this->head->next) ? 1 : (StrLengthFrom(this->head, p) + 1);
        }
        p = p->next;
    }
    // 没有找到
    return -1;
}

size_t linkString::StrLengthFrom(StringNode *head, StringNode *p) {
    size_t length = 0;
    StringNode *current = head->next;
    while (current != p) {
        length += strnlen(current->ch, 4);
        current = current->next;
    }
    return length;
}

