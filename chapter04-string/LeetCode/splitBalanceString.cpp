/**
 * @Description TODO 分割平衡字符串 贪心算法解决
 * @Version 1.0.0
 * @Date 2024/4/14 19:53
 * @Author Kenton
 */

#include "iostream"

int balanceStringSplit(std::string& s){
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'L'){
            ++cnt;
        } else{
            --cnt;
        }
        if (cnt == 0){
            ret++;
        }
    }
    return ret;
}
