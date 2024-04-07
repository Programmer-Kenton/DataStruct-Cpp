/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 16:45
 * @Author Kenton
 */

#include "iostream"
#include "stack"

bool isLeft(char c){
    return c == '(' || c == '[' || c == '{';
}

bool isMatch(char left,char right){
    return left == '(' && right == ')' ||
    left == '[' && right == ']' ||
    left == '{' && right == '}';
}

bool isValid(std::string s){
    std::stack<char> stk;
    for (int i = 0; i < stk.size(); ++i) {
        if (isLeft(s[i])){
            stk.push(s[i]);
        } else{
            if (stk.empty()){
                return false;
            }
            if (!isMatch(stk.top(),s[i])){
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::string s = "{{[]{{{}}}}}";

    std::cout << isValid(s);
}