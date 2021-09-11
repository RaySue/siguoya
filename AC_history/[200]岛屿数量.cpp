//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 835 👎 0


/**
[["1","1","1","1","0"],
 ["1","1","0","1","0"],
 ["1","1","0","0","0"],
 ["0","0","0","0","0"]]

 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    void bfs(vector <vector<char>> &grid, int ii, int jj)
    {
        queue <pair<int, int>> q;
        q.push({ii, jj});
        while (!q.empty())
        {
            auto loc = q.front();q.pop();
            int x = loc.first, y = loc.second;
            grid[x][y] = '#';
            if (x - 1 >= 0 && grid[x - 1][y] == '1')
            {
                grid[x - 1][y] = '#';
                q.push({x - 1, y});
            }
            if (y - 1 >= 0 && grid[x][y - 1] == '1')
            {
                grid[x][y - 1] = '#';
                q.push({x, y - 1});
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == '1')
            {
                grid[x+1][y] = '#';
                q.push({x + 1, y});
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == '1'){
                grid[x][y + 1] = '#';
                q.push({x, y + 1});
            }
        }
    }

    int numIslands(vector <vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    bfs(grid, i, j);
                }

            }
        }
        return count;
    }

    void dfs(vector <vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands1(vector <vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }


    int numIslands2(vector <vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(grid);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '2';
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') uf.unite(i * n + j, (i - 1) * n + j);
                    if (i + 1 < m && grid[i + 1][j] == '1') uf.unite(i * n + j, (i + 1) * n + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') uf.unite(i * n + j, i * n + j - 1);
                    if (j + 1 < n && grid[i][j + 1] == '1') uf.unite(i * n + j, i * n + j + 1);
                }
            }
        }
        return uf.count();
    }

private:

    class UnionFind
    {

    private:

        vector<int> parent;

    public:
        // 这里的初始化非常重要，否则[["0"]] 应该返回0，但是 parent[0] == 0 就会返回 1
        // 对所有的[i][j] 为 1 的初始化为 parent[i * n + j] = i * n + j， m 行n 列
        UnionFind(vector <vector<char>> &grid) : parent(grid.size() * grid[0].size(), -1)
        {
            int m = grid.size(), n = grid[0].size();
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (grid[i][j] == '1') parent[i * n + j] = i * n + j;
                }
            }
        }

        void unite(int x, int y)
        {
            auto px = find(x);
            auto py = find(y);
            if (px != py)
            {
                parent[px] = py;
            }
        }

        int find(int x)
        {
            // 普通 find
//            if (x == parent[x])
//            {
//                return x;
//            }
//            return find(parent[x]);

            while (x != parent[x])
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;

        }

        int count()
        {
            int res = 0;
            for (int i = 0; i < parent.size(); i++)
            {
                if (parent[i] != i) continue;
                res += (parent[i] == i);
            }
            return res;
        }

    };

};
//leetcode submit region end(Prohibit modification and deletion)
