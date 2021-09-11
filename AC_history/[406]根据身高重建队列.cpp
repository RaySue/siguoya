// 假设有打乱顺序的一群人站成一个队列。
// 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
// 编写一个算法来重建这个队列。
//
// 注意： 
// 总人数少于1100人。
//
// 示例 
//
// 
//输入:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//[[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
//[[7,0], [6,1], [7,1], [5,0], [5,2], [4,4]]

//
//
//输出:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
// 
// Related Topics 贪心算法 
// 👍 572 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    /*
    **贪心加冒泡**

    首先把people根据身高从高到低,人数从小到大进行排序

    然后把每个people和他前面的people进行比较,如果前面的people的身高高于他,那么就交换两位people

    同时,要确保每个people前面的人数是正确的
     *
     */

//    static bool cmp(vector<int> &a, vector<int> &b)
//    {
//        return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
//    }

    vector <vector<int>> reconstructQueue1(vector <vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> v1, vector<int> v2){return v1[0]!=v2[0]? v1[0] > v2[0]: v1[1] < v2[1];});

        // i = 1，是要 i - 1 存在
        for (int i = 1; i < people.size(); i++)
        {
            int j = i;
            while (j)
            {
                //  前一个身高比当前高 && 身高大于当前的 小于 当前前面人数
                if (people[j - 1][0] > people[j][0] && people[j][1] < j)
                    swap(people[j], people[j - 1]);
                else
                    break;

                j--;
            }
        }
        return people;
    }

    // 根据身高重建队列
    // 先对 people 进行排序，1.身高高的在前面 2.如果身高相等，那么k值小的在前面
    vector <vector<int>> reconstructQueue(vector <vector<int>> &people)
    {
        auto lambda = [&](vector<int> v1, vector<int> v2)->bool {
            if (v1[0] != v2[0]) return v1[0] > v2[0];
            else return v1[1] < v2[1];
        };
        sort(people.begin(), people.end(), lambda);
        vector<vector<int>> ret;
        for (int i = 0; i < people.size(); ++i)
        {
            ret.insert(ret.begin() + people[i][1], people[i]);
        }
        return ret;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
