/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    // 后序遍历
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 根节点为空则返回
        if (root == nullptr)
            return 0;
        // 遇到叶子节点则返回
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        // 左
        int leftNum = sumOfLeftLeaves(root->left);
        // 如果遇到左节点
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            leftNum = root->left->val;
        // 右
        int rightNum = sumOfLeftLeaves(root->right);
        // 中
        return leftNum + rightNum;
    }
};
// @lc code=end
