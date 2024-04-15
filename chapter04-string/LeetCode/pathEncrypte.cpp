/**
 * @Description 路径加密
 * @Version 1.0.0
 * @Date 2024/4/14 19:24
 * @Author Kenton
 */

#include "iostream"

std::string pathEncrption(std::string& path){
    int len = path.size();
    for (int i = 0; i < len; ++i) {
        if (path[i] == '.'){
            path[i] = ' ';
        }
    }
    return path;
}