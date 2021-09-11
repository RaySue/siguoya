//小扣在秋日市集选择了一家早餐摊位，一维整型数组 `staple` 中记录了每种主食的价格，一维整型数组 `drinks` 中记录了每种饮料的价格。小扣的计划
//选择一份主食和一款饮料，且花费不超过 `x` 元。请返回小扣共有多少种购买方案。
//
//注意：答案需要以 `1e9 + 7 (1000000007)` 为底取模，如：计算初始结果为：`1000000008`，请返回 `1`
//
//**示例 1：**
//>输入：`staple = [10,20,5], drinks = [5,5,2], x = 15`
//>
//>输出：`6`
//>
//>解释：小扣有 6 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
//>第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；
//>第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；
//>第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；
//>第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；
//>第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；
//>第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。
//
//**示例 2：**
//>输入：`staple = [2,1,1], drinks = [8,9,5,1], x = 9`
//>
//>输出：`8`
//>
//>解释：小扣有 8 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
//>第 1 种方案：staple[0] + drinks[2] = 2 + 5 = 7；
//>第 2 种方案：staple[0] + drinks[3] = 2 + 1 = 3；
//>第 3 种方案：staple[1] + drinks[0] = 1 + 8 = 9；
//>第 4 种方案：staple[1] + drinks[2] = 1 + 5 = 6；
//>第 5 种方案：staple[1] + drinks[3] = 1 + 1 = 2；
//>第 6 种方案：staple[2] + drinks[0] = 1 + 8 = 9；
//>第 7 种方案：staple[2] + drinks[2] = 1 + 5 = 6；
//>第 8 种方案：staple[2] + drinks[3] = 1 + 1 = 2；
//
//**提示：**
//+ `1 <= staple.length <= 10^5`
//+ `1 <= drinks.length <= 10^5`
//+ `1 <= staple[i],drinks[i] <= 10^5`
//+ `1 <= x <= 2*10^5` 👍 11 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 类似桶排序的思路
    // 1. 先弄 [1, x-1] 个桶表示价格，用于记录相应价格的主食，同时过滤掉大于等于x的主食
    // 2. 从小到大对每个桶进行累加，即得到小于该价格的主食的种类
    // 3. 遍历 drinks，通过 x - drinks[i] 的

    // 思路：
    // 暴力方法 O(N*M) O(1)：
    // 对staple排序，然后遍历drinks，如果 drinks[i] > x continue
    // if drinks[i] < x 那么就累加所有 staple 中价格小于等于 x - drinks[i] 的个数
    //
    // 利用额外的空间
    // 直接记录一下 staple 在每个价格能够买到的个数
    // 然后遍历drinks，进行组合
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x)
    {
        int ans = 0;
        vector<int> stapleCostCount(x, 0);
        for (auto c:staple)
        {
            if (c >= x) continue;
            stapleCostCount[c]++;
        }
        // 每个价格能够当前价格的主食和比其低的主食，记录能买的个数
        for (int i = 1; i < x; ++i)
        {
            stapleCostCount[i] += stapleCostCount[i - 1];
        }

        for (int i = 0; i < drinks.size(); ++i)
        {
            if (drinks[i] > x) continue;
            ans += stapleCostCount[x - drinks[i]];
            ans = ans % 1000000007;
        }
        return ans % 1000000007;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
