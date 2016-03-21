#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > levelOrder(TreeNode* root)
{
    vector<vector<int> > re;
    vector<int> rec;
    queue<TreeNode*> q1;
    TreeNode* t=root;
    if (!t)
        return re;
    q1.push(t);
    while (!q1.empty())
    {
        queue<TreeNode*> q2;
        while (!q1.empty())
        {
            t=q1.front();
            rec.push_back(t->val);
            q1.pop();
            if (t->left)
                q2.push(t->left);
            if (t->right)
                q2.push(t->right);
        }
        re.push_back(rec);
        rec.clear();
        q1=q2;
    }
    return re;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    vector<vector<int> > re;
    re=levelOrder(root);
    return 0;
}
