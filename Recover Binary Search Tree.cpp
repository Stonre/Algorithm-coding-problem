#include"tree.h"

    TreeNode* mistake1;
    TreeNode* mistake2;
    TreeNode* pre;
    TreeNode* post;

void cur(TreeNode* t)
{
    if (t==NULL)
        return;
    if (t->left)
        cur(t->left);
    if (pre->val>t->val)
        if (mistake1==NULL)
        {
            mistake1=pre;
            post = t;
        }
        else
            mistake2=t;
    pre=t;
    if (t->right)
        cur(t->right);

}

void recoverTree(TreeNode* root)
{
    if (root==NULL)
        return;
    TreeNode* t = root;
    while (t->left)
        t=t->left;
    pre=t;
    cur(root);
    int tmp=mistake1->val;
    if (mistake2)
    {
        mistake1->val=mistake2->val;
        mistake2->val=tmp;
    }
    else
    {
        mistake1->val=post->val;
        post->val=tmp;
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
    recoverTree(t);
    printtree(t);
    return 0;
}
