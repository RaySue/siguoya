//给定一个嵌套的整数列表，请返回该列表按深度加权后所有整数的总和。 
//
// 每个元素要么是整数，要么是列表。同时，列表中元素同样也可以是整数或者是另一个列表。 
//
// 示例 1: 
//
// 输入: [[1,1],2,[1,1]]
//输出: 10 
//解释: 因为列表中有四个深度为 2 的 1 ，和一个深度为 1 的 2。 
//
// 示例 2: 
//
// 输入: [1,[4,[6]]]
//输出: 27 
//解释: 一个深度为 1 的 1，一个深度为 2 的 4，一个深度为 3 的 6。所以，1 + 4*2 + 6*3 = 27。 
// Related Topics 深度优先搜索 
// 👍 27 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:

    int ans = 0;

    // 深度优先搜索
    // 1. 遇到整数乘以当前的深度加入 ans 中
    // 2. 遇到数组，那么就深度搜索（递归）继续对里面的整数进行做和
    void dfs(vector<NestedInteger> &nestedList, int depth)
    {
        if (nestedList.empty()) return;
        for (int i = 0; i < nestedList.size(); ++i)
        {
            if (nestedList[i].isInteger())
            {
                ans += nestedList[i].getInteger() * depth;
            } else {
                dfs(nestedList[i].getList(), depth + 1);
            }
        }
    }

    int depthSum(vector<NestedInteger>& nestedList)
    {
        if (nestedList.empty()) return 0;
        dfs(nestedList, 1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
