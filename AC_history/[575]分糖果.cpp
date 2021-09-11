// 给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。
// 你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
//
// 示例 1: 
//
// 
//输入: candies = [1,1,2,2,3,3]
//输出: 3
//解析: 一共有三种种类的糖果，每一种都有两个。
//     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
// 
//
// 示例 2 : 
//
// 
//输入: candies = [1,1,2,3]
//输出: 2
//解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
// 
//
// 注意: 
//
// 
// 数组的长度为[2, 10,000]，并且确定为偶数。 
// 数组中数字的大小在范围[-100,000, 100,000]内。
// 
// 
// 
// 
// Related Topics 哈希表 
// 👍 86 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 方法一： 利用集合
    // 思路：目的是要让妹妹得到的糖果种类最多
    // 我们需要先统计糖果的种类数，利用unordered_set
    // 考虑到要平均分，那么如果糖果种类的个数大于糖果数的一半的时候，糖果数的一半就是妹妹能够拿到的糖果种类的最大值
    // 否则，就把尽量把所有不同的糖果分给妹妹即可。
    // 时间复杂度 O(N)
    // 空间复杂度 O（N）
    int distributeCandies(vector<int>& candies)
    {
        unordered_set<int> candySet;
        for (int candy:candies) candySet.insert(candy);
        return candySet.size() >= candies.size() / 2? candies.size() / 2: candySet.size();
    }

};
//leetcode submit region end(Prohibit modification and deletion)
