#include"tree.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root==NULL)
        return NULL;
    if (root==p||root==q)
        return root;
    TreeNode* l = lowestCommonAncestor(root->left,p,q);
    TreeNode* r = lowestCommonAncestor(root->right,p,q);
    if (l && r)
        return root;
    return l?l:R
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
}
