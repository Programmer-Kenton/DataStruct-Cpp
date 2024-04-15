/**
 * @Description 长度为3且各个字符不同的子字符串
 * @Version 1.0.0
 * @Date 2024/4/14 19:27
 * @Author Kenton
 */

#include "iostream"

int countGoodSubstrings(std::string& s){
    int len = s.size();
    int cnt = 0;
    for (int i = 0; i < len - 2; ++i) {
        int a = s[i];
        int b = s[i+1];
        int c = s[i+2];
        if (a != b && b != c && a != c){
            ++cnt;
        }
    }
    return cnt;
}