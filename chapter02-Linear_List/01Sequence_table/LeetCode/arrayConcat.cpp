/**
 * @Description 数组串联
 * @Version 1.0.0
 * @Date 2024/3/29 16:49
 * @Author Kenton
 */

/**
*给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，数组下标 从 0 开始计数 ，对于所有 0 <= i < n 的 i ，满足下述所有要求：

ans[i] == nums[i]
ans[i + n] == nums[i]
具体而言，ans 由两个 nums 数组 串联 形成。

返回数组 ans 。

示例 1：

输入：nums = [1,2,1]
输出：[1,2,1,1,2,1]
解释：数组 ans 按下述方式形成：
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
**/

#include <vector>
#include <iostream>


std::vector<int> getConcatenation(std::vector<int>& nums) {
    std::vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        ans.push_back(nums[i]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main() {
}
