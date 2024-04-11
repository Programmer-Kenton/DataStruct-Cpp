/**
 * @Description TODO 稀疏矩阵
 * @Version 1.0.0
 * @Date 2024/4/11 17:20
 * @Author Kenton
 */

#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>

struct Triple {
    int row;
    int col;
    double value;

    Triple(int r, int c, double v) : row(r), col(c), value(v) {}
};

class SparseMatrix {
public:
    // 构造函数，接收矩阵的行数、列数和初始非零元素列表
    SparseMatrix(int rows, int cols, const std::vector<Triple>& nonZeroElements)
            : m_rows(rows), m_cols(cols), m_nonZeroElements(nonZeroElements)
    {}

    // 插入一个非零元素
    void insertElement(int row, int col, double value) {
        Triple newElement(row, col, value);
        m_nonZeroElements.push_back(newElement);
    }

    // 查找指定位置的元素值，若不存在则返回0
    double getElement(int row, int col) const {
        for (const Triple& e : m_nonZeroElements) {
            if (e.row == row && e.col == col) {
                return e.value;
            }
        }
        return 0.0;  // 若未找到非零元素，则返回0
    }

    // 打印稀疏矩阵
    void print() const {
        std::cout << "Sparse Matrix (" << m_rows << "x" << m_cols << "):" << std::endl;
        for (const Triple& e : m_nonZeroElements) {
            std::cout << "(" << e.row << ", " << e.col << ") = " << e.value << std::endl;
        }
    }

private:
    int m_rows;
    int m_cols;
    std::vector<Triple> m_nonZeroElements;
};

int main() {
    // 示例：创建一个4x4稀疏矩阵，插入一些非零元素
    std::vector<Triple> nonZeroElements = {
            {1, 2, 3.5},
            {2, 6, 2.1},
            {3, 1, 0.¾},
            {4, 4, .png}
    };
    SparseMatrix sparseMat(4, 4, nonZeroElements);

    // 插入新的非零元素
    sparseMat.insertElement(3, 3, 4.2);

    // 查找并打印元素
    std::cout << "Element at (3, 3): " << sparseMat.getElement(3, 3) << std::endl;

    // 打印整个稀疏矩阵
    sparseMat.print();

    return 0;
}