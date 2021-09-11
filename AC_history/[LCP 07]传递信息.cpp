//小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下： 
//
// 
// 有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0 
// 每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。 
// 每轮信息必须需要传递给另一个人，且信息可重复经过同一个人 
// 
//
// 给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k 轮传递到编号
//为 n-1 的小伙伴处的方案数；若不能到达，返回 0。 
//
// 示例 1： 
//
// 
// 输入：n = 5, relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], k = 3 
//
// 输出：3 
//
// 解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4， 0->2->
//3->4。 
// 
//
// 示例 2： 
//
// 
// 输入：n = 3, relation = [[0,2],[2,1]], k = 2 
//
// 输出：0 
//
// 解释：信息不能从小 A 处经过 2 轮传递到编号 2 
// 
//
// 限制： 
//
// 
// 2 <= n <= 10 
// 1 <= k <= 5 
// 1 <= relation.length <= 90, 且 relation[i].length == 2 
// 0 <= relation[i][0],relation[i][1] < n 且 relation[i][0] != relation[i][1] 
// 
// 👍 28 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // BFS
    /**
     * 思路：
     * 把关系用hashmap存起来，int -> vector<int>
     * 利用 bfs 进行搜索，终止条件是第k轮迭代
     * 结果是所有 等于n-1的个数
     */
    int bfs(unordered_map<int, vector<int>> relation, int k, int target)
    {
        int ans = 0;
        queue<int> q;
        q.push(0);
        int iter = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                int cur = q.front();
                q.pop();
                if (iter == k)
                {
                    if (cur == target) ans++;
                }
                vector<int> nextIter = relation[cur];
                for (auto n:nextIter) q.push(n);
            }
            if (iter == k) break;
            iter++;
        }
        return ans;
    }

    int numWays(int n, vector <vector<int>> &relation, int k)
    {
        if (n < 1) return 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) mp[i] = {};
        for (auto r : relation)
        {
            mp[r[0]].push_back(r[1]);
        }

        return bfs(mp, k, n - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
