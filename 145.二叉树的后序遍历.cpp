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
class Solution
{
public:
    vector<int> result;

    // 参数和返回类型
    void traversal(TreeNode *cur)
    {
        // 终止条件
        if (cur == nullptr)
            return;
        // 左右中
        traversal(cur->left);
        traversal(cur->right);
        result.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        traversal(root);
        return result;
    }
};
// @lc code=end
