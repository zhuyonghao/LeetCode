/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        // 如果左边界大于右边界终止
        if (left > right)
            return nullptr;
        // 取中间位置
        int mid = (left + right) / 2;
        // 构造root节点
        TreeNode *root = new TreeNode(nums[mid]);
        // 构造左子树
        root->left = traversal(nums, left, mid - 1);
        // 构造右子树
        root->right = traversal(nums, mid + 1, right);
        // 返回根节点
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
