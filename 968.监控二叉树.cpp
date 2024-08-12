/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int result = 0; // 摄像头个数

    // 因为需要根据叶子节点来确定摄像头个数，从下放上遍历用后序遍历
    int traversal(TreeNode *cur)
    {
        /*三种状态
        0无覆盖
        1有摄像头
        2有覆盖
         */

        // 当遇到空节点向上返回2(空节点有覆盖)
        if (cur == nullptr)
            return 2;

        // 左
        int left = traversal(cur->left);
        // 右
        int right = traversal(cur->right);
        // 中

        // 情况一左右节点有覆盖那么父节点无覆盖
        if (left == 2 && right == 2)
            return 0;

        // 情况二左右节点至少有一个无覆盖那么父节点需要增加一个摄像头
        if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }

        // 情况三左右节点至少有一个是摄像头那么父节点被覆盖
        if (left == 1 || right == 1)
            return 2;

        // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        // 情况四根节点无覆盖那么增加摄像头
        if (traversal(root) == 0)
            result++;
        return result;
    }
};
// @lc code=end
