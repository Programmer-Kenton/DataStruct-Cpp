/**
 * @Description Goal解析器
 * @Version 1.0.0
 * @Date 2024/4/14 20:05
 * @Author Kenton
 */

#include "iostream"

std::string interpret(std::string& command){
    std::string ret = "";
    for (int i = 0; i < command.size() - 2; ++i) {
        if (command[i] = 'G'){
            ret += 'G';
        }else if (command[i] == '('){
            if (command[i+1] == ')'){
                ret += 'o';
                i++;
            } else{
                ret += "al";
                i += 3;
            }
        } else{
            ret += '/';
        }
    }
    return ret;
}