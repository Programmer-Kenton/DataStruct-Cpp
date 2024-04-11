/**
 * @Description TODO 对称矩阵
 * @Version 1.0.0
 * @Date 2024/4/11 17:17
 * @Author Kenton
 */

#include "vector"

class SymmetricMatrix {
public:

    SymmetricMatrix(int size) : data(size * (size + 1) / 2) {}

    int &operator()(int i, int j) {
        if (i > j) {
            std::swap(i, j);  // 保证 i <= j
        }
        return data[i * (i + 1) / 2 + j];
    }

    const int &operator()(int i, int j) const {
        if (i > j) {
            std::swap(i, j);  // 保证 i <= j
        }
        return data[i * (i + 1) / 2 + j];
    }


private:
    std::vector<int> data;
};