//假设你设计一个游戏，用一个 m 行 n 列的 2D 网格来存储你的游戏地图。 
//
// 起始的时候，每个格子的地形都被默认标记为「水」。我们可以通过使用 addLand 进行操作，将位置 (row, col) 的「水」变成「陆地」。 
//
// 你将会被给定一个列表，来记录所有需要被操作的位置，然后你需要返回计算出来 每次 addLand 操作后岛屿的数量。 
//
// 注意：一个岛的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。你可以假设地图网格的四边均被无边无际的「水」所包围。 
//
// 请仔细阅读下方示例与解析，更加深入了解岛屿的判定。 
//
// 示例: 
//
// 输入: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
//输出: [1,1,2,3]
// 
//
// 解析: 
//
// 起初，二维网格 grid 被全部注入「水」。（0 代表「水」，1 代表「陆地」） 
//
// 0 0 0
//0 0 0
//0 0 0
// 
//
// 操作 #1：addLand(0, 0) 将 grid[0][0] 的水变为陆地。 
//
// 1 0 0
//0 0 0   Number of islands = 1
//0 0 0
// 
//
// 操作 #2：addLand(0, 1) 将 grid[0][1] 的水变为陆地。 
//
// 1 1 0
//0 0 0   岛屿的数量为 1
//0 0 0
// 
//
// 操作 #3：addLand(1, 2) 将 grid[1][2] 的水变为陆地。 
//
// 1 1 0
//0 0 1   岛屿的数量为 2
//0 0 0
// 
//
// 操作 #4：addLand(2, 1) 将 grid[2][1] 的水变为陆地。 
//
// 1 1 0
//0 0 1   岛屿的数量为 3
//0 1 0
// 
//
// 拓展： 
//
// 你是否能在 O(k log mn) 的时间复杂度程度内完成每次的计算？（k 表示 positions 的长度） 
// Related Topics 并查集 
// 👍 58 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    bool isAdjacent(vector<int> p1, vector<int> p2)
    {
        return (p1[0] == p2[0] && abs(p1[1] - p2[1]) == 1) || (p1[1] == p2[1] && abs(p1[0] - p2[0]) == 1);
    }

    vector<int> numIslands2(int m, int n, vector <vector<int>> &positions)
    {
        vector<int> ans;
        if (positions.empty()) return ans;
        UnionFind uf(positions.size());
        for (int i = 0; i < positions.size(); ++i)
        {
            ans.push_back(uf.count());
            for (int j = 0; j < i; ++j)
            {
                if (isAdjacent(positions[i], positions[j])) uf.unite(i, j);
            }
        }

        return ans;
    }


private:

    class UnionFind
    {
    private:
        vector<int> parent;
        vector<int> rank;


    public:

        UnionFind(int n) : parent(n), rank(n)
        {
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        void unite(int x, int y)
        {
            int px = find(x);
            int py = find(y);
            if (px != py)
            {
                if (rank[px] > rank[py])
                {
                    parent[py] = px;
                } else if (rank[py] > rank[px])
                {
                    parent[px] = py;
                } else {
                    parent[px] = py;
                    rank[py]++;
                }
            }
        }

        int find(int x)
        {
            while(x != parent[x])
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        int count()
        {
            int res = 0;
            for (int i = 0; i < parent.size(); ++i)
            {
                res += (i == parent[i]);
            }
            return res;
        }
    };


};
//leetcode submit region end(Prohibit modification and deletion)
