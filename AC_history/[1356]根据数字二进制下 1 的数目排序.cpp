// 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
//
// 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。 
//
// 请你返回排序后的数组。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [0,1,2,3,4,5,6,7,8]
// 输出：[0,1,2,4,8,3,5,6,7]
// 解释：[0] 是唯一一个有 0 个 1 的数。
// [1,2,4,8] 都有 1 个 1 。
// [3,5,6] 有 2 个 1 。
// [7] 有 3 个 1 。
// 按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
// 
//
// 示例 2： 
//
// 输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
//输出：[1,2,4,8,16,32,64,128,256,512,1024]
//解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
// 
//
// 示例 3： 
//
// 输入：arr = [10000,10000]
//输出：[10000,10000]
// 
//
// 示例 4： 
//
// 输入：arr = [2,3,5,7,11,13,17,19]
//输出：[2,3,5,17,7,11,13,19]
// 
//
// 示例 5： 
//
// 输入：arr = [10,100,1000,10000]
//输出：[10,100,10000,1000]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 500 
// 0 <= arr[i] <= 10^4 
// 
// Related Topics 排序 位运算 
// 👍 77 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // O(1)
    int countOne(int n)
    {
        int count = 0;
        while(n)
        {
            n &= (n - 1); // 不做位移运算，只是每次将最左边的1置为0
            count ++;
        }
        return count;
    }

    // 思路：
    // 1. 对每个数字进行countOne计算 O(N)
    // 2. 利用 unordered_map 进行记录对应二进制1的个数的数字列表 O(N)
    // 3. 然后遍历 1 ~ 32的顺序插入ans中，每个vector排序一下 O(mlogm)
    // Complexity:
    // Time: O(N)
    // Space: O(N)
    vector<int> sortByBits(vector<int>& arr)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); ++i)
        {
            int one = countOne(arr[i]);
            if (mp.count(one))
            {
                mp[one].push_back(arr[i]);
            } else {
                mp[one] = {arr[i]};
            }
        }
        arr.clear();
        for (int i = 0; i <= 32; ++i)
        {
            if (mp.count(i))
            {
                sort(mp[i].begin(), mp[i].end());
                arr.insert(arr.end(), mp[i].begin(), mp[i].end());
            }
        }
        return arr;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
