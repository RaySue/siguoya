//给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。 
//
// 示例 1: 
//
// 输入: [[1,1],[2,2],[3,3]]
//输出: 3
//解释:
//^
//|
//|        o
//|     o
//|  o  
//+------------->
//0  1  2  3  4
// 
//
// 示例 2: 
//
// 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出: 4
//解释:
//^
//|
//|  o
//|     o        o
//|        o
//|  o        o
//+------------------->
//0  1  2  3  4  5  6 
// Related Topics 哈希表 数学 
// 👍 178 👎 0


//leetcode submit region begin(Prohibit modification and deletion)



class Solution
{
public:
    int maxPoints(vector <vector<int>> &points)
    {
        if (points.size() < 3) return points.size();
        int result = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int duplicate = 0;
            int curMax = 0;
            unordered_map<string, int> oneline;
            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    duplicate += 1;
                    continue;
                }
                int diffX = points[j][0] - points[i][0];
                int diffY = points[j][1] - points[i][1];
                int temp = gcd(diffX, diffY);
                string key = to_string(diffX / temp)+"/"+to_string(diffY / temp);
                oneline[key]++;
                curMax = max(curMax, oneline[key]);
            }
            result = max(result, curMax + duplicate + 1);
        }
        return result;
    }
private:
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
