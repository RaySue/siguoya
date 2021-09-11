//
// 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。
// 8421
// 0000 000000
//
//
// 每个 LED 代表一个 0 或 1，最低位在右侧。
//
// 
//
// 例如，上面的二进制手表读取 “3:25”。 
//
// 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。 
//
// 
//
// 示例： 
//
// 输入: n = 1
// 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//
// 
//
// 提示： 
//
// 
// 输出的顺序没有要求。 
// 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。 
// 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。 
// 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。 
// 
// Related Topics 位运算 回溯算法 
// 👍 181 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


ostream &operator<<(ostream &out, const vector<int> &v)
{
    for (auto a:v)
    {
        cout << a << " ";
    }
    cout << " ";
    return out;
}

class Solution
{
public:

    // time out 的回溯方法
    unordered_set<string> ans_set;
    vector <string> ans;

    string binaryToString(vector<int> bit)
    {
        string hour = "";
        int tmp = 0;
        for (int i = 3; i >= 0 ; --i)
        {
            if (bit[i] == 1)
            {
                tmp += pow(2, (3 - i));
            }
        }
        if (tmp > 11) return "";
        hour = to_string(tmp);

        string minute = "";
        tmp = 0;
        for(int i = 9; i >= 4; --i)
        {
            if (bit[i] == 1)
            {
                tmp += pow(2, (9 - i));
            }
        }
        if (tmp > 59) return "";
        if (tmp < 10)
        {
            minute = "0" + to_string(tmp);
        } else {
            minute = to_string(tmp);
        }

        return hour + ":" + minute;
    }

    void dfs(int n, int depth, vector<bool> isVis, vector<int> path)
    {
        if (depth == n)
        {
            string res = binaryToString(path);
            if (res.empty()) return;
            ans_set.insert(res);
            return;
        }
        for (int i = 0; i < 10; ++i)
        {
            if (isVis[i]) continue;
            path[i] = 1;
            isVis[i] = true;
            dfs(n, depth + 1, isVis, path);
            isVis[i] = false;
            path[i] = 0;
        }
    }

    vector <string> readBinaryWatch1(int num)
    {
        vector<bool> isVis(10, false);
        vector<int> path(10, 0);
        dfs(num, 0, isVis, path);
        ans.assign(ans_set.begin(), ans_set.end());
        return ans;
    }

    // -----------------------------------------
    // 高手的解法，给跪了
    int countOne(int n)
    {
        int count = 0;
        while(n != 0)
        {
            n = n & (n - 1);
            count ++;
        }
        return count;
    }

    vector <string> readBinaryWatch(int num)
    {
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 60; ++j)
            {
                // 从数字转为二进制的1的个数，然后看看是否匹配给定的num
                if (countOne(i) + countOne(j) == num)
                {
                    // 插入复合规范的值
                    ans.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
                }
            }
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
