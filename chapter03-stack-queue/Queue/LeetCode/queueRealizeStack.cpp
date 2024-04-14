/**
 * @Description 队列实现栈
 * @Version 1.0.0
 * @Date 2024/4/11 21:39
 * @Author Kenton
 */

#include "queue"

class MyStack{
public:
    std::queue<int> q1,q2;

    MyStack() {}

    void push(int x){
        q1.push(x);
    }

    int pop(){
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return result;
    }

    int top(){
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        q2.push(result);
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return result;
    }

    bool empty(){
        return q1.empty();
    }

};