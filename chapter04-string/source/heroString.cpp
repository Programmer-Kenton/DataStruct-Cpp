/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/14 15:05
 * @Author Kenton
 */
#include "../head/heroString.h"

heroString::heroString() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

heroString::heroString(const char *str) {
    // strlen长度算入\0
    length = strlen(str);
    str = new char[length + 1];
    strcpy(this->str, str);
}

heroString::~heroString() {
    delete[] str;
}

size_t heroString::getLength() const {
    return length;
}

char heroString::operator[](size_t index) const {
    return str[index];
}

heroString &heroString::operator=(const heroString &s) {
    // 不是赋值本身
    if (this != &s) {
        delete[] this->str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }
    // 同一个对象 直接返回解引用
    return *this;
}

bool heroString::operator==(const heroString &s) const {
    return strcmp(str, s.str) == 0;
}

bool heroString::operator!=(const heroString &s) const {
    return strcmp(str, s.str) != 0;
}

heroString heroString::copy() const {
    heroString s = *this;
    return s;
}

heroString heroString::operator+(const heroString& s) const{
    heroString result;
    result.length = length + s.length;
    result.str = new char[result.length + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);
    return result;
}

ostream &operator<<(ostream &out, const heroString &s) {
    out << s.str;
    return out;
}

heroString::heroString(const heroString &s) {
    length = s.length;
    str = new char[length + 1];
    strcpy(str,s.str);
}


