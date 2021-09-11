//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。 
//
// 
//
// 示例 1： 
//
// 输入：[-4,-1,0,3,10]
//输出：[0,1,9,16,100]
// 
//
// 示例 2： 
//
// 输入：[-7,-3,2,3,11]
//输出：[4,9,9,49,121]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 10000 
// -10000 <= A[i] <= 10000 
// A 已按非递减顺序排序。 
// 
// Related Topics 数组 双指针 
// 👍 186 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 一刷 2020.12.22
    // 从头到尾，从大到小存储，再逆序即可
    // 从小到达存储是不变的，因为两端偏大
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> ans;
        ans.reserve(nums.size());
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int lv = nums[l] * nums[l];
            int rv = nums[r] * nums[r];
            if (lv < rv){
                ans.push_back(rv);
                r--;
            }
            else {
                ans.push_back(lv);
                l++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
