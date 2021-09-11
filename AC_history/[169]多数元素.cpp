// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [3,2,3]
//输出: 3 
//
// 示例 2: 
//
// 输入: [2,2,1,1,1,2,2]
//输出: 2
// 
// Related Topics 位运算 数组 分治算法 
// 👍 727 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement1(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        unordered_map<int, int> mp;
        int maxTime = 0;
        int ans;
        for(int a : nums)
        {
            mp[a] ++;
            if(mp[a] > maxTime)
            {
                maxTime = mp[a];
                ans = a;
            }
        }
        return ans;
    }


    int majorityElement(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int life = 1;
        int player = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == player)
            {
                life ++;
            } else {
                life --;
                if (life < 0)
                {
                    player = nums[i];
                    life = 1;
                }
            }
        }
        return player;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
