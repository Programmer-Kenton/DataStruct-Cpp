/**
 * @Description 利用栈实现括号匹配
 * @Version 1.0.0
 * @Date 2024/4/8 9:43
 * @Author Kenton
 */

#include "../head/LinkStack.h"
#include "stack"

bool isMatch(char left,char right){
    return left == '(' && right == ')' ||
           left == '[' && right == ']' ||
           left == '{' && right == '}';
}

bool bracketCheck(std::string str,int length){
    std::stack<char> stk;
    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] =='{'){
            stk.push(str[i]);
        } else{
            if (stk.empty()){
                return false;
            }
            if (!isMatch(stk.top(),str[i])){
                return false;
            }
            stk.pop();
        }
    }
    return true;
}

int main(){
    std::string str = "{{{{{(){}{}()()[[[]]]{}";
    int length = str.length();

    std::cout << bracketCheck(str,length);
}