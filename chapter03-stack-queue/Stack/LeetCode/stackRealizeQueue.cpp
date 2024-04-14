/**
 * @Description 栈实现队列
 * @Version 1.0.0
 * @Date 2024/4/11 21:25
 * @Author Kenton
 */

#include "stack"

class MyQueue{
private:
    std::stack<int> s1,s2;

public:

    MyQueue() {}

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    int peek(){
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
};