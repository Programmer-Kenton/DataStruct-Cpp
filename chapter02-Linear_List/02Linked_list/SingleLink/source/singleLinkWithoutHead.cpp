/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/30 13:00
 * @Author Kenton
 */

#include "../head/singleLinkWithoutHead.h"

void singleLink::InitList() {
    this->head = NULL;
    this->size = 0;
}

bool singleLink::List_TailInsert() {
    ElemType e;
    std::cout << "请输入要插入的元素值 输入100结束输入:" << std::endl;
    std::cin >> e;

    while (e != 100){
        ListNode *newNode = new ListNode(e);
        if (!newNode){
            std::cerr << "Memory allocation failure for new node";
            return false;
        }
        if (isEmpty()){
            // 当链表为空 新插入的结点成为头结点
            head = newNode;
        } else{
            // 在已又链表尾部插入新结点
            ListNode *curr = head;
            while (curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = newNode;

        }
        ++size;
        std::cin >> e;
    }
    return true;
}

bool singleLink::List_HeadInsert() {
    ElemType e;
    std::cout << "请输入要插入的元素值 输入100结束输入:" << std::endl;
    std::cin >> e;

    while (e != 100){
      ListNode *newNode = new ListNode(e);
        if (!newNode){
            std::cerr << "Memory allocation failure for new node";
            return false;
        }
        if (isEmpty()){
            head = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
        ++size;
        std::cin >> e;
    }

    return true;
}

bool singleLink::List_Inverse() {
    if (isEmpty()) {
        return false;
    }

    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        // 保存下一个节点的指针
        next = current->next;
        // 反转指针
        current->next = prev;
        // 移动 prev 到当前节点
        prev = current;
        // 移动 current 到下一个节点
        current = next;
    }

    head = prev; // 更新头指针
    return true;
}

singleLink::singleLink():size(0),head(NULL) {
    InitList();
}

singleLink::~singleLink() {
    ListNode *curr = head;
    while (curr != NULL) {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }
    head = NULL;
    size = 0;
}

bool singleLink::isEmpty() {
    return head == NULL;
}

bool singleLink::ListInsert(int i, ElemType e) {
    if (i < 1 || (i > 1 && head == NULL)) {
        // 插入的位置不合法必须从1开始，或者插入的位置合法大于1但链表头结点为空即没有数据，必须从头结点开始插
        return false;
    }

    // 不带头结点的单链表插入在第一个位置插入元素
    if (i == 1){
        ListNode *newNode = new ListNode(e);
        newNode->next = head;
        head = newNode;
        ++size;
        return true;
    }


    // 在第一个位置之后的节点插入元素
    ListNode *curr = GetNode(i - 1);

    return InsertNextNode(curr,e);
}

bool singleLink::InsertNextNode(ListNode* p, ElemType e) {
    if (p == NULL || head == NULL) {
        // 如果p为空，无法插入
        return false;
    }
    ListNode *newNode = new ListNode(e);
    if (newNode == nullptr) {
        // 内存分配失败
        std::cerr << "Memory allocation failure for new node";
        return false;
    }
    // 将新节点的next指向p的下一个节点
    newNode->next = p->next;
    // 将p的next指向新节点
    p->next = newNode;
    // 链表长度增加
    ++size;
    return true;
}

bool singleLink::InsertPriorNode(ListNode* p, ElemType e) {
    if (p == NULL || head == NULL) {
        // 传入空指针
        return false;
    }
    if (p == head) {
        // 在不带头结点的链表第一个位置插入
        return ListInsert(1,e);
    }
    ListNode *curr = head;
    while (curr != NULL && curr->next != p) {
        curr = curr->next;
    }
    if (curr == NULL) {
        // 没有找到p的前一个结点 说明p不在链表中
        return false;
    }
    ListNode *newNode = new ListNode(e);
    if (!newNode) {
        std::cerr << "Memory allocation failure for new node";
        return false;
    }
    newNode->next = p;
    curr->next = newNode;
    ++size;
    return true;
}

bool singleLink::ListDelete(int i, ElemType& e) {
    if (i < 1 || isEmpty()) {
        return false;
    }

    // 删除第一个结点
    if (i == 1){
        ListNode *temp = head->next;
        e = head->data;
        delete head;
        head = temp;
        size--;
        return true;
    }



    // 找到被删除结点的前一个结点
    ListNode *curr = GetNode(i - 1);

    if (curr == NULL) {
        return false;
    }
    if (curr->next == NULL) {
        return false;
    }

    ListNode *temp = curr->next;
    e = temp->data;
    curr->next = temp->next;
    delete temp;
    size--;
    return true;
}

bool singleLink::DeleteNode(ListNode* p) {
    if (p == NULL || head == nullptr) {
        return false;
    }


    if (p == head){
        ListNode *temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    ListNode *curr = head;
    while (curr != nullptr && curr->next != p){
        curr = curr->next;
    }

    // 如果没有找到要删除的结点或者已经是最后一个结点
    if (curr == nullptr || curr->next == nullptr){
        return false;
    }

    ListNode *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    size--;
    return true;
}

ElemType singleLink::GetElem(int i) {
    if (i < 1 || isEmpty()) {
        std::cerr << "索引超出范围";
        return -1;
    }
    ListNode *curr = head;
    for (int j = 0; j < i - 1 && curr != NULL; ++j) {
        curr = curr->next;
    }
    if (curr == NULL) {
        std::cerr << "索引超出范围";
        return -1;
    }
    return curr->data;
}

ListNode* singleLink::GetNode(int i) {
    if (i < 0) {
        return NULL;
    }
    ListNode *curr = head;
    int j = 0;
    while (curr != NULL && j < i - 1) {
        curr = curr->next;
        j++;
    }
    // 如果越界 没有找到也是返回NULL
    return curr;
}

ListNode* singleLink::LocateNode(ElemType e) {
    ListNode *curr = head;
    while (curr != NULL && curr->data != e) {
        curr = curr->next;
    }
    // 返回找到的节点或NULL（表示未找到）
    return curr;
}

void singleLink::getSize() {
    std::cout << "链表尺寸 size = " << size << std::endl;
}

void singleLink::printList() {
    ListNode *curr = head;
    while (curr != NULL) {
        std::cout << curr->data << ' ';
        curr = curr->next;
    }
    std::cout << std::endl;
    getSize();
}
