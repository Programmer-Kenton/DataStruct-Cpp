/**
 * @Description TODO 计算中缀表达式
 * @Version 1.0.0
 * @Date 2024/4/11 16:00
 * @Author Kenton
 */


#include <iostream>
#include <string>
#include <cctype>

int calculateInfix(const std::string& infixExpr, size_t& pos) {
    int result;
    char op;

    if (pos >= infixExpr.size()) {
        throw std::runtime_error("Invalid expression");
    }

    // 处理数字
    if (isdigit(infixExpr[pos])) {
        result = infixExpr[pos++] - '0';
        while (pos < infixExpr.size() && isdigit(infixExpr[pos])) {
            result = 10 * result + infixExpr[pos++] - '0';
        }
        return result;
    }

    // 处理左括号
    if (infixExpr[pos] == '(') {
        ++pos;
        result = calculateInfix(infixExpr, pos);
        if (infixExpr[pos] != ')') {
            throw std::runtime_error("Missing closing parenthesis");
        }
        ++pos;
        return result;
    }

    // 处理操作符
    op = infixExpr[pos++];
    if (pos >= infixExpr.size()) {
        throw std::runtime_error("Invalid expression");
    }

    int right = calculateInfix(infixExpr, pos);
    int left = calculateInfix(infixExpr, pos);

    switch (op) {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/': result = left / right; break;
        default: throw std::runtime_error("Unknown operator");
    }

    return result;
}

int main() {
    std::string infixExpr = "3 * 4 + 5 / 2";
    size_t pos = 0;
    try {
        int result = calculateInfix(infixExpr, pos);
        if (pos != infixExpr.size()) {
            throw std::runtime_error("Invalid expression");
        }
        std::cout << "Infix expression: " << infixExpr << std::endl;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}