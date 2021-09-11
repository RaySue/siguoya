//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [3,4,3,3]
//输出：4
// 
//
// 示例 2： 
//
// 输入：nums = [9,1,7,9,7,9,7]
//输出：1 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10000 
// 1 <= nums[i] < 2^31 
// 
//
// 
// 👍 104 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.07
    // 面试的时候如果没有要求空间复杂度，那就先给出 hash map 的解法
    // Complexity:
    // Time: O(N)
    // Space: O(N)

    // 如果要求时间复杂度，再使用 位运算

    // 利用位运算的思路：
    /**
        1. 根据题意我们可以找出这么一个规律：假设不存在这个 single number，
        那么 nums 中所有元素的二进制形式加起来之后，每一位必然都可以被 3 整除。
        因为每个数字都出现了三次，那么它们的二进制形式每一位也都出现了三次，那加起来之后每一位当然可以被 3 整除了。

        2. 现在加上这个 single number，我们可以进一步想到：同样把 nums 中所有元素的二进制形式加起来，这时候就不是每一位都能被 3 整除了，
        因为混入了一个只出现了一次的元素。所以我们只需要看加起来之后的和的哪一位不能被 3 整除，
        就说明这个 single number 的二进制形式在这一位是 1。然后把这些 single number 是 1 的位转换成十进制再加起来，就是 single number 的十进制形式了。

        3. 举个例子：假设 single number = 1，然后 nums 中所有元素的二进制形式加起来之后等于 3334（即 3333 + 1 = 3334）。
        那么我们就知道，4 这一位不能被 3 整除，说明 single number 在从右往左第一位是 1。
        然后因为剩下的全都能被 3 整除，所以 single number 在剩下的位上都是 0。由此可得 single number = 0001 = 1。
     */
    // Complexity:

    // 中间过渡方法 利用 vector<int> binary(32);
    int singleNumber1(vector<int> &nums)
    {
        vector<int> binary(32);

        // 对每个数字计算其在 32 位上的累加
        for(int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                // 位运算的优先级 小于 比较运算
                if ((nums[i] & (1 << j)) != 0)
                {
                    binary[j]++;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (binary[i] % 3 != 0)
            {
                ret += (1 << i);
            }
        }
        return ret;
    }

    // 最终的解法
    // Time: O(N)
    // Space: O(1)
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            int count = 0;
            int p =  (1 << i);
            for (int n: nums)
            {
                if ((n & p) != 0)
                {
                    count ++;
                }
            }
            if (count % 3 != 0)  // 这有出现一次的数，在这一位才不会整除 3
            {
                ret += p;
            }
        }
        return ret;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
