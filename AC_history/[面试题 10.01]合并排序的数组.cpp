//给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。 
//
// 初始化 A 和 B 的元素数量分别为 m 和 n。 
//
// 示例: 
//
// 输入:
//A = [1,2,3,0,0,0], m = 3
//B = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6] 
//
// 说明: 
//
// 
// A.length == n + m 
// 
// Related Topics 数组 双指针 
// 👍 73 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 排序法

    // 利用额外数据的方法

    // 前插法

    // 尾插法
    void merge(vector<int>& A, int m, vector<int>& B, int n)
    {
        if(m == 0) A.assign(B.begin(), B.end());
        int p = A.size() - 1;
        int a = m - 1;
        int b = n - 1;
        for (;;)
        {
            if (a < 0 || b < 0) break;
            if (A[a] > B[b])
            {
                A[p] = A[a];
                a--;
            } else {
                A[p] = B[b];
                b--;
            }
            p --;
        }
        if (p >= 0)
        {
            while (b >= 0)
            {
                A[p] = B[b];
                b--;
                p--;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
