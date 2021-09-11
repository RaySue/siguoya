//给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。 
//
// 请你找到这个数组里第 k 个缺失的正整数。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [2,3,4,7,11], k = 5
//输出：9
//解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
// 
//
// 示例 2： 
//
// 输入：arr = [1,2,3,4], k = 2
//输出：6
//解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 1000 
// 1 <= arr[i] <= 1000 
// 1 <= k <= 1000 
// 对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j] 
// 
// Related Topics 数组 哈希表 
// 👍 19 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.01 利用 hash map，没有用到 严格升序排列 这一特性
    // Complexity:
    // Time: O(N)
    // Space: O(N)
    int findKthPositive(vector<int> &arr, int k)
    {
        unordered_set<int> record;
        for (int a:arr) record.insert(a);
        int count = 0;
        for (int i = 1; i <= arr.back() + k; ++i)
        {
            if (!record.count(i)) count++;
            if (count == k) return i;
        }
        return -1;
    }

    // 思路；
    // 1. 第一种情况： arr 的最小值大于等于 k + 1，说明 k 就是确实的第 k 大的整数
    // 2. 第二种情况： 缺失数字比arr[0]大，但比arr[n-1]小，即在数组之间；
    // 3. 第三种情况： 缺失数字比arr[n-1]大，即在数组之后。
    int findKthPositive(vector<int> &arr, int k)
    {
        if (arr[0] >= k + 1) return k;
        for (int i = 1; i < arr.size(); ++i)
            if (arr[i] - i > arr[0] && (arr[0] = arr[i] - i) >= k + 1)
                return arr[i] - (arr[0] - k);

        return arr.back() + k + 1 - arr[0];
    }

};
//leetcode submit region end(Prohibit modification and deletion)
