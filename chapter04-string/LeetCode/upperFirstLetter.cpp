/**
 * @Description 输入一串字符将首字母小写转大写
 * @Version 1.0.0
 * @Date 2024/4/14 17:25
 * @Author Kenton
 */

#include "iostream"
#include "cstring"

int main(){
    char s[100];
    while (gets(s)){
        int len = strlen(s);

        for (int i = 0; i < len; ++i) {
            // 如果是第一个字母或者前面字符为空格
            if (i == 0 || s[i-1] == ' '){
                if (s[i] != ' '){
                    // 转大写
                    if (s[i] >= 'a' && s[i] <= 'z'){
                        s[i] -= 'a';
                        s[i] += 'A';
                    }
                }
            }
        }
        printf("%s\n",s);
    }
}