#include "tree.h"

void flatten (TreeNode* root)
{
    if (root==NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    if (root->left!=NULL)
        flatten(root->left);
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    while (root->right!=NULL)
        root = root->right;
    root->right = tmp;
    flatten(tmp);
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
    flatten(t);
    printtree(t);
    return 0;
}
