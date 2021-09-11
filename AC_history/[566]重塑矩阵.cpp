//在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。 
//
// 给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。 
//
// 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。 
//
// 如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。 
//
// 示例 1: 
//
// 
//输入: 
//nums = 
//[[1,2],
// [3,4]]
//r = 1, c = 4
//输出: 
//[[1,2,3,4]]
//解释:
//行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
// 
//
// 示例 2: 
//
// 
//输入: 
//nums = 
//[[1,2],
// [3,4]]
//r = 2, c = 4
//输出: 
//[[1,2],
// [3,4]]
//解释:
//没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
// 
//
// 注意： 
//
// 
// 给定矩阵的宽和高范围在 [1, 100]。 
// 给定的 r 和 c 都是正数。 
// 
// Related Topics 数组 
// 👍 145 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 1. 先判断一下，如果r * c和原始的h * w不相等，那么直接返回原始矩阵 O(1) O(1)
    // 2. 将 nums 拉成一行，存在ans中， O(r) O(r * c)
    // 3. 将 nums 清空，然后将 ans reshape到nums上面再返回 O(r * c) O(1)
    // Complexity：
    // Time: O(r * c)
    // Space: O(r * c)
    vector <vector<int>> matrixReshape(vector <vector<int>> &nums, int r, int c)
    {
        if (nums.empty() || nums[0].empty()) return nums;
        vector<int> ans = {};
        int row = nums.size();
        int col = nums[0].size();
        if (row * col != r * c) return nums;

        for (int i = 0; i < nums.size(); ++i)
        {
            ans.insert(ans.end(), nums[i].begin(), nums[i].end());
        }
        nums.clear();
        for (int i = 0; i < r; ++i)
        {
            nums.push_back({});
            for (int j = 0; j < c; ++j)
            {
                nums[i].push_back(ans[i * c + j]);
            }
        }
//        return {ans};
        return nums;
    }


    // 更简洁的解法
    vector <vector<int>> matrixReshape(vector <vector<int>> &nums, int r, int c)
    {
        //先判断数组是不是可以重塑的
        auto r_Nums = nums.size();
        auto c_Nums = nums[0].size();

        //代表不能重塑返回原矩阵
        if (r_Nums * c_Nums != r * c)
            return nums;

        //可以重塑开始重塑
        vector <vector<int>> new_Nums(r, vector<int>(c));
        for (int i = 0; i < r * c; i++)
        {
            // i / c 是 ri, i % c 是 ci
            new_Nums[i / c][i % c] = nums[i / c_Nums][i % c_Nums];
        }
        return new_Nums;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
