/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
//     // 通过双指针比较前后大小
//     TreeNode *pre = nullptr;
//     bool isValidBST(TreeNode *root)
//     {
//         // 到达结尾返回true
//         if (root == nullptr)
//             return true;

//         // 向左遍历
//         bool left = isValidBST(root->left);

//         // 两个条件的逆命题pre == nullptr导致返回false
//         // 判断当前节点是否大于前一个节点
//         if (pre != nullptr && pre->val >= root->val)
//             return false;
//         else
//             // 更新
//             pre = root;

//         // 向右遍历
//         bool right = isValidBST(root->right);

//         return left && right;
//     }
// };

class Solution
{
public:
    vector<int> nums;

    void traversal(TreeNode *root)
    {
        // 终止条件
        if (root == nullptr)
            return;

        // 左
        traversal(root->left);
        // 中：处理
        nums.push_back(root->val);
        // 右
        traversal(root->right);
    }

    // 中序遍历将其放入数组中，判断是否升序
    bool isValidBST(TreeNode *root)
    {
        traversal(root);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
