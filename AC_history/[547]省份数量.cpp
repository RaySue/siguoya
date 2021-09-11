//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：isConnected = [[1,1,0],
//                    [1,1,0],
//                    [0,0,1]]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：isConnected = [[1,0,0],
//                    [0,1,0],
//                    [0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
// 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 397 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 改名了，以前叫朋友圈，现在叫省份数量了，真奇怪
    // 二刷 2021.01.06 并查集，无他，唯手熟尔
    // 三刷 2021.01.07 昨天刚刷完，今天就是每日一题，😂 那就在熟悉一遍 并查集，
    // 两次复习同一个题的时候，切勿要背着写，要变思考边写，这个过程可以不断的问自己问题，并查集有几种方法，find方法该怎么实现...
    int findCircleNum(vector <vector<int>> &isConnected)
    {
        // 并查集写好，这个题目就再无难处
        UnionFind uf(isConnected.size());

        for (int i = 0; i < isConnected.size(); ++i)
        {
            for (int j = i + 1; j < isConnected[i].size(); ++j)
            {
                if (isConnected[i][j] == 0) continue;
                uf.unite(i, j);
            }
        }
        return uf.count();
    }

private:

    class UnionFind
    {

    private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;  // 防止出现链表 线性查找复杂度的情况

    public:
        UnionFind(int n)
        {
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }


        // find 是要找到集合的 首领(x == parent[x])，边 find 边 压缩 展平式 压缩
        int find(int x)
        {
            if (x != parent[x])  // 相同的题刷多遍是有道理的，因为利用的是递归，所以这个位置不能是 while 必须是 if
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

//         折半式压缩
//        int find(int x)
//        {
//            while (x != parent[x])
//            {
//                parent[x] = parent[parent[x]];
//                x = parent[x];
//            }
//            return x;
//        }

        // 合并两个 元素 到一个集合中，就是对各自的首领进行合并即可
        // 合并的时候有个问题，如何对两个集合进行合并，才能让后续查找的效率更高呢，也就是让路径压缩更省力呢？
        // 利用 rank 优化
        void unite(int x, int y)
        {

            int px = find(x);
            int py = find(y);

            if (px != py)
            {
                // 谁大谁是爹
                if (rank[px] > rank[py])
                {
                    parent[py] = px;  // 喊 爹
                } else if (rank[px] < rank[py])
                {
                    parent[px] = py;
                } else
                {
                    // 如果一样大，那么随便了，当爹的折寿，添加 rank 值
                    parent[px] = py;
                    rank[py]++;
                }
            }
        }

        int count()
        {
            int ret = 0;
            for (int i = 0; i < parent.size(); ++i)
            {
                if (i == parent[i]) ret++;
            }
            return ret;
        }


    };

};
//leetcode submit region end(Prohibit modification and deletion)
