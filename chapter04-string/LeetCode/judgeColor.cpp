/**
 * @Description 判断国际象棋棋盘中一个格子的颜色
 * @Version 1.0.0
 * @Date 2024/4/14 19:18
 * @Author Kenton
 */

#include "iostream"

bool squareIsWhite(std::string coordinates){
    int x = coordinates[0] - 'a';
    int y = coordinates[1] - '1';
    return (x + y) % 2 == 1;
}