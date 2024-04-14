/**
 * @Description 静态串
 * @Version 1.0.0
 * @Date 2024/4/11 21:50
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICSTRING_H
#define INC_08WANGDAO_STATICSTRING_H

#define MAXLEN 255

#include "iostream"
#include "cstring"
#include "vector"

typedef struct {
    // 每个分量存储一个字符
    char ch[MAXLEN];
    // 串的实际长度
    int length;
} SString;

class staticString {
public:

    SString S;

    // 初始化串
    void InitStr();

    // 构造函数
    staticString();

    // 赋值操作 将当前串的内容复制给chars
    void StrAssign(char *chars) const;

    // 复制操作
    void StrCopy(SString &T);

    // 判空操作
    bool StrEmpty();

    // 求串长
    size_t StrLength();

    // 清空操作
    void ClearString();

    // 析构函数 销毁串
    ~staticString();

    // 串连接 将原串和S2连接成新串复制给T
    void Concat(SString &T, SString S2);

    // 求字串
    bool SubString(SString &Sub, int pos, int len);

    /**
     * 比较字符串大小
     * @param T T和原串比较
     * @return 原串>T 返回大于0 原串=T 返回0 原串<T 返回小于0
     */
    int StrCompare(SString T) const;

    /**
     * 求串T在原串中第一次出现的位置 没有找到返回-1
     * @param T
     * @return
     */
    int Index(SString T);

    // 朴素模式匹配
    int Index_Simplicity(SString T);

    /**
     * 构建KMP算法的部分匹配表 next数组
     * @param pattern 待匹配的m模式串
     * @return next数组 表示每个位置的最长相同前后缀长度
     */
    static std::vector<int> buildPartialMatchTable(const SString &pattern);


    /**
    * 使用KMP算法在文本串中查找模式串的起始索引，文本串即本串
    * @param pattern 待匹配的模式串
    * @param next 预先计算好的模式串的部分匹配表
    * @return 若找到模式串，则返回其在文本串中的起始索引；否则返回-1
    */
    int Index_KMP(SString &pattern, std::vector<int> &next);
};


#endif //INC_08WANGDAO_STATICSTRING_H
