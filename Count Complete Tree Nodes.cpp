#include "tree.h"
#include<math.h>

int getleft(TreeNode* l)
{
    int cont = 0;
    while (l!=NULL)
    {
        l=l->left;
        cont++;
    }
    return cont;
}

int getright(TreeNode* r)
{
    int cont = 0;
    while (r!=NULL)
    {
        r=r->right;
        cont++;
    }
    return cont;
}

int countNodes(TreeNode* root)
{
    if (root==NULL)
        return 0;
    int contleft = getleft(root);
    int contright = getright(root);
    if (contleft == contright)
        return pow(2,contleft)-1;
    else
        return countNodes(root->left) + countNodes(root->right) + 1;
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
    int cont = countNodes(t);
    cout<<cont<<endl;
    return 0;
}

