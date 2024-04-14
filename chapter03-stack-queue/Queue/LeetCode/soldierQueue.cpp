/**
 * @Description 士兵队列
 * @Version 1.0.0
 * @Date 2024/4/11 20:36
 * @Author Kenton
 */

#include "queue"
#include "iostream"

int main(){
    int t;

    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::queue<int> q1,q2;
        for (int i = 1; i <= n; ++i) {
            q1.push(i);
        }
        while (q1.size() > 3){
            int cnt = 0;
            while (q1.size()){
                int value = q1.front();
                q1.pop();
                ++cnt;
                if (cnt % 2 == 1){
                    q2.push(value);
                }
            }
            if (q2.size() <= 3){
                while (q2.size()){
                    q1.push(q2.front());
                    q2.pop();
                    break;
                }
            }
            cnt = 0;
            while (q2.size()){
                int value = q2.front();
                q2.pop();
                ++cnt;
                if (cnt % 3 == 1 || cnt % 3 == 2){
                    q1.push(value);
                }
            }
        }
        int flag = 0;
        while (q1.size()){
            if (flag){
                std::cout << ' ';
            }
            std::cout << q1.front();
            q1.pop();
            flag++;
        }
        std::cout << std::endl;
    }
}