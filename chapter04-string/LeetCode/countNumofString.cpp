/**
 * @Description 统计一致字符串的数目
 * @Version 1.0.0
 * @Date 2024/4/15 9:38
 * @Author Kenton
 */

#include "iostream"
#include "vector"

int countConsistentStrings(std::string allowed,std::vector<std::string>& words){
    int has[256] = {0};

    for (int i = 0; i < allowed.size(); ++i) {
        has[allowed[i]] = 1;
    }
    int sum = 0;
    for (int i = 0; i < words.size(); ++i) {
        bool bfind = true;
        for (int j = 0; j < words[i].size(); ++j) {
            char c = words[i][j];
            if (has[c] == 0){
                bfind = false;
                break;
            }
        }
        if (bfind) sum++;
    }
    return sum;
}