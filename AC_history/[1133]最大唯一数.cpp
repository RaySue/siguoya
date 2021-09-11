//给你一个整数数组 A，请找出并返回在该数组中仅出现一次的最大整数。 
//
// 如果不存在这个只出现一次的整数，则返回 -1。 
//
// 
//
// 示例 1： 
//
// 输入：[5,7,3,9,4,9,8,3,1]
//输出：8
//解释： 
//数组中最大的整数是 9，但它在数组中重复出现了。而第二大的整数是 8，它只出现了一次，所以答案是 8。
// 
//
// 示例 2： 
//
// 输入：[9,9,8,8]
//输出：-1
//解释： 
//数组中不存在仅出现一次的整数。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 2000 
// 0 <= A[i] <= 1000 
// 
// Related Topics 数组 哈希表 
// 👍 12 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 计数桶的长度 必须最大值 + 1
    // 使用计数桶的时候一定要注意，必须得考虑数值范围，数值过大不可用。
    int largestUniqueNumber(vector<int>& A)
    {
        if (A.empty()) return -1;
        int maxVal = *max_element(A.begin(), A.end());
        vector<int> bucket(maxVal + 1, 0);
        for (int a:A) bucket[a]++;
        for (int i = maxVal; i >= 0; --i)
        {
            if (bucket[i] == 0) continue;
            else if (bucket[i] == 1) return i;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
