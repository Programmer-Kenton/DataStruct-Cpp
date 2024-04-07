/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 15:10
 * @Author Kenton
 */

#include "stack"
#include "iostream"

using namespace std;

int main(){
    stack<int> intStk;
    stack<double> doubleStk;

    intStk.push(1);
    intStk.push(2);
    intStk.push(3);
    intStk.push(4);

    while (!intStk.empty()){
        cout << intStk.top() << ' ';
        intStk.pop();
    }


    doubleStk.push(1.1);
    doubleStk.push(2.2);
    doubleStk.push(3.3);
    doubleStk.push(4.4);

    while (!doubleStk.empty()){
        cout << doubleStk.top() << ' ';
        doubleStk.pop();
    }
}