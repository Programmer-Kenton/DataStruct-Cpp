/**
 * @Description 朴素模式匹配
 * @Version 1.0.0
 * @Date 2024/4/19 18:36
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <iostream>
#include <string>
#include <vector>

// 朴素模式匹配算法
std::vector<int> naivePatternMatching(const std::string& text,const std::string& pattern){
    // 存储匹配位置
    std::vector<int> matches;

    // 主串长度
    int m = text.size();
    // 模式串长度
    int n = pattern.size();

    // 在主串中逐个字符进行匹配
    // 如果主串剩下的字符长度小于模式串的长度，那么无需继续匹配，因为剩下的字符长度已经无法容纳整个模式串。
    for (int i = 0; i < m - n; ++i) {
        int j;
        // 逐个字符比较主串和模式串
        for (j = 0; j < n; ++j) {
            if (text[i+j] != pattern[j]){
                // 如果有不匹配的字符 则跳出内循环
                break;
            }
        }
        if (j == n){
            // 如果内循环完成，则说明找到了匹配，将匹配位置存入数组
            matches.push_back(i);
        }
    }
    return matches;
}


int main(){
    std::string text = "ababcabcaabcac";
    std::string pattern = "ab";

    // 调用朴素模式匹配函数
    std::vector<int> match_positions = naivePatternMatching(text, pattern);

    if (!match_positions.empty()) {
        std::cout << "Pattern \"" << pattern << "\" found at positions: ";
        for (int pos : match_positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pattern \"" << pattern << "\" not found in the given text." << std::endl;
    }
}