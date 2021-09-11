// 给你一个由一些多米诺骨牌组成的列表 dominoes。
//
// 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。 
//
// 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。
//
// 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。
//
// 示例： 
//
// 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
// 输出：1
// 
//
//      dominoes = [[1,2],[2,1],[1,2]]
//                 [[1,2],[2,1],[1,2],[2,1]]
// 提示： 
//
// 
// 1 <= dominoes.length <= 40000 
// 1 <= dominoes[i][j] <= 9 
// 
// Related Topics 数组 
// 👍 71 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 2021.01.26 每日一题
    // 暴力 两次遍历 dominoes TLE
    // 思路：每个和后面所有的配对，如果满足配对规则，那么就 ret ++
    // Complexity：
    // Time: O(N^2)
    // Space: O(1)
    int numEquivDominoPairs1(vector <vector<int>> &dominoes)
    {
        if (dominoes.empty()) return 0;
        int ret = 0;
        for (int i = 0; i < dominoes.size(); ++i)
        {
            for (int j = i + 1; j < dominoes.size(); ++j)
            {
                bool flag1 = dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1];
                bool flag2 = dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0];
                if (flag1 || flag2) ret++;
            }
        }
        return ret;
    }

    // 如果能配对成功，那么一定是相加肯定相等的，所以可以进行分组
    // 利用 hash map 对 dominoes 进行分组, 结果也不是很好
    // Runtime:1688 ms, faster than 5.70% of C++ online submissions.
    // Memory Usage:22.8 MB, less than 5.46% of C++ online submissions.
    // Complexity:
    // Time: O(17 * M^2)
    // Space: O(N)
    int numEquivDominoPairs2(vector <vector<int>> &dominoes)
    {
        unordered_map < int, vector < vector < int >> > mem;
        for (int i = 0; i < dominoes.size(); ++i)
        {
            mem[dominoes[i][0] + dominoes[i][1]].push_back(dominoes[i]);
        }
        int ret = 0;
        for (auto &[k, v] : mem)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = i + 1; j < v.size(); ++j)
                {
                    bool flag1 = v[i][0] == v[j][0] && v[i][1] == v[j][1];
                    bool flag2 = v[i][0] == v[j][1] && v[i][1] == v[j][0];
                    if (flag1 || flag2) ret++;
                }
            }
        }
        return ret;
    }

    // 利用组合数，利用 map 做聚合，然后计算每个pair的组合数
    // 如果找到了两个那么就是 1
    // 如果找到了三个都相等那么就是 C32
    // 如果找到了4个就是 C42
    int numEquivDominoPairs(vector <vector<int>> &dominoes)
    {
        map<pair<int, int>, int> bucket;
        for (int i = 0; i < dominoes.size(); ++i)
        {
            if (dominoes[i][0] == 0) continue;
            for (int j = i + 1; j < dominoes.size(); ++j)
            {
                if (dominoes[j][0] + dominoes[j][1] != dominoes[i][0] + dominoes[i][1]) continue;
                bool flag1 = dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1];
                bool flag2 = dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0];
                if (flag1 || flag2)
                {
                    dominoes[j][0] = 0;
                    bucket[{dominoes[i][0], dominoes[i][1]}]++;
                }
            }
        }
        int ret = 0;
        for (auto &[k, v] :bucket)
        {
            v++;
            if (v < 2) continue;
            else if (v == 2) ret++;
            else if (v > 2) ret += (v * (v - 1)) / 2;
        }
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
