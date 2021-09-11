//给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。 
//
// 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。 
//
// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
// 格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。
// 计算这个岛屿的周长。
//
// 
//
// 示例 : 
//
// 输入:
//[[0,1,0,0],
// [1,1,1,0],
// [0,1,0,0],
// [1,1,0,0]]
//
//输出: 16
//
//解释: 它的周长是下面图片中的 16 个黄色的边：
//
//
//
// 👍 263 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // vector <vector<int>> grid Time out
    // vector <vector<int>> &grid Passed
    // 这就充分说明了传引用的重要性
    int check(vector <vector<int>> &grid, int i, int j)
    {
        int count = 0;
        if (i - 1 < 0 || grid[i - 1][j] == 0) count++;
        if (i + 1 == grid.size() || grid[i + 1][j] == 0) count++;
        if (j - 1 < 0 || grid[i][j - 1] == 0) count++;
        if (j + 1 == grid[0].size() || grid[i][j + 1] == 0) count++;
        return count;
    }

    // 循环中能不用调函数，尽量不要使用，否则效率很慢
    int islandPerimeter(vector <vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    count += check(grid, i, j);
                }
            }
        }
        return count;
    }

    // passed
    int islandPerimeter2(vector <vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    if (i - 1 < 0 || grid[i - 1][j] == 0) count++;
                    if (i + 1 == grid.size() || grid[i + 1][j] == 0) count++;
                    if (j - 1 < 0 || grid[i][j - 1] == 0) count++;
                    if (j + 1 == grid[0].size() || grid[i][j + 1] == 0) count++;
                }
            }
        }
        return count;
    }


    // ------------------ dfs ------------------------

    int ans = 0;

    void dfs(vector<vector<int> > &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] != 1) return;

        if (i - 1 < 0 || grid[i - 1][j] == 0) ans++;
        if (i + 1 == grid.size() || grid[i + 1][j] == 0) ans++;
        if (j - 1 < 0 || grid[i][j - 1] == 0) ans++;
        if (j + 1 == grid[0].size() || grid[i][j + 1] == 0) ans++;

        grid[i][j] = 2;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int islandPerimeter3(vector <vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
