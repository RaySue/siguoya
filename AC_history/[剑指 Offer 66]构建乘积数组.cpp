//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i
//+1]×…×A[n-1]。不能使用除法。 
//
// 
//
// 示例: 
//
// 输入: [1,2,3,4,5]
//输出: [120,60,40,30,24] 
//
// 
//
// 提示： 
//
// 
// 所有元素乘积之和不会溢出 32 位整数 
// a.length <= 100000 
// 
// 👍 65 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 注意：无法使用除法
    // 构造前向累乘数组和逆向累乘数组
    // 第 i 项的累乘数组不带第 i 项目
    // 分别构造前向累乘和逆向累乘，保证没有问题，不要一上来把问题搞复杂
    // 当要求优化的时候，再考虑合并运算
    vector<int> constructArr(vector<int> &a)
    {
        if (a.empty()) return a;
        vector<int> multiForward(a.size(), 1);
        vector<int> multiBackward(a.size(), 1);
        for (int i = 1; i < a.size(); ++i)
        {
            multiForward[i] = a[i - 1] * multiForward[i - 1];
        }
        for (int i = a.size() - 2; i >= 0; --i)
        {
            multiBackward[i] = a[i + 1] * multiBackward[i + 1];
        }
        for (int i = 0; i < a.size(); ++i)
        {
            a[i] = multiForward[i] * multiBackward[i];
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
