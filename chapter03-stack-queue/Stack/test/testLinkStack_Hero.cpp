/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 14:53
 * @Author Kenton
 */

#include "../head/LinkStack_Hero.h"

int main(){
    LinkStack_Hero<int> S;
    S.push(4);
    S.push(7);
    S.push(13);
    std::cout << S.top() << std::endl;
    S.push(17);
    std::cout << S.top() << std::endl;
    S.pop();
    S.pop();
    std::cout << S.top() << std::endl;
    std::cout << S.getSize() << std::endl;
}