#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void cur(vector<string>& re,string& cur_re,TreeNode* t)
{
    stringstream ss;
    ss<<t->val;
    string s;
    ss>>s;
    int len=s.size();
    if (t->left==NULL&&t->right==NULL)
    {
        cur_re=cur_re+s;
        re.push_back(cur_re);
        cur_re.erase(cur_re.end()-len,cur_re.end());
        return;
    }
    cur_re=cur_re+s+"->";
    if (t->left!=NULL)
    {
        cur(re,cur_re,t->left);
    }
    if (t->right!=NULL)
    {
        cur(re,cur_re,t->right);
    }
    cur_re.erase(cur_re.end()-len-2,cur_re.end());
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> re;
    string cur_re;
    if (root==NULL)
        return re;
    cur(re,cur_re,root);
    return re;
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
//    root->right=new TreeNode(3);
    root->left->left=new TreeNode(5);
    vector<string> re=binaryTreePaths(root);
    for (int i=0;i<re.size();i++)
    {
        cout<<re[i]<<endl;
    }
    return 0;
}
