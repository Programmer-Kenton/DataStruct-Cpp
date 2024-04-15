/**
 * @Description 速算机器人
 * @Version 1.0.0
 * @Date 2024/4/14 19:34
 * @Author Kenton
 */

#include "iostream"

int calculate(std::string s){
    int x = 1;
    int y = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'A'){
            x = 2 * x + y;
        } else{
            y = 2 * y + x;
        }
    }
    return x + y;
}