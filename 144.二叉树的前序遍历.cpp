/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution
// {
// public:
//     // 用来存放结果的数组
//     vector<int> result;

//     // 参数和返回类型
//     void traversal(TreeNode *cur)
//     {
//         // 终止条件
//         if (cur == nullptr)
//             return;
//         // 中左右
//         result.push_back(cur->val);
//         preorderTraversal(cur->left);
//         preorderTraversal(cur->right);
//     }
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         traversal(root);
//         return result;
//     }
// };

// 用迭代法实现前序遍历
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        // 用来存放节点的栈
        stack<TreeNode *> st;
        // 存放结果的数组
        vector<int> result;
        // 将节点放入栈中
        st.push(root);
        // 栈不为空一直进行
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            // 中序
            result.push_back(node->val);
            // 如果右不为空则放入
            if (node->right)
                st.push(node->right);
            // 如果左不为空则放入
            if (node->left)
                st.push(node->left);
        }
        return result;
    }
};
// @lc code=end
