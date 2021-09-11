// 我们将石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。
//
// 每次 move 操作都会移除一块所在行或者列上有其他石头存在的石头。 
//
// 请你设计一个算法，计算最多能执行多少次 move 操作？ 
//
// 
//
// 示例 1： 
//
// 输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
//输出：5
// 
//
// 示例 2： 
//
// 输入：stones =
// [[0,0],[0,2],[1,1],[2,0],[2,2]]
//输出：3
// 
//
// 示例 3： 
//
// 输入：stones = [[0,0]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= stones.length <= 1000 
// 0 <= stones[i][j] < 10000 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 92 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷，2021.01.15
    // 思路：
    // 依稀记得，第一次做这个题目的时候，感觉不是很顺畅，总结原因如下：
    // 1. 当时是按照 tag == 并查集 来刷的，所以知道使用并查集
    // 2. 并没有自己弄懂题目的时候就开始着手写并查集了
    // 3. 写完并查集，发现后续的逻辑没想清楚
    //
    // 这个题目的难点是如何进行删除，才能让删除的石头更多,
    // 我们如果上来就把连接两个部分的石头移除，那么就会少移除至少一个石头
    // 把坐标点画在图上，并查集能够告诉你，哪些石头能构成团（即在同一行或同一列）
    // 然后我们利用所有的元素的个数 减去 团数就是能够移除的最多的石头的个数
    int removeStones(vector <vector<int>> &stones)
    {
        UnionFind uf(stones.size());
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = i + 1; j < stones.size(); ++j)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    uf.unite(i, j);
                }
            }
        }
        return stones.size() - uf.count();
    }

private:

    class UnionFind
    {
    private:
        vector<int> parent;
        vector<int> rank;

    public:

        UnionFind(int n)
        {
            parent = vector<int>(n);
            rank = vector<int>(n);
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }


        int find(int x)
        {
            if (x != parent[x])
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y)
        {
            int px = find(x);
            int py = find(y);
            if (px != py)
            {
                if (rank[px] < rank[py])
                {
                    parent[px] = py;
                } else if (rank[px] > rank[py])
                {
                    parent[py] = px;
                } else {
                    parent[py] = px;
                    rank[py]++;
                }
            }
        }

        int count()
        {
            int ret = 0;
            for (int i = 0; i < parent.size(); ++i)
            {
                if (parent[i] == i) ret++;
            }
            return ret;
        }

    };

};
//leetcode submit region end(Prohibit modification and deletion)
