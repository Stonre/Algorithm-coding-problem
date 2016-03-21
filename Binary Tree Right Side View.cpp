#include"tree.h"
#include<math.h>
#include<algorithm>

vector<int> rightSideView(TreeNode* root)
{
    vector<int> re;
    queue<TreeNode*> q;
    if (root==NULL)
        return re;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        TreeNode* t;
        for (int i=0;i<len;i++)
        {
            t = q.front();
            q.pop();
            if (t->left!=NULL)
                q.push(t->left);
            if (t->right!=NULL)
                q.push(t->right);
        }
        re.push_back(t->val);
    }
    return re;
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
    vector<int> re = rightSideView(t);
    for (int i=0;i<re.size();i++)
    {
        cout<<re[i]<<endl;
    }
    return 0;
}
