/**
 * @Description 英雄算法实现字符串
 * @Version 1.0.0
 * @Date 2024/4/14 15:05
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_HEROSTRING_H
#define INC_08WANGDAO_HEROSTRING_H

#include "iostream"
#include "cstring"

using namespace std;

class heroString {
private:
    char *str;
    size_t length;

public:
    heroString();

    explicit heroString(const char *s);

    heroString(const heroString& s);

    virtual ~heroString();

    size_t getLength() const;

    char operator[](size_t index) const;

    heroString &operator=(const heroString &s);

    bool operator==(const heroString &s) const;

    bool operator!=(const heroString &s) const;

    heroString copy() const;

    heroString operator+(const heroString& s) const;

    friend ostream &operator<<(ostream &out, const heroString &s);
};


#endif //INC_08WANGDAO_HEROSTRING_H
