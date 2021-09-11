//有一个二维矩阵 A 其中每个元素的值为 0 或 1 。 
//
// 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。 
//
// 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。 
//
// 返回尽可能高的分数。 
//
// 
//
// 
// 
//
// 示例： 
//
// 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
//输出：39
//解释：
//转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
//0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 20 
// 1 <= A[0].length <= 20 
// A[i][j] 是 0 或 1 
// 
// Related Topics 贪心算法 
// 👍 124 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 每日一题打卡
    // 刚看到这个题目的时候我以为使用暴力的回溯算法，每次选择一行或者一列，然后计算 A 的得分，找到最大值
    // 但是对于二维矩阵来说，这样做的代价太大了，还是需要根据题意寻找思路
    //
    // 根据题目给出的示例进行推演，我发现
    // 1. 每行的首位置一定是要为1的才能保证最大，所以以此为根据修改行
    // 2. 每列的 1 的数目一定是要最多，以此为根据修改每一列
    // 直到不能修改为止，所以我写了一个递归，可能只会修改以此，并不需要用到递归

    // 计算最终的矩阵的得分
    int calcScore(vector <vector<int>> &A)
    {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            int row = 0;
            for (int j = A[0].size() - 1; j >= 0; --j)
            {
                row += A[i][j] << (A[0].size() - j - 1);
            }
            ans += row;
        }
        return ans;
    }

    // 对每行进行修改，如果行首的位置不是 1，那么就需要进行修改
    int changeRow(vector <vector<int>> &A)
    {
        int count = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i][0] == 0)
            {
                for (int j = 0; j < A[0].size(); ++j)
                {
                    A[i][j] = A[i][j] == 1 ? 0 : 1;
                }
                count++;
            }
        }
        return count;
    }

    // 对每列进行修改，如果每列的1的最大个数不超过一半，那么需要进行修改
    int changeCol(vector <vector<int>> &A)
    {
        vector<int> needChange;
        for (int j = 0; j < A[0].size(); ++j)
        {
            int count = 0;
            for (int i = 0; i < A.size(); ++i)
            {
                if (A[i][j] == 1) count++;
            }
            if (count * 2 < A.size()) needChange.push_back(j);

        }
        for (int j:needChange)
        {
            for (int i = 0; i < A.size(); ++i)
            {
                A[i][j] = A[i][j] == 1 ? 0 : 1;
            }
        }
        return needChange.size();
    }

    int matrixScore(vector <vector<int>> &A)
    {
        int row = changeRow(A);
        int col = changeCol(A);
        return (row + col == 0) ? calcScore(A) : matrixScore(A);
    }

};



//  官方答案

// --- 方法一：贪心 ---
// 根据题意，能够知道一个重要的事实：给定一个翻转方案，则它们之间任意交换顺序后，得到的结果保持不变。
// 因此，我们总可以先考虑所有的行翻转，再考虑所有的列翻转。不难发现一点：为了得到最高的分数，
// 矩阵的每一行的最左边的数都必须为 1。为了做到这一点，我们可以翻转那些最左边的数不为 1 的那些行，
// 而其他的行则保持不动。
// 当将每一行的最左边的数都变为 1 之后，就只能进行列翻转了。
// 为了使得总得分最大，我们要让每个列中 1 的数目尽可能多。
// 因此，我们扫描除了最左边的列以外的每一列，如果该列 0 的数目多于 1 的数目，
// 就翻转该列，其他的列则保持不变。
// 实际编写代码时，我们无需修改原矩阵，而是可以计算每一列对总分数的「贡献」，从而直接计算出最高的分数。
// 假设矩阵共有 mm 行 nn 列，计算方法如下：
// 对于最左边的列而言，由于最优情况下，它们的取值都为 1，因此每个元素对分数的贡献都为 2n−1，
// 总贡献为 m x 2^{n-1}
// 对于第 j 列（j>0，此处规定最左边的列是第 0 列）而言，我们统计这一列 0,1 的数量，
// 令其中的最大值为 k，则 k 是列翻转后的 1 的数量，该列的总贡献为 k x 2^{n-j-1}
// 需要注意的是，在统计 0,1 的数量的时候，要考虑最初进行的行反转。


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int ret = m * (1 << (n - 1));

        for (int j = 1; j < n; j++) {
            int nOnes = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][0] == 1) {
                    nOnes += A[i][j];
                } else {
                    nOnes += (1 - A[i][j]); // 如果这一行进行了行反转，则该元素的实际取值为 1 - A[i][j]
                }
            }
            int k = max(nOnes, m - nOnes);
            ret += k * (1 << (n - j - 1));
        }
        return ret;
    }
};



//leetcode submit region end(Prohibit modification and deletion)
