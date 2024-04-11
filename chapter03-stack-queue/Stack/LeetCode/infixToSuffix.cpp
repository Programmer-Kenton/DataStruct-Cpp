/**
 * @Description TODO 中缀转后缀及后缀计算
 * @Version 1.0.0
 * @Date 2024/4/11 14:15
 * @Author Kenton
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>

// 判断字符是否为操作符
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 比较两个操作符的优先级 -1:op1>op2 0:op1=op2 1:op1<op2
int comparePrecedence(char op1,char op2){
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')){
        return -1;
    } else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')){
        return 1;
    } else{
        return 0;
    }
}

// 中缀表达式转后缀表达式
std::string infixToPostfix(const std::string& infixExpr){
    std::string postfixExpr;
    std::stack<char> operatorStack;

    for (char c:infixExpr) {
        // 遇到空格跳过
        if (isspace(c)) continue;
        // 遇到数字直接添加到后缀表达式
        if (isdigit(c)){
            postfixExpr += c;
        } else if (isOperator(c)){
            // 遇到操作符 先弹出所有优先级高于当前操作符的栈顶操作符
            while (!operatorStack.empty() && comparePrecedence(operatorStack.top(),c) != 1){
                postfixExpr += operatorStack.top();
                operatorStack.pop();
            }
            // 将当前操作符压入栈中
            operatorStack.push(c);
        } else if (c == '('){
            // 遇到左括号直接压入栈
            operatorStack.push(c);
        } else if (c == ')'){
            // 遇到右括号 将栈中所有元素弹出并添加到后缀表达式 直到遇到左括号
            while (operatorStack.top() != '('){
                postfixExpr += operatorStack.top();
                operatorStack.pop();
            }
            // 弹出左括号 不添加到后缀表达式
            operatorStack.pop();
        }
    }
    // 将栈中剩余的操作符全部弹出并添加到后缀表达式
    while (!operatorStack.empty()){
        postfixExpr += operatorStack.top();
        operatorStack.pop();
    }
    return postfixExpr;
}

// 计算后缀表达式的值
int calculatePostfix(const std::string& postfixExpr){
    std::stack<int> operandStack;
    for(char c : postfixExpr){
        if (isdigit(c)){
            // 将字符串转换为整数压入栈
            operandStack.push(c - '0');
        } else{
            int operand2 = operandStack.top(); operandStack.pop();
            int operand1 = operandStack.top(); operandStack.pop();

            switch (c) {
                case '+': operandStack.push(operand1 + operand2); break;
                case '-': operandStack.push(operand1 - operand2); break;
                case '*': operandStack.push(operand1 * operand2); break;
                case '/': operandStack.push(operand1 / operand2); break;
            }
        }
    }
    return operandStack.top();
}

int main(){
    std::string infixExpr = "3 * 4 + 5 / 2";
    std::string postfixExpr = infixToPostfix(infixExpr);
    std::cout << "Infix expression: " << infixExpr << std::endl;
    std::cout << "Postfix expression: " << postfixExpr << std::endl;
    std::cout << "Result: " << calculatePostfix(postfixExpr) << std::endl;
}