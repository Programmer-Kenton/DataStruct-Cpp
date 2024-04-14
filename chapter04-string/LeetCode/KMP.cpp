/**
 * @Description KMP算法
 * @Version 1.0.0
 * @Date 2024/4/12 22:13
 * @Author Kenton
 */

#include <iostream>
#include <string>
#include <vector>

// 建立部分匹配表
std::vector<int> buildNext(const std::string &pattern) {
    // 获取字符串长度
    int n = pattern.size();
    // next容器所有元素值设置为0
    std::vector<int> next(n, 0);

    // 跟踪当前已匹配的最长后缀长度
    int j = 0;
    printf("next[%d] = %d\n",j,next[0]);

    // 从第二个字符开始遍历字符串
    for (int i = 1; i < n; ++i) {
        // 当j>0且当前字符pattern[i]与pattern[j]不匹配时
        while (j > 0 && pattern[i] != pattern[j]) {
            // 将j回退到next[j-1]对应的已知相等前后缀长度
            j = next[j - 1];
        }
        // 若当前字符pattern[i]与pattern[j]匹配
        if (pattern[i] == pattern[j]) {
            // 递增j，表示已匹配长度加1
            ++j;
        }
        // 更新next[i]为当前的j值，即当前字符之前的子串中，最长相等前后缀的长度
        next[i] = j;
        printf("next[%d] = %d\n",i,next[i]);
    }

    return next;
}

// KMP查找算法
std::vector<int> kmpSearch(const std::string &text, const std::string &pattern) {
    // 存储匹配位置
    std::vector<int> matches;

    // 计算pattern的next数组
    std::vector<int> next = buildNext(pattern);

    // 定义变量m（文本长度）和n（模式长度）
    int m = text.size(), n = pattern.size();

    // i（文本指针）和j（模式指针），初始值均为0。
    int i = 0, j = 0;

    // 模式串匹配完成/主串匹配结束没有找到都结束循环
    while (i < m && j < n) {
        if (text[i] == pattern[j]) {
            // 当text[i]与pattern[j]相等时，同时递增i和j
            ++i;
            ++j;
        } else if (j > 0) {
            // 若j > 0且字符不匹配，则利用next数组回退j至已知的前缀位置
            j = next[j - 1];
        } else {
            // j为0 即第一个字符不匹配 文本串指针后移 模式串指针不变
            ++i;
        }

        // 第一个if判断结束后j指针后移 若匹配成功则超过模式串范围 j == n
        if (j == n) {
            //记录匹配成功的起始位置
            matches.push_back(i - j);
            //回退到前一个最长相等前后缀的结束位置，继续寻找下一个匹配
            j = next[j - 1];
        }
    }

    return matches;
}

int main() {
    std::string text = "ababcabcaabcac";
    std::string pattern = "ababcaa";

    std::vector<int> match_positions = kmpSearch(text, pattern);

    if (!match_positions.empty()) {
        std::cout << "Pattern \"" << pattern << "\" found at positions: ";
        for (int pos : match_positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pattern \"" << pattern << "\" not found in the given text." << std::endl;
    }

    return 0;
}

