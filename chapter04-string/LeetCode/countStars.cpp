/**
 * @Description TODO 统计星号
 * @Version 1.0.0
 * @Date 2024/4/14 19:46
 * @Author Kenton
 */

#include "iostream"

int countAsterisks(std::string& s){
    int sh = 0;
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '|'){
            sh += 1;
        } else if (s[i] == '*'){
            if (sh % 2 == 0){
                ret++;
            }
        }
    }
    return ret;
}

