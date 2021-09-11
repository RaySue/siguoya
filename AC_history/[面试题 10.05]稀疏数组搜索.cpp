// 稀疏数组搜索。**有个排好序的字符串数组**，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
//
// 示例1: 
//
//  输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""],
// s = "ta"
// 输出：-1
// 说明: 不存在返回-1。
// 
//
// 示例2: 
//
//  输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], 
//s = "ball"
// 输出：4
// 
//
// 提示: 
//
// 
// words的长度在[1, 1000000]之间 
// 
// Related Topics 二分查找 
// 👍 29 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 二分查找，
    // 如果 words[mid] == s, 那么就返回 mid
    // 如果 mid 为 ""， 那么我就从 mid 位置左右找，找到最近的字符串， 判断
    // words[mid] > s; r = mid - 1;
    // words[mid] < s; l = mid + 1;
    int findString(vector <string> &words, string s)
    {
        int l = 0, r = words.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (words[mid] == s) return mid;
            int lmid = mid - 1;
            int rmid = mid + 1;
            if (lmid < 0 && rmid >= words.size()) break;
            while (words[mid] == "")
            {
                if (words[lmid] != "")
                {
                    mid = lmid;
                    break;
                }
                if (words[rmid] != "")
                {
                    mid = rmid;
                    break;
                }
                lmid--;
                rmid++;
            }
            cout << lmid << " " << rmid << endl;
            if (words[mid] < s)
            {
                l = mid + 1;
            } else if (words[mid] > s)
            {
                r = mid - 1;
            }
            cout << l << " " << r << endl;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
