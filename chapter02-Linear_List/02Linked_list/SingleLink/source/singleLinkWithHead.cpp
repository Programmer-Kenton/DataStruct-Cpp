/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/30 12:38
 * @Author Kenton
 */
#include "../head/singleLinkWithHead.h"


void singleLink::InitList() {
    // ʹ��NULL��Ϊͷ�������� ͷ��㲻�洢����
    head = new ListNode(NULL);
    if (!head) {
        throw "Memory allocation failure for head node";
    }
    // ͷ������һ�����Ϊ�� �ڽṹ�幹���Ѿ�����
    size = 0;
}

bool singleLink::List_TailInsert() {
    ListNode *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    ElemType e;
    std::cout << "������Ҫ�����Ԫ��ֵ ����100��������:" << std::endl;
    std::cin >> e;
    // ����100 ���ٽ���������
    while (e != 100) {
        ListNode *newNode = new ListNode(e);
        curr->next = newNode;
        curr = newNode;
        size++;
        std::cin >> e;
    }
    // �ṹ��ÿ����һ������Զ����Ӻ���ΪNULL ����ֱ�ӷ���
    return true;
}

bool singleLink::List_HeadInsert() {
    ElemType e;
    std::cout << "������Ҫ�����Ԫ��ֵ ����100��������:" << std::endl;
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
    // ָ��ǰһ����� ��ʼ��Ϊ��
    ListNode *prev = NULL;
    // ����ǰ��� ��ʼ��Ϊͷ������һ�����
    ListNode *curr = head->next;
    // �����ݴ�curr����һ�����
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
        // ���pΪ�� ˵��û���ҵ���Ч�Ĳ���λ��
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


    // �ҵ���ɾ������ǰһ�����
    ListNode *curr = GetNode(i - 1);

    // ��ɾ������ǰһ�����Ϊ��
    if (curr == NULL) {
        // �����������û���ҵ�ָ��λ�� ��ɾ����λ�ò��Ϸ�
        return false;
    }

    if (curr->next == NULL) {
        // ��i-1���֮�������������
        return false;
    }

    // tempָ��ɾ���Ľ��
    ListNode *temp = curr->next;
    // e���ձ�ɾ�����洢������
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
    // ���Խ�� û���ҵ�Ҳ�Ƿ���NULL
    return curr;
}

ListNode* singleLink::LocateNode(ElemType e) {
    ListNode *curr = head;
    // �ӵ�һ����㿪ʼ����������Ϊe�Ľ��
    while (curr != NULL && curr->data != e) {
        curr = curr->next;
    }
    // �ҵ��󷵻ظý��ָ��
    return curr;
}

void singleLink::getSize() {
    std::cout << "����ߴ� size = " << size << std::endl;
}


void singleLink::printList() {
    // ����ͷ���
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
