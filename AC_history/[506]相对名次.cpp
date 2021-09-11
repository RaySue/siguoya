// 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。
// 前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal",
// "Silver Medal", "Bronze Medal"）。 
//
// (注：分数越高的选手，排名越靠前。) 
//
// 示例 1: 
//
// 
//输入: [5, 4, 3, 2, 1]
//输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and 
//"Bronze Medal").
//余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。 
//
// 提示: 
//
// 
// N 是一个正整数并且不会超过 10000。 
// 所有运动员的成绩都不相同。 
// 
// 👍 62 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 1. 先用hash map 记录每个数据的位置
    // 2. 对数组排序
    // 3. 根据 hash map 得到排序后数字的原始 index
    // 4. 对 index 的 ans 进行赋值
    // Complexity
    // Time: O(N * logN)
    // Space: O(N)
    vector <string> findRelativeRanks1(vector<int> &nums)
    {
        vector <string> ans(nums.size(), "");
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) mp[nums[i]] = i;
        sort(nums.begin(), nums.end());  // 升序排序
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums.size() - i == 1)
            {
                ans[mp[nums[i]]] = "Gold Medal";
            } else if (nums.size() - i == 2)
            {
                ans[mp[nums[i]]] = "Silver Medal";
            } else if (nums.size() - i == 3)
            {
                ans[mp[nums[i]]] = "Bronze Medal";
            } else
            {
                ans[mp[nums[i]]] = to_string(nums.size() - i);
            }
        }
        return ans;
    }


    // 复习 C++ lambda 表达式的使用
    // argsort
    // 然后遍历排序后的index，进行赋值
    // Complexity
    // Time: O(N * logN)
    // Space: O(1)
    vector <string> findRelativeRanks(vector<int> &nums)
    {
        vector <string> ans(nums.size(), "");
        vector<int> idx(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            idx[i] = i;
        }

        auto lambda = [&nums](int a, int b)->bool {return nums[a] > nums[b];};
        sort(idx.begin(), idx.end(), lambda);

        for (int i = 0; i < idx.size(); ++i)
        {
            if (i == 0)
            {
                ans[idx[i]] = "Gold Medal";
            } else if (i == 1)
            {
                ans[idx[i]] = "Silver Medal";
            } else if (i == 2)
            {
                ans[idx[i]] = "Bronze Medal";
            } else
            {
                ans[idx[i]] = to_string(i + 1);
            }
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
