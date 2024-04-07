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
    std::cout << "������Ҫ�����Ԫ��ֵ ����100��������:" << std::endl;
    std::cin >> e;

    while (e != 100){
        ListNode *newNode = new ListNode(e);
        if (!newNode){
            std::cerr << "Memory allocation failure for new node";
            return false;
        }
        if (isEmpty()){
            // ������Ϊ�� �²���Ľ���Ϊͷ���
            head = newNode;
        } else{
            // ����������β�������½��
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
    std::cout << "������Ҫ�����Ԫ��ֵ ����100��������:" << std::endl;
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
        // ������һ���ڵ��ָ��
        next = current->next;
        // ��תָ��
        current->next = prev;
        // �ƶ� prev ����ǰ�ڵ�
        prev = current;
        // �ƶ� current ����һ���ڵ�
        current = next;
    }

    head = prev; // ����ͷָ��
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
        // �����λ�ò��Ϸ������1��ʼ�����߲����λ�úϷ�����1������ͷ���Ϊ�ռ�û�����ݣ������ͷ��㿪ʼ��
        return false;
    }

    // ����ͷ���ĵ���������ڵ�һ��λ�ò���Ԫ��
    if (i == 1){
        ListNode *newNode = new ListNode(e);
        newNode->next = head;
        head = newNode;
        ++size;
        return true;
    }


    // �ڵ�һ��λ��֮��Ľڵ����Ԫ��
    ListNode *curr = GetNode(i - 1);

    return InsertNextNode(curr,e);
}

bool singleLink::InsertNextNode(ListNode* p, ElemType e) {
    if (p == NULL || head == NULL) {
        // ���pΪ�գ��޷�����
        return false;
    }
    ListNode *newNode = new ListNode(e);
    if (newNode == nullptr) {
        // �ڴ����ʧ��
        std::cerr << "Memory allocation failure for new node";
        return false;
    }
    // ���½ڵ��nextָ��p����һ���ڵ�
    newNode->next = p->next;
    // ��p��nextָ���½ڵ�
    p->next = newNode;
    // ����������
    ++size;
    return true;
}

bool singleLink::InsertPriorNode(ListNode* p, ElemType e) {
    if (p == NULL || head == NULL) {
        // �����ָ��
        return false;
    }
    if (p == head) {
        // �ڲ���ͷ���������һ��λ�ò���
        return ListInsert(1,e);
    }
    ListNode *curr = head;
    while (curr != NULL && curr->next != p) {
        curr = curr->next;
    }
    if (curr == NULL) {
        // û���ҵ�p��ǰһ����� ˵��p����������
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

    // ɾ����һ�����
    if (i == 1){
        ListNode *temp = head->next;
        e = head->data;
        delete head;
        head = temp;
        size--;
        return true;
    }



    // �ҵ���ɾ������ǰһ�����
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

    // ���û���ҵ�Ҫɾ���Ľ������Ѿ������һ�����
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
        std::cerr << "����������Χ";
        return -1;
    }
    ListNode *curr = head;
    for (int j = 0; j < i - 1 && curr != NULL; ++j) {
        curr = curr->next;
    }
    if (curr == NULL) {
        std::cerr << "����������Χ";
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
    // ���Խ�� û���ҵ�Ҳ�Ƿ���NULL
    return curr;
}

ListNode* singleLink::LocateNode(ElemType e) {
    ListNode *curr = head;
    while (curr != NULL && curr->data != e) {
        curr = curr->next;
    }
    // �����ҵ��Ľڵ��NULL����ʾδ�ҵ���
    return curr;
}

void singleLink::getSize() {
    std::cout << "����ߴ� size = " << size << std::endl;
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
