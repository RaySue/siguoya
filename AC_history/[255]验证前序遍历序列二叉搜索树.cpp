//给定一个整数数组，你需要验证它是否是一个二叉搜索树正确的先序遍历序列。 
//
// 你可以假定该序列中的**数都是不相同的**。
//
// 参考以下这颗二叉搜索树： 
//
//      5
//    / \
//   2   6
//  / \
// 1   3
//
// 示例 1： 
//
// 输入: [5,2,6,1,3]    [2]  5  [6,1,3]
//输出: false 
//
// 示例 2： 
//
// 输入: [5,2,1,3,6]    [2,1,3] 5 [6]
//输出: true 
//
//  [6, 1, 3]  1, 3

// 进阶挑战： 
//
// 您能否使用恒定的空间复杂度来完成此题？ 
// Related Topics 栈 树 
// 👍 69 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.05
    // 思路：
    // 已知条件：
    // BST 左子树 严格 小于 根节点，根节点严格小于 右子树，所有子树都遵循
    // 利用深度优先搜索
    // 1. 前序遍历的结果是根节点是第一个
    // 2. 利用 给定数组的第一个值 将后面的数组划分为left、right两个部分
    // 3. 如果 right部分存在 值 小于 根节点 返回 false，否则遍历完返回 true

    // base 解法 TLE (Time Limit Exceeded) 60/63
    bool dfs(vector<int> root)
    {
        if (root.size() <= 1) return true;
        int rootVal = root[0];
        vector<int> left, right;
        int i = 1;
        for (; i < root.size(); ++i)
        {
            if (root[i] < rootVal) left.push_back(root[i]);
            else break;
        }
        right.assign(root.begin() + i, root.end());
        for (int i = 0; i < right.size(); ++i)
            if (right[i] < rootVal) return false;
        return dfs(left) && dfs(right);
    }


    bool dfs(vector<int> &root, int start, int end)
    {
        if (end - start <= 1) return true;
        int rootVal = root[start];
        int i = start + 1;

        for (; i < end; ++i) if (root[i] > rootVal) break;
        end = i;

        for (int j = end; j < root.size(); ++j)  // BST 要求右子树是要大于根节点的
            if (rootVal > root[j]) return false;

        return dfs(root, start + 1, end) && dfs(root, end, root.size());
    }


    bool verifyPreorder1(vector<int> &preorder)
    {
        if (preorder.size() <= 1) return true;
        return dfs(preorder, 0, preorder.size());
    }


    // -----------------------------------------

    // 二刷 2021.01.07 利用单调栈, 单调递减 if (!sta.empty() && nums[sta.top()] < value)
    /**
    结论
        维护一个单调递减的栈，以及最新pop出来的值。待 push 进栈的节点值必须大于已经 pop 出来的所有元素的值，才能是合法的BST。
    思路
        BST的性质是左子树小于root，右子树大于root，所以校验这个性质即可。
        单调递减栈的 单调性用来假设 root 到 左子树的性质 正确，
        再用待 push 进栈的节点值必须大于已经 pop 出来的所有元素的值来校验 root 到右子树的性质
        得益于单调性，已经pop出来的所有元素的值是不断递增的，所以用最新的值来校验即可

     */
     // 单调递减的栈，递增的 minVal
    //
    //     5
    //    / \
    //   2   6
    //  / \
    // 1   3
    // 比栈顶元素大的入栈，并将前面比其小的都出栈，最后一个出栈的作为 minVal
    // 5 2 1
    // 3 来了 1 2 出栈 此时的 minVal = 2
    // 即 3 的所有子节点必须大于 minVal = 2
    // 6 入栈 minVal = 5，后续入栈的不可以有比 5 小的，minVal 是递增的
    //
    // ex: 5 6 2
    // 根节点 5 入栈， 6 入栈的时候（5出栈），minVal变为了 5，表示右子树开始了，所有的点不可以小于根节点
    //
    // ex: 5 3 1 2 6
    //
    //       5
    //      / \
    //     3   6
    //    /
    //   1
    //    \
    //     2
    //
    // 只需要保证最后一个出栈的 元素（根） 其右子树没有比它小的就行
    // 右子树的值肯定是在 根 和 左子树 后面

    // 二刷 2021.01.13 利用单调栈
    // 思路：
    // BST  根节点大于左子树，小于右子树，
    // 所以一旦我们遇到了 大于 根节点的值，意味着右子树开始了
    // 此时，根节点作为 minVal 如果右子树有大于 minVal 的返回 false
    bool verifyPreorder(vector<int> &preorder)
    {
        stack<int> sta;
        int minVal = INT_MIN;
        for (int i = 0; i < preorder.size(); ++i)
        {
            if (preorder[i] < minVal) return false;
            // 记住，单调栈必须是 while
            while (!sta.empty() && preorder[i] > preorder[sta.top()])
            {
                minVal = preorder[sta.top()];
                sta.pop();
            }
            sta.push(i);
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
