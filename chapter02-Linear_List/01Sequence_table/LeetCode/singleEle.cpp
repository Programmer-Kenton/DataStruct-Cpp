/**
 * @Description 单一元素
 * @Version 1.0.0
 * @Date 2024/3/29 18:04
 * @Author Kenton
 */

/**
*给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。



示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10
**/

#include <iostream>
#include <vector>

int singleNonDuplicate(std::vector<int>& nums) {
    for (int i = 1; i < nums.size() - 1; ++i) {
        if (nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
            return nums[i];
        }
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums[0] != nums[1]) {
        return nums[0];
    }
    return nums.back();
}
