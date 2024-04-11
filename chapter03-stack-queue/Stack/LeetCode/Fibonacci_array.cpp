/**
 * @Description 递归实现斐波那契数列
 * @Version 1.0.0
 * @Date 2024/4/11 16:41
 * @Author Kenton
 */

#include "iostream"

unsigned long long fibonacci_recursive(int n){
    if (n <= 1){
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main(){
    unsigned long long int res = fibonacci_recursive(8);

    std::cout << res << std::endl;
}