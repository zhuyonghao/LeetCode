/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool traversal(TreeNode *cur, int count)
    {
        // 如果遇到叶子节点此时count为0,说明找到该路径
        if (cur->left == nullptr && cur->right == nullptr && count == 0)
            return true;
        // 如果遇到叶子节点此时count不为0,说明没有找到该路径
        if (cur->left == nullptr && cur->right == nullptr && count != 0)
            return false;
        // 左
        if (cur->left)
        {
            // 递归
            count -= cur->left->val;
            // 找到返回true
            if (traversal(cur->left, count))
                return true;
            // 回溯
            count += cur->left->val;
        }
        if (cur->right)
        {
            count -= cur->right->val;
            // 递归
            if (traversal(cur->right, count))
                return true;
            // 回溯
            count += cur->right->val;
        }
        // 没有找到
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return traversal(root, targetSum - root->val);
    }
};
// @lc code=end
