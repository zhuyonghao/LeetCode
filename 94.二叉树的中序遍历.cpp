/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
//     // 参数和返回类型
//     void traversal(TreeNode *cur, vector<int> &vec)
//     {
//         // 终止条件
//         if (cur == nullptr)
//             return;
//         // 左中右
//         traversal(cur->left, vec);
//         vec.push_back(cur->val);
//         traversal(cur->right, vec);
//     }

//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         // 用来存放结果的数组
//         vector<int> result;
//         traversal(root, result);
//         return result;
//     }
// };

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 用来存放节点的栈
        stack<TreeNode *> st;
        // 用来存放结果的数组
        vector<int> result;
        // 用来访问节点的指针
        TreeNode *cur = root;
        // 当指针不为空或栈不为空时
        while (cur != nullptr || !st.empty())
        {
            // cur不为空时，添加元素，并继续向左访问
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            // cur为空时弹出元素，并向右访问
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end
