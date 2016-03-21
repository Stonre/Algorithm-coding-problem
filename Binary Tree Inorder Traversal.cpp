#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void cur(vector<int>& re,TreeNode* t)
    {
        if (t->left!=NULL)
            cur(re,t->left);
        re.push_back(t->val);
        if (t->right!=NULL)
        {
            cur(re,t->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        if (root==NULL)
            return re;
        cur(re,root);
        return re;
    }

int main()
{
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int> re;
    re=inorderTraversal(root);
    for (int i=0;i<re.size();i++)
    {
        cout<<re[i]<<" ";
    }
    return 0;
}
