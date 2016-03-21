#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int depth(TreeNode* root,bool& isB){
        if (root->left==NULL&&root->right==NULL)
        {
            return 1;
        }
        int llen,rlen;
        if (root->left!=NULL)
            llen=depth(root->left,isB);
        else
            llen=0;
        if (root->right!=NULL)
            rlen=depth(root->right,isB);
        else
            rlen=0;
        if (abs(llen-rlen)>1)
        {
            isB=false;
            return 0;
        }
        return llen>rlen?(llen+1):(rlen+1);
    }
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
            return true;
        bool isB=true;
        depth(root,isB);
        return isB;
    }

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(5);
    bool isB;
    isB=isBalanced(root);
    cout<<isB;
    return 0;
}
