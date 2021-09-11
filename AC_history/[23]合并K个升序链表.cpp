//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
// Related Topics 堆 链表 分治算法 
// 👍 1049 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class BestSolution
{
    //------------------ Best Solution -----------------------

// 分治合并K个有序链表
// 合并两个有序链表
    ListNode *merge(ListNode *p1, ListNode *p2)
    {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val)
        {
            p1->next = merge(p1->next, p2);
            return p1;
        } else
        {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

    // 对 lists 中的列表进行两两合并，利用快速排序的思想
    // 分治思想：
    // 对 lists 进行不断的拆分，直到拆分为单个 链表的时候再去 merge
    // 从而得到最终的结果
    ListNode *merge(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode *l1 = merge(lists, start, mid);
        ListNode *l2 = merge(lists, mid + 1, end);
        return merge(l1, l2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};


class Solution
{
public:

    // 二刷 2020.12.22 依然是土办法
    ListNode *mergeKLists1(vector<ListNode *> &lists)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *ptr = dummyHead;
        for (;;)
        {
            int index = -1;
            int tmp = INT_MAX;
            for (int i = 0; i < lists.size(); ++i)
            {
                if (!lists[i]) continue;
                if (lists[i]->val < tmp)
                {
                    tmp = lists[i]->val;
                    index = i;
                }
            }
            if (index == -1) break;
            ptr->next = lists[index];
            lists[index] = lists[index]->next;
            ptr = ptr->next;
        }
        return dummyHead->next;
    }


    // 思路：
    // 利用快速排序的思想，先根据mid将lists分为两个部分，
    // 递归对每个子 lists 合并
    // 对两个有序链表合并为一个有序链表
    // 递归的终止条件 if(start == end) return lists[start];
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

    //
    ListNode *merge(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end) return lists[start];
        int mid = start + (end - start >> 1);
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *merge(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }


//    int partition(vector<int> &nums, int start, int end)
//    {
//        int begin = start;
//        int pivot = nums[begin];
//        while(start != end)
//        {
//            while(start < end && nums[end] >= pivot) end--;
//            while(start < end && nums[start] <= pivot) start++;
//            if (start < end) swap(nums[start], nums[end]);
//        }
//        swap(nums[begin], nums[start]);
//        return start;
//    }
//
//    // 基于递归的
//    void quickSort(vector<int> &nums, int start, int end)
//    {
//        if (start >= end) return;
//        int pi = partition(vector<int> &nums, start, end);
//        quickSort(nums, start, pi - 1);
//        quickSort(nums, pi + 1, end);
//    }
//
//    // 基于迭代的
//    void quickSort(vector<int> &nums, int start, int end)
//    {
//        if (start >= end) return;
//        stack<vector<int>> sta;
//        if (start < end) sta.push({start, end});
//        while(!sta.empty())
//        {
//            vector<int> interval = sta.top();sta.pop();
//            int i = interval[0], j = interval[1];
//            int pi = partition(nums, i, j);
//            if (i < pi - 1) sta.push({i, pi - 1});
//            if (pi + 1 < j) sta.push({pi + 1, j});
//        }
//    }

};
//leetcode submit region end(Prohibit modification and deletion)
