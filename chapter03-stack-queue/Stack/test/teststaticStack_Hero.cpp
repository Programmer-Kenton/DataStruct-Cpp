/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 14:26
 * @Author Kenton
 */

#include "../head/staticStack_Hero.h"

int main(){
    staticStack_Hero<int> S;
    S.push(4);
    S.push(7);
    S.push(13);
    std::cout << S.top() << std::endl;

    S.pop();
    S.pop();
    std::cout << S.pop() << std::endl;
}