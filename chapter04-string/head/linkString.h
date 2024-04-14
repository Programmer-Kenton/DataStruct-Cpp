/**
 * @Description 链式串
 * @Version 1.0.0
 * @Date 2024/4/11 21:52
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_LINKSTRING_H
#define INC_08WANGDAO_LINKSTRING_H

#include "iostream"
#include "cstring"
#include <limits>

typedef struct StringNode{
    // 每个结点存4个字符 未满的单元用\0截止
    char ch[4];

    struct StringNode *next;

};

class linkString {
public:
    StringNode *head;

    // 初始化串
    void InitStr();

    // 构造函数
    linkString();

    // 赋值操作 将当前串的内容复制给chars字符数组
    void StrAssign(char *chars) const;

    // 复制操作 将串T的内容复制给当前串
    void StrCopy(linkString& T);

    // 判空操作
    bool StrEmpty();

    // 求串长
    size_t StrLength();

    // 清空操作
    void ClearString();

    // 析构函数 销毁串
    ~linkString();

    // 串连接 将原串和S2连接成新串复制给T
    void Concat(linkString& T,linkString S2);

    // 求字串
    bool SubString(linkString& Sub,int pos,int len);

    /**
     * 比较字符串大小
     * @param T T和原串比较
     * @return 原串>T 返回大于0 原串=T 返回0 原串<T 返回小于0
     */
    int StrCompare(linkString T) const;

    /**
     * 求串T在原串中第一次出现的位置 没有找到返回-1
     * @param T
     * @return
     */
    int Index(linkString T);

    // 辅助函数：从head到p的字符串长度
    size_t StrLengthFrom(StringNode *head,StringNode *p);

};


#endif //INC_08WANGDAO_LINKSTRING_H
