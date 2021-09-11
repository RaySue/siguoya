//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性： 
//
// 
// 每行的元素从左到右升序排列。 
// 每列的元素从上到下升序排列。 
// 
//
// 示例: 
//
// 现有矩阵 matrix 如下： 
//
// [
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// 给定 target = 5，返回 true。 
//
// 给定 target = 20，返回 false。 
// Related Topics 二分查找 分治算法 
// 👍 479 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一 半暴力法
    // 思路： 每行首尾判断 + 二分法
    // 每行判断是否包含 target，然后在该行用二分法
    // M 行 N 列
    // Complexity:
    // Time: O(M * log(N))
    // Space: O(1)
    bool binarySearch(vector<int> nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)
        {
            mid = left + (right - left >> 1);
            if (nums[mid] < target)
            {
                left = mid + 1;
            } else if (nums[mid] > target)
            {
                right = mid - 1;
            } else
            {
                return true;
            }
        }
        return false;
    }

    bool searchMatrix1(vector <vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (target >= matrix[i][0] && target <= matrix[i].back())
            {
                if (binarySearch(matrix[i], target)) return true;
            }
        }
        return false;
    }

    // 方法二： 对角线二分法 (是一个好的方法)
    // 沿着对角线从左上角走到右下角，然后对每个位置对应的其右面和下面的元素使用二分法
    // 所以每次移动都会减少一个二分法的长度
    // m 行的复杂度 lg(m) + lg(m-1) + ... + lg(1) = lg(m!)
    // n 列的复杂度 lg(n) + lg(n-1) + ... + lg(1) = lg(n!)
    // lg(n!)+lg(m!)
    // Time: O(max(lg(n!), lg(m!)))
    // Space: O(1)
    bool binarySearch(vector <vector<int>> &matrix, int i, int j, int target)
    {
        int l, r, mid;
        l = j;
        r = matrix[0].size() - 1;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (matrix[i][mid] < target)
            {
                l = mid + 1;
            } else if (matrix[i][mid] > target)
            {
                r = mid - 1;
            } else
            {
                return true;
            }
        }
        l = i;
        r = matrix.size() - 1;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (matrix[mid][j] < target)
            {
                l = mid + 1;
            } else if (matrix[mid][j] > target)
            {
                r = mid - 1;
            } else
            {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix2(vector <vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = 0;
        while(i < matrix.size() && j < matrix[0].size())
        {
            if (binarySearch(matrix, i++, j++, target)) return true;
        }
        return false;
    }


    // 方法三：启发式线性扫描，充分利用矩阵从左到右，从上到下递增的性质
    // 初始化左下角的点 ptr(matrix.size()-1, 0)
    // 1. 对比当前位置的值与target，如果改点大于target向上移动
    // 2. 如果小于target向右移动
    // 3. 如果ptr的x或y有超过边界的返回 false
    // Complexity:
    // Time: O(max(m, n))
    // Space: O(1)
    bool searchMatrix(vector <vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        int px = 0, py = matrix.size() - 1;
        while(px < matrix[0].size() && py >= 0)
        {
            if (matrix[py][px] < target) px++;
            else if (matrix[py][px] > target) py--;
            else return true;
        }
        return false;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
