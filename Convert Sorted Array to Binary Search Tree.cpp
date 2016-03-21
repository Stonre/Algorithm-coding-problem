#include"tree.h"

TreeNode* btree(vector<int>& nums,int high,int low)
{
    if (high < low)
        return NULL;
    int mid = (high+low)/2;
    TreeNode* re = new TreeNode(nums[mid]);

    re->left = btree(nums,mid-1,low);
    re->right = btree(nums,high,mid+1);
    return re;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int len = nums.size();
    int high = len - 1, low = 0;

    if (len == 0)
        return NULL;
    if (len == 1)
        return new TreeNode(nums[0]);

    TreeNode* root = btree(nums,high,low);
    return root;
}

int main()
{
    vector<int> nums;
    for (int i=0;i<8;i++)
        nums.push_back(i);
    TreeNode* root = sortedArrayToBST(nums);
    printtree(root);
    return 0;
}
