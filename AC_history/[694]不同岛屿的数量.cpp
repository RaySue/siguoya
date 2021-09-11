//给定一个非空 01 二维数组表示的网格，一个岛屿由四连通（上、下、左、右四个方向）的 1 组成，你可以认为网格的四周被海水包围。 
//
// 请你计算这个网格中共有多少个形状不同的岛屿。两个岛屿被认为是相同的，当且仅当一个岛屿可以通过平移变换（不可以旋转、翻转）和另一个岛屿重合。 
//
// 
//
// 示例 1： 
//
// 11000
// 11000
// 00011
// 00011
// 
//
// 给定上图，返回结果 1 。 
//
// 示例 2： 
//
// 11011
// 10000
// 00001
// 11011
//
// 给定上图，返回结果 3 。 
// 
//注意： 
//
// 11
//1
// 
//
// 和 
//
//  1
//11
// 
//
// 是不同的岛屿，因为我们不考虑旋转、翻转操作。 
//
// 
//
// 提示：二维数组每维的大小都不会超过 50 。 
// Related Topics 深度优先搜索 哈希表 
// 👍 54 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：深度优先搜索
    // 要点1：对比两个岛屿是个看似复杂的任务，但是我们只需要在搜索的时候减去当前的base位置，那么所有平移的位置就都一样了
    // 要点2：需要使用 map 和 set 来存储相同岛屿面积的所有岛屿，用set对排序之后的岛屿去重
    // 时间复杂度：O(RC)*。其中 R 是给定网格中的行数，C 是列数。我们遍历每个网格一次。
    // 空间复杂度：O(RC)* 用来保存跟踪访问过的网格和形状。
    int action[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};

    void dfs(vector <vector<int>> &grid, int baseI, int baseJ, int i, int j, vector <vector<int>> &record)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 2;
        record.push_back({i - baseI, j - baseJ});
        for (int idx = 0; idx < 4; ++idx)
        {
            dfs(grid, baseI, baseJ, i + action[idx][0], j + action[idx][1], record);
        }
    }

    int numDistinctIslands(vector <vector<int>> &grid)
    {
        int ans = 0;
        map < int, set < vector < vector < int > > > > records;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    vector <vector<int>> record;
                    dfs(grid, i, j, i, j, record);
                    sort(record.begin(), record.end());
                    records[record.size()].insert(record);
                    record.clear();
                }
            }
        }
        map < int, set < vector < vector < int > > > > ::iterator iter;
        for (iter = records.begin(); iter != records.end(); iter++)
        {
            ans += iter->second.size();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
