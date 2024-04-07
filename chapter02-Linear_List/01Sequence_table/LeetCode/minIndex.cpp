/**
 * @Description 值相等的最小索引
 * @Version 1.0.0
 * @Date 2024/3/29 14:36
 * @Author Kenton
 */

/**
给你一个下标从 0 开始的整数数组 nums ，返回 nums 中满足 i mod 10 == nums[i] 的最小下标 i ；如果不存在这样的下标，返回 -1 。

x mod y 表示 x 除以 y 的 余数 。



示例 1：

输入：nums = [0,1,2]
输出：0
解释：
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
所有下标都满足 i mod 10 == nums[i] ，所以返回最小下标 0
**/

#include <iostream>
#include <vector>

int smalllestEqual(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 10 == nums[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums = {0,1,2};
    std::cout << smalllestEqual(nums) << std::endl;
}
