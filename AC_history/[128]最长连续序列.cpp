// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//
// 
//
// 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 104 
// -109 <= nums[i] <= 109 
// 
// Related Topics 并查集 数组 
// 👍 633 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class UnionFind
{

private:
    vector<int> parent;
    vector<int> rank;


public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }

    }

    int find(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
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

    int count()
    {
        int ans = 0;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == i) ans++;
        }
        return ans;
    }


};

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
