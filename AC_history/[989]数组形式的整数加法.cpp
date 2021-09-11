// 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
//
// 给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：A = [1,2,0,0], K = 34
//输出：[1,2,3,4]
//解释：1200 + 34 = 1234
// 
//
// 示例 2： 
//
// 输入：A = [2,7,4], K = 181
//输出：[4,5,5]
//解释：274 + 181 = 455
// 
//
// 示例 3： 
//
// 输入：A = [2,1,5], K = 806
//输出：[1,0,2,1]
//解释：215 + 806 = 1021
// 
//
// 示例 4： 
//
// 输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
//输出：[1,0,0,0,0,0,0,0,0,0,0]
//解释：9999999999 + 1 = 10000000000
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 10000 
// 0 <= A[i] <= 9 
// 0 <= K <= 10000 
// 如果 A.length > 1，那么 A[0] != 0 
// 
// Related Topics 数组 
// 👍 98 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.22 每日一题
    // 思路：
    // 1. 把 K 转为数组形式的表达的逆序 KK
    // 2. 对 A 进行逆序 AA
    // 3. 遍历 AA、KK 逐个相加
    // 4. 对结果逆序
    // Complexity:
    // Time: O(N)
    // Space: O(K)
    // 相加模型：
    // 1. 两个指针分别指向不同的数组的逆序的首部，carry = 0
    // 2. 判断条件取并
    // 3. 结果逆序回来
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        vector<int> KK;
        while(K > 0)
        {
            int tmp = K % 10;
            K /= 10;
            KK.push_back(tmp);
        }
        reverse(A.begin(), A.end());
        int pa = 0, pk = 0, carry = 0;
        while(pa < A.size() || pk < KK.size() || carry > 0)
        {
            int n1 = pa < A.size()? A[pa]: 0;
            int n2 = pk < KK.size()? KK[pk++]: 0;
            int cur = (n1 + n2 + carry) % 10;
            if (pa < A.size())
            {
                A[pa] = cur;
            } else {
                A.push_back(cur);
            }
            carry = (n1 + n2 + carry) / 10;
            pa++;
        }
        reverse(A.begin(), A.end());
        return A;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
