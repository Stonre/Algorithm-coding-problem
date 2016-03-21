#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

void cur(TreeNode* t,int& cont,int dep)
    {
        if (t->left==NULL&&t->right==NULL)
        {
            dep++;
            if (dep>cont)
                cont=dep;
            return;
        }
        dep++;
        if (t->left!=NULL)
            cur(t->left,cont,dep);
        if (t->right!=NULL)
            cur(t->right,cont,dep);
    }
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int cont=1;
        cur(root,cont,0);
        return cont;
    }

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    int a=maxDepth(root);
    cout<<a;
    return 0;
}
