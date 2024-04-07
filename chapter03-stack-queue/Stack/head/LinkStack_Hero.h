/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 14:52
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_LINKSTACK_HERO_H
#define INC_08WANGDAO_LINKSTACK_HERO_H

#include "iostream"


template<typename T>
class LinkStack_Hero {
    struct Node {
        T data;

        Node *next;

        Node(T d) : data(d), next(nullptr) {}
    };

    Node *head;

    int size;

public:
    LinkStack_Hero():head(nullptr),size(0){}

    ~LinkStack_Hero();

    void push(T element);

    T pop();

    T top()const;

    int getSize() const;
};

template<typename T>
int LinkStack_Hero<T>::getSize() const {
    return size;
}

template<typename T>
T LinkStack_Hero<T>::top() const {
    if (head == nullptr){
        throw std::underflow_error("Stack is empty");
    }
    return head->data;
}

template<typename T>
T LinkStack_Hero<T>::pop() {
    if (head == nullptr){
        throw std::underflow_error("Stack is empty");
    }
    T result = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    --size;
    return result;
}

template<typename T>
void LinkStack_Hero<T>::push(T element) {
    Node *newNode = new Node(element);
    // 头插
    newNode->next = head;
    head = newNode;
    ++size;
}

template<typename T>
LinkStack_Hero<T>::~LinkStack_Hero() {
    while (head){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}


#endif //INC_08WANGDAO_LINKSTACK_HERO_H
