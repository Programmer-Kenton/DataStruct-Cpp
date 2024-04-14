/**
 * @Description 王道 KMP算法实现
 * @Version 1.0.0
 * @Date 2024/4/14 13:30
 * @Author Kenton
 */


#include "iostream"
#include "string"


// KMP匹配算法实现
int index_KMP(std::string S,std::string T,int next[]){
    // 这里从1位置开始存储数据
    int i = 1,j = 1;
    while (i <= S.length() && j <= T.length()){
        if (j == 0 || S[i] == T[i]){
            // 继续比较后继字符
            ++i;
            ++j;
        } else{
            // 模式串向右移动
            j = next[j];
        }
        if (j > T.length())
            // 匹配成功
            return i - T.length();
        else return 0;
    }
}

