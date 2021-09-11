//给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
//
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最
//终结果不会超过 231 - 1 。 
//
// 例如: 
//
// 
//输入:
//A = [ 1, 2]
//B = [-2,-1]
//C = [-1, 2]
//D = [ 0, 2]
//
//输出:
//2
//
//解释:
//两个元组如下:
//1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
// 
// Related Topics 哈希表 二分查找 
// 👍 244 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    int binarySearch(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;

        while (left <= right)
        {
            mid = left + (right - left >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            } else if (nums[mid] < target)
            {
                left = mid + 1;
            } else
            {
                right = mid - 1;
            }
        }

        if (left >= nums.size() || nums[left] != target)
            return -1;

        int count = 0;
        for (int i = left; i < nums.size(); ++i)
        {
            if (nums[i] == target)
                count++;
        }
        return count;

    }


    int fourSumCount1(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int N = A.size(), count = 0;
        if (A.empty()) return count;
        vector<int> AB;
        AB.reserve(N * N);  // S: O(N^2)
        vector<int> CD;
        CD.reserve(N * N); // S: O(N^2)

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                AB.push_back(A[i] + B[j]);
                CD.push_back(C[i] + D[j]);
            }
        }
        sort(CD.begin(), CD.end()); // O(N^2 log N^2)

        // O(N^2 * log N^2)
        for (auto a:AB)
        {
            pair <vector<int>::iterator, vector<int>::iterator> range = equal_range(CD.begin(), CD.end(), -a);
            int temp_count = range.second - range.first;
//        int temp_count = binarySearch(CD, -a);
            if (temp_count == -1) continue;
            else
            {
                count += temp_count;
            }
        }
        return count;
    }

    // 笛卡尔积
    // 这道题目解题的点在于用 O(N^2) 先组合两个数组，然后再使用二分查找，或者hash Map
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int count = 0;
        unordered_map<int, int> mem;
        for (int a:A)
        {
            for (int b:B)
            {
                mem[a + b]++;
            }
        }
        for (int c:C)
        {
            for (int d:D)
            {
                if (mem.count(-(c+d)))
                {
                    count += mem[-(c+d)];
                }
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
