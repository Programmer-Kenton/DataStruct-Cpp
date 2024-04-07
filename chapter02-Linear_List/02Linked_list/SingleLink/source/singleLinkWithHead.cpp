/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/30 12:38
 * @Author Kenton
 */
#include "../head/singleLinkWithHead.h"


void singleLink::InitList() {
    // 使用NULL作为头结点的数据 头结点不存储数据
    head = new ListNode(NULL);
    if (!head) {
        throw "Memory allocation failure for head node";
    }
    // 头结点的下一个结点为空 在结构体构造已经声明
    size = 0;
}

bool singleLink::List_TailInsert() {
    ListNode *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    ElemType e;
    std::cout << "请输入要插入的元素值 输入100结束输入:" << std::endl;
    std::cin >> e;
    // 输入100 不再建立单链表
    while (e != 100) {
        ListNode *newNode = new ListNode(e);
        curr->next = newNode;
        curr = newNode;
        size++;
        std::cin >> e;
    }
    // 结构体每生成一个结点自动连接后置为NULL 这里直接返回
    return true;
}

bool singleLink::List_HeadInsert() {
    ElemType e;
    std::cout << "请输入要插入的元素值 输入100结束输入:" << std::endl;
    std::cin >> e;
    ListNode *curr = head;
    while (e != 100) {
        ListNode *newNode = new ListNode(e);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
        std::cin >> e;
    }
    return true;
}

bool singleLink::List_Inverse() {
    // 指向前一个结点 初始化为空
    ListNode *prev = NULL;
    // 处理当前结点 初始化为头结点的下一个结点
    ListNode *curr = head->next;
    // 用于暂存curr的下一个结点
    ListNode *next;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
    return true;
}

singleLink::singleLink() : head(NULL), size(0) {
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
    return size == 0;
}

bool singleLink::ListInsert(int i, ElemType e) {
    if(i < 1 || i > size + 1) {
        return false;
    }

    ListNode *curr = GetNode(i - 1);

    return InsertNextNode(curr,e);

}

bool singleLink::InsertNextNode(ListNode* p, ElemType e) {
    if (p == NULL) {
        // 如果p为空 说明没有找到有效的插入位置
        return false;
    }
    ListNode *newNode = new ListNode(e);
    if (!newNode) {
        std::cerr << "Memory allocation failure for new node";
        return false;
    }
    newNode->next = p->next;
    p->next = newNode;
    ++size;
    return true;
}

bool singleLink::InsertPriorNode(ListNode* p, ElemType e) {
    if (p == NULL || p == head) {
        return false;
    }
    ListNode *newNode = new ListNode(e);
    if (!newNode) {
        std::cerr << "Memory allocation failure for new node";
        return false;
    }
    newNode->next = p->next;
    p->next = newNode;
    newNode->data = p->data;
    p->data = e;
    ++size;
    return true;
}

bool singleLink::ListDelete(int i, ElemType& e) {
    if (i < 1) {
        return false;
    }


    // 找到被删除结点的前一个结点
    ListNode *curr = GetNode(i - 1);

    // 待删除结点的前一个结点为空
    if (curr == NULL) {
        // 链表遍历结束没有找到指定位置 即删除的位置不合法
        return false;
    }

    if (curr->next == NULL) {
        // 第i-1结点之后已无其他结点
        return false;
    }

    // temp指向被删除的结点
    ListNode *temp = curr->next;
    // e接收被删除结点存储的数据
    e = temp->data;
    curr->next = temp->next;
    delete temp;
    size--;
    return true;
}

bool singleLink::DeleteNode(ListNode* p) {
    if (p == NULL || p == head || p->next == NULL) {
        return false;
    }
    ListNode *temp = p->next;
    p->data = p->next->data;
    p->next = temp->next;
    delete temp;
    size--;
    return true;
}

ElemType singleLink::GetElem(int i) {
    if (i < 1) {
        return false;
    }
    ListNode *curr = head;
    int j = 0;
    while (curr != NULL && j < i) {
        curr = curr->next;
        j++;
    }
    return curr->data;
}

ListNode* singleLink::GetNode(int i) {
    if (i < 0) {
        return NULL;
    }
    ListNode *curr = head;
    int j = 0;
    while (curr != NULL && j < i) {
        curr = curr->next;
        j++;
    }
    // 如果越界 没有找到也是返回NULL
    return curr;
}

ListNode* singleLink::LocateNode(ElemType e) {
    ListNode *curr = head;
    // 从第一个结点开始查找数据域为e的结点
    while (curr != NULL && curr->data != e) {
        curr = curr->next;
    }
    // 找到后返回该结点指针
    return curr;
}

void singleLink::getSize() {
    std::cout << "链表尺寸 size = " << size << std::endl;
}


void singleLink::printList() {
    // 跳过头结点
    ListNode *curr = head->next;
    while (curr != NULL) {
        std::cout << curr->data << ' ';
        curr = curr->next;
    }
    std::cout << std::endl;
    getSize();
}

ElemType singleLink::Sum() {
    ListNode *curr = head;
    ElemType sum = 0;
    while (curr != nullptr){
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

void singleLink::append(ElemType e) {
    ListInsert(size,e);
}

void singleLink::ascInsert(ElemType e) {
    if (size == 0){
        ListInsert(0,e);
        return;
    }

    ListNode *curr = head;

    for (int i = 0; i < size; ++i) {
        if (e <= curr->data){
            ListInsert(i,e);
            return;
        }
        curr = curr->next;
    }
    ListInsert(size,e);
}
