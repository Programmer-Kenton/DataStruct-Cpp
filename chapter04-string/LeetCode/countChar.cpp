/**
 * @Description 统计文本中汉字的个数
 * @Version 1.0.0
 * @Date 2024/4/14 17:03
 * @Author Kenton
 */

#include "iostream"
#include "cstring"

// 判断一个UTF-8编码的字节是否为有效汉字的第一个字节
bool isUtf8LeadByte(unsigned char byte){
    // 汉字的首字节范围
    return (byte >= 0xE0 && byte <= 0xF7);
}

// 统计UTF-8编码字符串中的汉字个数
int countChineseCharacter(const std::string& input){
    int count = 0;
    // 标记是否处于一个汉字的内部
    bool isInsideChar = false;

    for (unsigned char byte:input) {
        if (isUtf8LeadByte(byte)){
            // 遇到汉字首字节 计数器+1 并标记处于汉字内部
            count++;
            isInsideChar = true;
        } else if (isInsideChar){
            // 检查是否是有效的汉字后续字节
            if ((byte >= 0x80 && byte <= 0xBF)){
                // 继续处理当前汉字的后续字节
            } else{
                // 非法的后续字节，结束当前汉字
                isInsideChar = false;
            }
        }
    }
    return count;
}

int main(){
   char s[100];
   int n;
   std::cin >> n;
   getchar();

    while (n--){
        gets(s);
        int cnt = 0;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if (s[i] < 0) cnt++;
        }
        std::cout << cnt / 2 << std::endl;
    }
}



