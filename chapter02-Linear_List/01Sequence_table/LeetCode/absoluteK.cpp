/**
 * @Description 差的绝对值为K的数对数目
 * @Version 1.0.0
 * @Date 2024/3/29 14:51
 * @Author Kenton
 */

/**
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。


示例 1：

输入：nums = [1,2,2,1], k = 1
输出：4
解释：差的绝对值为 1 的数对为：
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
**/

#include <vector>
#include <iostream>

int countKDifference(std::vector<int>& nums, int k) {
    int ret = 0;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (abs(nums[i] - nums[j]) == k) {
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    std::vector<int> nums = {1,2,2,1};
    std::cout << countKDifference(nums,1) << std::endl;
}
