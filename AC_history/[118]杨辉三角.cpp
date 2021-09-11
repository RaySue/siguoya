//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//] 
// Related Topics 数组 
// 👍 341 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // -------------- 方法一： 循环
    vector<vector<int>> generate1(int numRows)
    {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1},{1,1}};
        if (numRows == 3) return {{1},{1,1},{1,2,1}};
        ans = {{1},{1,1},{1,2,1}};
        int n = numRows - 3;
        while(n > 0)
        {
            // n 个 几
            vector<int> tmp(ans.back().size() + 1, 1);  // 初始化 n 个 1
            for (int i = 1; i < ans.back().size(); ++i)
            {
                tmp[i] = ans.back()[i - 1] + ans.back()[i];
            }
            ans.push_back(tmp);
            n--;
        }
        return ans;
    }

    // ------------ 方法二： 递归
    vector<int> helper(int n)
    {
        if (n == 1) return {1};
        if (n == 2) return {1,1};
        if (n == 3) return {1,2,1};
        vector<int> back = helper(n - 1);
        vector<int> tmp(back.size() + 1, 1);  // 初始化 n 个 1
        for (int i = 1; i < back.size(); ++i)
        {
            tmp[i] = back[i - 1] + back[i];
        }
        return tmp;
    }

    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0) return {};
        vector<vector<int> > ans;
        for (int i = 1; i <= numRows; ++i)
        {
            ans.push_back(helper(i));
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
