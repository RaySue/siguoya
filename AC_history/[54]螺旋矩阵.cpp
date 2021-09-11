//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
// 示例 1:
//
// 输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
//
//
// 示例 2:
//
// 输入:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]
//
// [[1,2,3,4],
// [5,6,7,8],
// [9,10,11,12],
// [13,14,15,16]]
//

// Related Topics 数组 
// 👍 474 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 利用双端队列解决螺旋矩阵问题
    // 时间复杂度： O(m*n) + O(m*n) = O(m*n)
    // 空间复杂度： O(m*n)
    vector<int> spiralOrder1(vector <vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty()) return ans;
        if (matrix[0].empty()) return ans;
        deque <deque<int>> buffer;
        for (int i = 0; i < matrix.size(); ++i)
        {
            buffer.push_back({});
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                buffer[i].push_back(matrix[i][j]);
            }
        }

        while (!buffer.empty())
        {
            deque<int> tmp = buffer.front();
            buffer.pop_front();
            // 第一行
            // 注意，这里不能用tmp.size()作为for循环的判断条件, 因为tmp的size是变换的
            while (!tmp.empty())
            {
                ans.push_back(tmp.front());
                tmp.pop_front();
            }
            // 最后一列
            if (buffer.empty() || buffer[0].empty()) break;
            int s = buffer.size();
            for (int i = 0; i < s; ++i)
            {
                ans.push_back(buffer[i].back());
                buffer[i].pop_back();
            }
            // 最后一行
            if (buffer.empty() || buffer[0].empty()) break;
            tmp = buffer.back();
            buffer.pop_back();
            while (!tmp.empty())
            {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
            // 第一列
            if (buffer.empty() || buffer[0].empty()) break;
            s = buffer.size();
            for (int i = s - 1; i >= 0; --i)
            {
                ans.push_back(buffer[i].front());
                buffer[i].pop_front();
            }
        }
        return ans;
    }


    // 旋转法
    // 注意，方阵和非方阵时候的区别
    // 方阵的时候最终 top bottom left right 都为同一个值，即中心
    // 非方阵的时候 只有其中一对 为同一个值，如果高短，那么left right最终不相等， 因为还没减到中心，高度已经没有了
    vector<int> spiralOrder(vector <vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, right = n - 1, bottom = m - 1, left = 0;
        int target = n * m;
        for(;;)
        {
            // top
            for(int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
            if (ans.size() >= target) break;
            top ++;

            // right
            for(int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
            if (ans.size() >= target) break;
            right --;

            // bottom
            for(int i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
            if (ans.size() >= target) break;
            bottom --;

            // left
            for(int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
            if (ans.size() >= target) break;
            left ++;
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
