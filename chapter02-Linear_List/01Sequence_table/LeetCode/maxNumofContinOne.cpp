/**
 * @Description 最大连续1的个数
 * @Version 1.0.0
 * @Date 2024/3/29 14:42
 * @Author Kenton
 */

/**
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。



示例 1：

输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
**/

#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int count = 0,temp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] == 1) {
            temp++;
            if (temp > count) {
                count = temp;
            }
        }else {
            temp = 0;
        }
    }
    return count;
}

int main() {
    std::vector<int> nums = {1,1,0,1,1,1};
    std::cout << findMaxConsecutiveOnes(nums) << std::endl;
}
