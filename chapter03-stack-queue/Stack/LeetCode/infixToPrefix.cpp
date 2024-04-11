/**
 * @Description TODO 中缀转前缀及前缀表达式的计算
 * @Version 1.0.0
 * @Date 2024/4/11 15:51
 * @Author Kenton
 */


#include <iostream>
#include <stack>
#include <string>
#include <cctype>


// 判断字符是否为操作符
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 比较两个操作符的优先级，返回值为：
//   -1：op1优先级高于op2
//    0：op1与op2优先级相同
//    1：op1优先级低于op2
int comparePrecedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        return -1;
    } else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {
        return 1;
    } else {
        return 0;
    }
}

// 中缀表达式转前缀表达式
std::string infixToPrefix(const std::string& infixExpr) {
    std::string prefixExpr;
    std::stack<char> operatorStack;

    for (int i = infixExpr.size() - 1; i >= 0; --i) {
        char c = infixExpr[i];
        if (isspace(c)) continue;

        if (isdigit(c)) {
            prefixExpr += c;
        } else if (isOperator(c)) {
            // 遇到操作符，先弹出所有优先级高于当前操作符的栈顶操作符
            while (!operatorStack.empty() && comparePrecedence(operatorStack.top(), c) != 1) {
                prefixExpr += operatorStack.top();
                operatorStack.pop();
            }
            // 将当前操作符压入栈
            operatorStack.push(c);
        } else if (c == ')') {
            // 遇到右括号直接压入栈
            operatorStack.push(c);
        } else if (c == '(') {
            // 遇到左括号，将栈中所有元素弹出并添加到前缀表达式，直到遇到右括号
            while (operatorStack.top() != ')') {
                prefixExpr += operatorStack.top();
                operatorStack.pop();
            }
            // 弹出右括号，不添加到前缀表达式
            operatorStack.pop();
        }
    }

    // 将栈中剩余的操作符全部弹出并添加到前缀表达式
    while (!operatorStack.empty()) {
        prefixExpr += operatorStack.top();
        operatorStack.pop();
    }

    return prefixExpr;
}

// 计算前缀表达式的结果
int calculatePrefix(const std::string& prefixExpr) {
    std::stack<int> operandStack;

    for (char c : prefixExpr) {
        if (isdigit(c)) {
            operandStack.push(c - '0');  // 将字符转换为整数并压入栈
        } else {
            int operand1 = operandStack.top(); operandStack.pop();
            int operand2 = operandStack.top(); operandStack.pop();

            switch (c) {
                case '+': operandStack.push(operand2 + operand1); break;
                case '-': operandStack.push(operand2 - operand1); break;
                case '*': operandStack.push(operand2 * operand1); break;
                case '/': operandStack.push(operand2 / operand1); break;
            }
        }
    }

    return operandStack.top();
}


int main() {
    std::string infixExpr = "3 * 4 + 5 / 2";
    std::string prefixExpr = infixToPrefix(infixExpr);
    std::cout << "Infix expression: " << infixExpr << std::endl;
    std::cout << "Prefix expression: " << prefixExpr << std::endl;
    std::cout << "Result: " << calculatePrefix(prefixExpr) << std::endl;

    return 0;
}