//给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。 
//
// 例如，给定一个 3叉树 : 
//
// 
//
// 
//
// 
//
// 返回其层序遍历: 
//
// [
//     [1],
//     [3,2,4],
//     [5,6]
//]
// 
//
// 
//
// 说明: 
//
// 
// 树的深度不会超过 1000。 
// 树的节点总数不会超过 5000。 
// Related Topics 树 广度优先搜索 
// 👍 117 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    // 典型 BFS
    // 可能对 N叉树 不太熟悉，加上总不用 BFS 了，这段程序用了10分多钟
    // 总结：

    // 1. BFS 的队列元素要与输入的元素一致
    // 2. BFS 的队列每次保存的是下一圈要处理的元素
    // 3. N叉树的遍历 for(auto child:Node->children)
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<Node*> treeQ;
        treeQ.push(root);
        vector<int> treeList;

        while(!treeQ.empty())
        {
            int sz = treeQ.size();
            for (int i = 0; i < sz; ++i)
            {
                Node* treeNode = treeQ.front();treeQ.pop();
                if (!treeNode) continue;
                treeList.push_back(treeNode->val);
                for (auto child:treeNode->children) treeQ.push(child);
            }
            ans.push_back(treeList);
            treeList.clear();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
