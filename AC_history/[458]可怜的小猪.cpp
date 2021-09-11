//有 buckets 桶液体，其中 正好 有一桶含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否
//会死进行判断。不幸的是，你只有 minutesToTest 分钟时间来确定哪桶液体是有毒的。 
//
// 喂猪的规则如下： 
//
// 
// 选择若干活猪进行喂养 
// 可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。 
// 小猪喝完水后，必须有 minutesToDie 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。 
// 过了 minutesToDie 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。 
// 重复这一过程，直到时间用完。 
// 
//
// 给你桶的数目 buckets ，minutesToDie 和 minutesToTest ，返回在规定时间内判断哪个桶有毒所需的 最小 猪数。 
//
// 
//
// 示例 1： 
//
// 
//输入：buckets = 1000, minutesToDie = 15, minutesToTest = 60
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：buckets = 4, minutesToDie = 15, minutesToTest = 15
//输出：2
// 
//
// 示例 3： 
//
// 
//输入：buckets = 4, minutesToDie = 15, minutesToTest = 30
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= buckets <= 1000 
// 1 <= minutesToDie <= minutesToTest <= 100 
// 
// Related Topics 数学 
// 👍 145 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 从一头猪开始推导
    // 组合数的求和公式 Cn0 + Cn1 + ... + Cnn = 2^n
    // 如果尝试时间 15分钟， 给定时间也是15分钟， 那么一头猪只能验证 两桶水
    // 喝第 0 桶水，没事，说明 第 1 通水有毒；毒死，说明第 0 桶有毒。
    // 同样的条件如果有两头猪 A B
    // 那么:
    // A - 0
    // B - 1
    // AB - 2
    // 如果 AB 都没毒死，那么第四桶水有毒，则两头猪可以尝试 4 桶水
    // 再考虑有三头猪 A B C
    // A - 0; B - 1; C - 2;  n
    // AB - 3; AC - 4; BC - 5;  Cn2
    // ABC - 6   Cn3
    // 如果都没死，那么第 8 桶水有问题，则 三头猪可以尝试 8 桶水，如果AB死了说明第4桶水有问题，以此类推
    // 那么四头猪的情况呢
    // 4 + 6 + 4 + 1 + (1，都没死则最后一桶有毒) = 16
    // 即 Cn1 + Cn2 + Cn3 + Cn4 + ... + Cnn + 1(Cn0) 恰好是 2 ^ n, 这里的 2 是一个猪可以验的桶的个数
    // x ^ n = buckets; n * log(x) = log(buckets); n = log(buckets) / log(x);
    // 一头猪可以验证多少桶水 minutesToTest / minutesToDie + 1
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int base = minutesToTest / minutesToDie + 1;
        int ans = ceil(log(buckets) / log(base));  // 向上取整
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
