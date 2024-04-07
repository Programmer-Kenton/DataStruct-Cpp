/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 16:34
 * @Author Kenton
 */

#include "string"

int maxDepth(std::string s){
    int ret = 0,top = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '('){
            ++top;
            ret = std::max(ret,top);
        } else if (s[i] == ')'){
            --top;
        }
    }
    return ret;
}