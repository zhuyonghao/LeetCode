/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 如果遇到叶子节点则新建一个节点返回给上一层
        if (root == nullptr)
            return new TreeNode(val);
        // 左 如果当前值较大向左寻找
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        // 右 如果当前值较小向右寻找
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        // 返回根节点
        return root;
    }
};
// @lc code=end
