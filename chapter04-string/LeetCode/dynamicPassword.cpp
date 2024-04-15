/**
 * @Description 动态口令
 * @Version 1.0.0
 * @Date 2024/4/14 19:59
 * @Author Kenton
 */

#include "iostream"

std::string dynamicPassword(std::string& password,int target){
    std::string str = "";
    std::string temp = "";
    for (int i = 0; i < target; ++i) {
        temp[i] = password[i];
    }
    for (int j = target; j < password.size(); ++j) {
        str[j] = password[j];
    }
    return str += temp;
}