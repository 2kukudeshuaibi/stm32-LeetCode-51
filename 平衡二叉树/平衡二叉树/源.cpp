/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left1 = max(root->left) + 1;
    int right1 = max(root->right) + 1;
    if (left1 > right1)
    {
        return left1;
    }
    else
    {
        return right1;
    }
}


bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    int left1 = max(root->left);
    int right1 = max(root->right);
    return abs(left1 - right1) < 2 && isBalanced(root->left) && isBalanced(root->right);
}