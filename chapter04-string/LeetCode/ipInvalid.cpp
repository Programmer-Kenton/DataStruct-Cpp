/**
 * @Description ip地址无效化
 * @Version 1.0.0
 * @Date 2024/4/14 19:43
 * @Author Kenton
 */

#include "iostream"

std::string addr_Invalid(std::string address){
    std::string s = "";
    for (int i = 0; i < address.size(); ++i) {
        if (address[i] == '.'){
            s += '[.]';
        } else{
            s += address[i];
        }
    }
    return s;
}