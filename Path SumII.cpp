#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void cur(vector<vector<int> >& re,vector<int>& cur_re,TreeNode* t,int sum,int tsum)
    {
        if (t->left==NULL&&t->right==NULL)
        {
            if (tsum==sum)
            {
                re.push_back(cur_re);
                return;
            }
            else
                return;
        }
        if (t->left!=NULL)
        {
            cur_re.push_back(t->left->val);
            cur(re,cur_re,t->left,sum,tsum+t->left->val);
            cur_re.pop_back();
        }
        if (t->right!=NULL)
        {
            cur_re.push_back(t->right->val);
            cur(re,cur_re,t->right,sum,tsum+t->right->val);
            cur_re.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > re;
        vector<int> cur_re;
        if (root==NULL)
            return re;
        cur_re.push_back(root->val);
        cur(re,cur_re,root,sum,root->val);
        return re;
    }

int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->right->left=new TreeNode(5);
    root->right->right->right=new TreeNode(1);

    vector<vector<int> > re;
    re=pathSum(root,22);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
