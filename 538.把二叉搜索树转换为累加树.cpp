/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    // 使用双指针进行运算
    int pre = 0;

    void traversal(TreeNode *cur)
    {
        // 当遇到空节点返回
        if (cur == nullptr)
            return;

        // 右中左
        // 先向右遍历找到最大值
        traversal(cur->right);

        // 中：进行累加
        cur->val += pre;
        // 更新pre
        pre = cur->val;
        // 向左遍历
        traversal(cur->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        traversal(root);
        return root;
    }
};
// @lc code=end
