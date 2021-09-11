// 数组 nums 包含从  0到 n 的所有整数，但其中缺了一个。
// 请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//
// 注意：本题相对书上原题稍作改动 
//
// 示例 1： 
//
// 输入：[3,0,1]
//输出：2 
//
// 
//
// 示例 2： 
//
// 输入：[9,6,4,2,3,5,7,0,1]
//输出：8
// 
// Related Topics 位运算 数组 数学 
// 👍 33 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 方法一： 土办法，hash map，把 nums 加入 hash map, 然后在从0到n判断 O(N) O(N) 方法太土
    // 方法二： 前 n 项和公式，对 nums 求和O(N)， 前 n 项求和 O(1)， 相减， 容易数值溢出
    int missingNumber(vector<int>& nums)
    {
        int curSum = 0;
        for (int n : nums) curSum += n;
        int nSum = (nums.size()) * (1 + nums.size()) / 2;
        return nSum - curSum;
    }
    // 方法三： 位运算，^ 异或运算，从0到n异或一遍，在对nums异或一遍，结果就是缺失的数字，洋气
    // 而且位运算快呀
    int missingNumber3(vector<int>& nums)
    {
        int ans = 0;
        for (int n:nums) ans ^= n;
        for (int i = 0; i <= nums.size(); ++i) ans ^= i;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
