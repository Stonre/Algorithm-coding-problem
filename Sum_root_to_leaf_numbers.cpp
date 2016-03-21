#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void sum_cur(vector<vector<int> >& re,vector<int>& cur,TreeNode* t)
{
    cur.push_back(t->val);
    if (t->left == NULL && t->right == NULL)
    {
        re.push_back(cur);
        return;
    }
    if (t->left != NULL)
    {
        sum_cur(re,cur,t->left);
        cur.pop_back();
    }
    if (t->right != NULL)
    {
        sum_cur(re,cur,t->right);
        cur.pop_back();
    }
    return;
}

int sumNumbers(TreeNode* root)
{
    vector<vector<int> > re;
    vector<int> cur;
    if (root == NULL)
        return 0;
    sum_cur(re,cur,root);

    int sum = 0;
    for (int i = 0; i < re.size(); i++)
    {
        int tmpsum = re[i][0];
        for (int j = 1; j < re[i].size(); j++)
            {tmpsum = tmpsum * 10 + re[i][j];}
        sum += tmpsum;
    }
    return sum;
}

int main()
{
    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(9);
    t->right = new TreeNode(0);
    t->right->left = new TreeNode(2);
    t->left->right = new TreeNode(1);

    int sum = sumNumbers(t);
    cout<<sum;
    return 0;
}
