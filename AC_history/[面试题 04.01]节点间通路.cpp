// 节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。
//
// 示例1: 
//
//  输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
// 输出：true
// 
//
// 示例2: 
//
//  输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]],
//  start = 0, target = 4
// 输出 true
// 
//
// 提示： 
//
// 
// 节点数量n在[0, 1e5]范围内。 
// 节点编号大于等于 0 小于 n。 
// 图中可能存在自环和平行边。 
// 
// Related Topics 图 
// 👍 19 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 这个题目可以使用 广度优先搜索 来解决
    // 先对节点通路进行去重 利用 unordered_map<int, vector<int>>
    // 广度优先搜索，从起始点开始，每层搜索，注意去过的地方需要用 isVis标识，防止走回头路（因为有环）
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target)
    {
        unordered_map<int, unordered_set<int>> mp;
        vector<bool> isVis(n);
        for (vector<int> r:graph)
        {
            if (!mp.count(r[0])) mp[r[0]] = {r[1]};
            else mp[r[0]].insert(r[1]);
        }
        queue<int> q;
        q.push(start);
        isVis[start] = true;
        while(!q.empty())
        {
            unordered_set<int> cur = mp[q.front()];q.pop();
            unordered_set<int>::iterator iter;
            for (iter = cur.begin(); iter != cur.end(); ++iter)
            {
                if (*iter == target) return true;
                if (!isVis[*iter]){
                    q.push(*iter);
                    isVis[*iter] = true;
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
