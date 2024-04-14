/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/11 21:50
 * @Author Kenton
 */
#include "../head/staticString.h"

void staticString::InitStr() {
    for (int i = 0; i < MAXLEN; ++i) {
        S.ch[i] = '\0';
    }
    S.length = 0;
}

staticString::staticString() {
    InitStr();
}

void staticString::StrAssign(char *chars) const {
    if (chars != nullptr && S.length <= MAXLEN){
        memcpy(chars,S.ch,S.length);
        // 结尾添加'\0'
        chars[S.length] = '\0';
    } else{
        std::cerr << "Error: Invalid target buffer or current string exceeds maximum length." << std::endl;
    }
}

void staticString::StrCopy(SString &T) {
    if (T.length <= MAXLEN){
        memcpy(S.ch,T.ch,T.length);
        S.ch[T.length] = '\0';
        S.length = T.length;
    } else{
        std::cerr << "Error: Source string exceeds maximum length." << std::endl;
    }
}

bool staticString::StrEmpty() {
    return S.length == 0;
}

size_t staticString::StrLength() {
    return S.length;
}

void staticString::ClearString() {
    InitStr();
}

staticString::~staticString() {

}

void staticString::Concat(SString &T, SString S2) {
    if (S.length + S2.length <= MAXLEN){
        memcpy(T.ch,S.ch,S.length);
        memcpy(T.ch + S.length,S2.ch,S2.length);
        T.ch[S.length + S2.length] = '\0';
    } else{
        std::cerr << "Error: Concatenation result exceeds maximum length." << std::endl;
    }
}

/**
 *
 * @param Sub 目标串 用于存储提取的字串
 * @param pos 开始位置从0开始计数
 * @param len 子串长度
 * @return 字串提取成功返回true 否则为false
 */
bool staticString::SubString(SString &Sub, int pos, int len) {
    if (pos >= 0 && pos < S.length && len >= 0 && pos + len <= S.length && len <= MAXLEN){
        memcpy(Sub.ch,S.ch + pos,len);
        Sub.ch[len] = '\0';
        Sub.length = len;
        return true;
    } else{
        std::cerr << "Error: Invalid substring parameters or resulting substring exceeds maximum length." << std::endl;
        return false;
    }
}

int staticString::StrCompare(SString T) const {
    int min_len = std::min(S.length,T.length);
    int cmp_result = memcmp(S.ch,T.ch,min_len);
    if (cmp_result != 0){
        return cmp_result;
    } else{
        // 扫描过的所有字符都相等 长度长的串更大
        return S.length - T.length;
    }
}

int staticString::Index(SString T) {
    if (T.length > S.length){
        // 字串长度大于原串 不可能找到匹配的
        return -1;
    }
    for (int i = 0; i <= S.length - T.length; ++i) {
        bool match = true;
        for (int j = 0; j < T.length; ++j) {
            if (S.ch[i+j] != T.ch[j]){
                match = false;
                break;
            }
        }
        if (match){
            // 找到匹配 返回起始位置
            return i;
        }
    }
    // 没有找到匹配
    return -1;
}

int staticString::Index_Simplicity(SString T) {
    int S_len = S.length;
    int T_len = T.length;
    for (int i = 0; i <- S_len - T_len; ++i) {
        int j;
        for (int j = 0; j < T_len; ++j) {
            if (S.ch[i+j] != T.ch[j]){
                break;
            }
        }
        if (j == T_len){
            // 返回子串在主串中的位置（从0开始计数）
            return i;
        }
    }
    // 没有找到子串
    return -1;
}

std::vector<int> staticString::buildPartialMatchTable(const SString &pattern) {
    int patternLength = pattern.length;
    std::vector<int> next(patternLength,0);

    for (int i = 1,j = 0; i < patternLength; ++i) {
        while (j > 0 && pattern.ch[j] != pattern.ch[i]){
            j = next[j - 1];
        }
        if (pattern.ch[i] == pattern.ch[j]){
            ++j;
        }
        next[i] = j;
    }
    return next;
}

int staticString::Index_KMP(SString &pattern, std::vector<int> &next) {
    int textLength = S.length;
    int patternLength = pattern.length;

    int i = 0, j = 0;
    while (i < textLength && j < patternLength) {
        if (S.ch[i] == pattern.ch[j]) {
            ++i;
            ++j;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            ++i;
        }
    }
    return j == patternLength ? i - j : -1;
}



