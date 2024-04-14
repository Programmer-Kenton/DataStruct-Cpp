/**
 * @Description 二维队列
 * @Version 1.0.0
 * @Date 2024/4/11 21:05
 * @Author Kenton
 */

#include <queue>
#include "iostream"
#include "string"
#include "cstring"

int team[1000000];

int main(){
    int t;
    while (std::cin >> t && t){
        memset(team,0,sizeof(team));
        for (int i = 1; i <= t; ++i) {
            int n;
            std::cin >> n;
            while (n--){
                int x;
                std::cin >> x;
                team[x] = i;
            }
        }
        std::queue<int> q[1001];
        int s = 0,e = 0;
        std::string str;
        while (std::cin >> str){
            if (str == "STOP") break;
            if (str == "ENQUEUE") {
                int x,i;
                std::cin >> x;
                for (i = s; s < e; ++i) {
                    if (team[q[i].front() == team[x]]){
                        break;
                    }
                }
                q[i].push(x);
                if (i == e){
                    ++e;
                }
            } else{
                int val = q[s].front();
                q[s].pop();
                if (q[s].size() == 0){
                    ++s;
                }
                std::cout << val << std::endl;
            }
        }
    }
}