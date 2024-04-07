/**
 * @Description 杨辉三角
 * @Version 1.0.0
 * @Date 2024/3/29 18:21
 * @Author Kenton
 */

/**
118. 杨辉三角
简单
相关标签
相关企业
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。





示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:

输入: numRows = 1
输出: [[1]]

0 <= rowIndex <= 33
**/

#include <iostream>
#include <vector>


std::vector<std::vector<int>> getGow(int numRows) {
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < numRows; ++i) {
        // 初始化每一行的第一个元素和最后一个元素为0
        std::vector<int> row(i+1,1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

int main() {
    int numRows = -1;
    std::cin >> numRows;

    std::vector<std::vector<int>> ret = getGow(numRows);

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            std::cout << ret[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
