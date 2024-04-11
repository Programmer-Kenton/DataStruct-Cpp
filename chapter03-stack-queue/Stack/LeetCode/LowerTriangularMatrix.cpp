/**
 * @Description TODO 下三角矩阵
 * @Version 1.0.0
 * @Date 2024/4/11 17:31
 * @Author Kenton
 */


#include <iostream>
#include <vector>

// 定义一个用于存储和操作下三角矩阵的类
class LowerTriangularMatrix {
public:
    // 构造函数，接受矩阵的阶数并初始化为全零
    LowerTriangularMatrix(int size) : data(size, std::vector<double>(size, 0.0)) {}

    // 设置或修改矩阵中的某个元素，仅允许对下三角部分进行操作
    void setElement(int row, int col, double value) {
        if (row >= col) {
            data[row - 1][col - 1] = value;
        } else {
            throw std::invalid_argument("Attempted to set an element outside the lower triangular part of the matrix.");
        }
    }

    // 获取矩阵中的某个元素
    double getElement(int row, int col) const {
        if (row >= col) {
            return data[row - 1][col - 1];
        } else {
            throw std::invalid_argument("Attempted to access an element outside the lower triangular part of the matrix.");
        }
    }

    // 用于存储下三角矩阵元素的二维动态数组
    std::vector<std::vector<double>> data;

};

int main() {
    // 创建一个3x3的下三角矩阵
    LowerTriangularMatrix mtx(3);

    // 设置矩阵元素
    mtx.setElement(1, 1, 1.0);
    mtx.setElement(2, 2, 2.0);
    mtx.setElement(3, 3, 3.0);
    mtx.setElement(2, 1, 4.0);
    mtx.setElement(3, 2, 5.0);

    // 输出矩阵
    for (int i = 1; i <= mtx.data.size(); ++i) {
        for (int j = 1; j <= mtx.data[i - 1].size(); ++j) {
            std::cout << mtx.getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}