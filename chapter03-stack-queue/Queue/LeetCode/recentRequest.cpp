/**
 * @Description 最近的请求次数
 * @Version 1.0.0
 * @Date 2024/4/11 21:19
 * @Author Kenton
 */

#include "queue"

class RecentCounter{
public:
    std::queue<int> q;

    RecentCounter(){

    }

    int ping(int t){
        q.push(t);
        while (t - q.front() > 3000){
            q.pop();
        }
        return q.size();
    }
};