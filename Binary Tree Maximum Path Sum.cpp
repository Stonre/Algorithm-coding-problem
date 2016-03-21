#include"tree.h"

int ans;

int scanT(TreeNode* t)
{
    if (t==NULL)
        return 0;
    int left = scanT(t->left);
    int right = scanT(t->right);
    int val = root->val;
    if (left>0)
        val+=left;
    if (right>0)
        val+=right;
    if (val>ans)
        ans=val;
    return max(root->val,max(left+root->val,right+root->val));
}

int maxPathSum(TreeNode *root)
{
    if (root==NULL)
        return 0;
    ans = root->val;
    scanT(root);
    return ans;
}

int main()
{

}
