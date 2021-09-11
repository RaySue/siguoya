//给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
//
// 示例: 
//
// 输入: 3
//输出:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//] 
// Related Topics 数组 
// 👍 262 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 不看题解想不到系列
    //
    vector <vector<int>> generateMatrix(int n)
    {
        vector <vector<int>> ans(n, vector<int>(n, 0));
        int top = 0, left = 0, right = n - 1, bottom = n - 1, count = 1;
        int target = n * n;
        while(count <= target) // 递归终止条件
        {
            for (int i = left; i <= right; ++i) {ans[top][i] = count; count++;}
            top ++;
            for (int i = top; i <= bottom; ++i) {ans[i][right] = count; count++;}
            right--;
            for (int i = right; i >= left; --i) {ans[bottom][i] = count; count++;}
            bottom--;
            for (int i = bottom; i >= top; --i) {ans[i][left] = count; count++;}
            left++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
