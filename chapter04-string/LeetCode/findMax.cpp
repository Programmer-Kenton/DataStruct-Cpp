/**
 * @Description 查找最大元素
 * 对于输入的每个字符串 查找其中的最大字母 在该字母后面插入字符串max
 * @Version 1.0.0
 * @Date 2024/4/14 18:10
 * @Author Kenton
 */

#include "iostream"
#include "cstring"

int main(){
    std::string s;
    while (std::cin >> s){
        std::string ret = "";
        char maxc = 'a';
        // 先找最大的字符
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > maxc){
                maxc = s[i];
            }
        }
        // 新的字符串接收
        for (int i = 0; i < s.size(); ++i) {
            ret += s[i];
            if (s[i] == maxc){
                ret += "{max}";
            }
        }
        std::cout << ret << std::endl;
    }
}