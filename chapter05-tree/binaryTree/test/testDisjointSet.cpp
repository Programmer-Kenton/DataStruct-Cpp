/**
 * @Description 测试并查集
 * @Version 1.0.0
 * @Date 2024/4/15 22:08
 * @Author Kenton
 */

#include "../head/DisjointSet.h"

int main() {
    DisjointSet ds(5); // 创建一个包含5个元素的并查集

    // 进行一系列操作
    ds.unionSets(0, 1);
    ds.unionSets(2, 3);
    ds.unionSets(0, 4);

    // 合并两个集合的树
    ds.mergeTrees(1, 3);

    // 检查某些元素是否属于同一集合
    std::cout << "Is 0 connected to 2? " << (ds.isConnected(0, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Is 1 connected to 4? " << (ds.isConnected(1, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Is 2 connected to 3? " << (ds.isConnected(2, 3) ? "Yes" : "No") << std::endl;
    std::cout << "Is 1 connected to 3? " << (ds.isConnected(1, 3) ? "Yes" : "No") << std::endl;

}