// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
// 格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
// 它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 2： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
// 👍 180 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    bool check(int i, int j, int k)
    {
        int sum = 0;
        while (i > 0 || j > 0)
        {
            sum += i % 10;
            sum += j % 10;
            i /= 10;
            j /= 10;
        }
        return sum <= k;
    }

    // BFS
    int movingCount(int m, int n, int k)
    {
        int count = 0;
        queue <pair<int, int>> q;
        set <pair<int, int>> isVis;
        q.push({0, 0});
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            if (!check(i, j, k)) continue;
            if (i + 1 < n)
            {
                if (!isVis.count({i + 1, j}))
                {
                    q.push({i + 1, j});
                    isVis.insert({i + 1, j});
                }
            }
            if (j + 1 < m)
            {
                if (!isVis.count({i, j + 1}))
                {
                    q.push({i, j + 1});
                    isVis.insert({i, j + 1});
                }

            }
            count++;
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
