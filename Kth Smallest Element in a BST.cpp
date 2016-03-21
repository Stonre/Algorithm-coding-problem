#include "tree.h"

int kthSmallest(TreeNode* root, int k)
{
    stack<TreeNode*> stk;

    while (root)
    {
        stk.push(root);
        root = root->left;
    }

    for (int i=0;i<k;i++)
    {
        TreeNode* t = stk.top();
        if (i == k-1)
            return t->val;
        stk.pop();
        if (t->right)
        {
            TreeNode* tmp = t->right;
            while (tmp)
            {
                stk.push(tmp);
                tmp = tmp->left;
            }
        }
    }
}

int main()
{
    ifstream f("in.txt");
    string s;
    vector<string> ss;
    while (!f.eof())
    {
        f>>s;
        ss.push_back(s);
    }
    TreeNode* t = buildtree(ss);
    int kthsmallest = kthSmallest(t,5);
    cout<<kthsmallest;
    return 0;
}
