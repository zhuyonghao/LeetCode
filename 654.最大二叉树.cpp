/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *node = new TreeNode(0);

        node->val = nums[0];
        // 终止条件
        if (nums.size() == 1)
            return node;

        // 找到最大值
        int maxValue = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= maxValue)
            {
                // 更新
                index = i;
                maxValue = nums[i];
            }
        }

        node->val = maxValue;

        // 分割数组
        // 左
        if (index > 0)
        {
            // [0, index)
            vector<int> leftNums(nums.begin(), nums.begin() + index);
            node->left = constructMaximumBinaryTree(leftNums);
        }
        // 右
        if (index < nums.size() - 1)
        {
            // [index + 1, end)
            vector<int> rightNums(nums.begin() + index + 1, nums.end());
            node->right = constructMaximumBinaryTree(rightNums);
        }
        return node;
    }
};
// @lc code=end
