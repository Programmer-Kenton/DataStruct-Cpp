/**
 * @Description 算数三元组的个数
 * @Version 1.0.0
 * @Date 2024/3/29 15:50
 * @Author Kenton
 */

/**
给你一个下标从 0 开始、严格递增 的整数数组 nums 和一个正整数 diff 。如果满足下述全部条件，则三元组 (i, j, k) 就是一个 算术三元组 ：

i < j < k ，
nums[j] - nums[i] == diff 且
nums[k] - nums[j] == diff
返回不同 算术三元组 的数目。



示例 1：

输入：nums = [0,1,4,6,7,10], diff = 3
输出：2
解释：
(1, 2, 4) 是算术三元组：7 - 4 == 3 且 4 - 1 == 3 。
(2, 4, 5) 是算术三元组：10 - 7 == 3 且 7 - 4 == 3 。
**/

#include <vector>
#include <iostream>

int arithmeticTriplets(std::vector<int>& nums, int diff) {
    int count = 0;
    for (int j = 0; j < nums.size(); ++j) {
        for (int i = 0; i < j; ++i) {
            if (nums[j] - nums[i] == diff) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[k] - nums[j] == diff) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> nums = {4,5,6,7,8,9};
    std::cout << arithmeticTriplets(nums,2);
}