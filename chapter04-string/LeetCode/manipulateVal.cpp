/**
 * @Description 执行操作后的变量值
 * @Version 1.0.0
 * @Date 2024/4/14 19:38
 * @Author Kenton
 */

#include "iostream"
#include "vector"

int finalValueAfterOperations(std::vector<std::string>& operators){
    int X = 0;
    for (int i = 0; i < operators.size(); ++i) {
        std::string s = operators[i];
        if (s[i] == '+'){
            X++;
        } else{
            X--;
        }
    }
    return X;
}