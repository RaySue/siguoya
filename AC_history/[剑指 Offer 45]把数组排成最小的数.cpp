//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。 
//
// 
//
// 示例 1: 
//
// 输入: [10,2]
//输出: "102" 
//
// 示例 2: 
//
// 输入: [3,30,34,5,9]
//输出: "3033459" 
//
// 
//
// 提示: 
//
// 
// 0 < nums.length <= 100 
// 
//
// 说明: 
//
// 
// 输出结果可能非常大，所以你需要返回一个字符串而不是整数 
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0 
// 
// Related Topics 排序 
// 👍 129 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 我们只需要对字符串之间的组合的字典序最小即可凑成最小的数
    // 在排序的时候，元素是需要两两比较的，这里我们只需要比较 s1 + s2 与 s2 + s1 哪个字典序更靠前即可
    // 大的字典序 + 小的字典序 一定没有 小的字典序 + 小的字典序 靠前
    // 而两个小字典序 根据先后顺序不同 再选出最小字典序的组合即是答案
    string minNumber(vector<int>& nums)
    {
        string ans = "";
        vector<string> transferNums(nums.size(), "");
        auto lambda = [](string s1, string s2)->bool {return s1 + s2 < s2 + s1;};

        for(int i = 0; i < nums.size(); ++i) transferNums[i] = to_string(nums[i]);

        sort(transferNums.begin(), transferNums.end(), lambda);
        for (string s:transferNums)
        {
            ans += s;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
