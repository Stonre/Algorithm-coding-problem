#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

    void cur(TreeNode* root,int sum,int tsum,bool& re)
    {
        tsum+=root->val;
        if (root->left==NULL&&root->right==NULL)
        {
            if (tsum==sum)
                re=true;
            return;
        }
        if (root->left!=NULL)
            cur(root->left,sum,tsum,re);
        if (root->right!=NULL)
            cur(root->right,sum,tsum,re);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool re=false;
        if (root==NULL)
            return re;
        cur(root,sum,0,re);
        return re;
    }
