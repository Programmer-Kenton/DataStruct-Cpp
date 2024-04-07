/**
 * @Description 数组中两元素的最大乘积
 * @Version 1.0.0
 * @Date 2024/3/29 14:55
 * @Author Kenton
*/


/**
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。



示例 1：

输入：nums = [3,4,5,2]
输出：12
解释：如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。
**/

#include <vector>
#include <iostream>

int maxProduct(std::vector<int>& nums) {
    int maxInx = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > nums[maxInx]) {
            maxInx = i;
        }
    }

    int subInx = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (i != maxInx) {
            if (subInx == -1 || nums[i] > nums[subInx]) {
                subInx = i;
            }
        }
    }
    return (nums[maxInx] - 1) * (nums[subInx] - 1);
}

int main() {
    std::vector<int> nums = {3,4,5,2};
    std::cout << maxProduct(nums) << std::endl;
}