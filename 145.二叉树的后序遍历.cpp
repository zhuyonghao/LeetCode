/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
//     vector<int> result;

//     // 参数和返回类型
//     void traversal(TreeNode *cur)
//     {
//         // 终止条件
//         if (cur == nullptr)
//             return;
//         // 左右中
//         traversal(cur->left);
//         traversal(cur->right);
//         result.push_back(cur->val);
//     }

//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         traversal(root);
//         return result;
//     }
// };

// 用迭代法实现后序遍历
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // 如果为空则返回空数组
        if (root == nullptr)
            return {};

        // 用来存放节点的栈
        stack<TreeNode *> st;
        // 用来存放结果的数组
        vector<int> result;
        // 将节点放入栈中
        st.push(root);
        // 栈不为空时
        while (!st.empty())
        {
            // 取出栈顶元素
            TreeNode *node = st.top();
            // 将栈顶元素弹出
            st.pop();
            // 中序
            result.push_back(node->val);
            // 如果左节点不为空放入
            if (node->left)
                st.push(node->left);
            // 如果右节点不为空放入
            if (node->right)
                st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// @lc code=end
