/**
 * @Description 数组元素和与数字和的绝对差
 * @Version 1.0.0
 * @Date 2024/3/29 15:13
 * @Author Kenton
 */

/**
元素和 是 nums 中的所有元素相加求和。
数字和 是 nums 中每一个元素的每一数位（重复数位需多次求和）相加求和。
返回 元素和 与 数字和 的绝对差。

注意：两个整数 x 和 y 的绝对差定义为 |x - y| 。



示例 1：

输入：nums = [1,15,6,3]
输出：9
解释：
nums 的元素和是 1 + 15 + 6 + 3 = 25 。
nums 的数字和是 1 + 1 + 5 + 6 + 3 = 16 。
元素和与数字和的绝对差是 |25 - 16| = 9 。
**/

#include <vector>
#include <iostream>

int differenceOfSum(std::vector<int>& nums) {
    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); ++i) {
        x += nums[i];
        while (nums[i]) {
            y += nums[i] % 10;
            nums[i] /= 10;
        }
    }
    return abs(x - y);
}

int main() {
    std::vector<int> nums = {1,15,6,3};

    std::cout << differenceOfSum(nums);
}