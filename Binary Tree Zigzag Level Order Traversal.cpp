#include "tree.h"

vector<vector<int> > zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int> > re;
    vector<int> cur;
    vector<TreeNode*> q1;
    int k = 1;
    if (root==NULL)
        return re;
    q1.push_back(root);
    while (!q1.empty())
    {
        int len = q1.size();
        vector<TreeNode*> q2;
        if(k%2==0)
        {
            for (int i=len-1;i>=0;i--)
            {
                cur.push_back(q1[i]->val);
                if (q1[len-1-i]->left)
                    q2.push_back(q1[len-1-i]->left);
                if (q1[len-1-i]->right)
                    q2.push_back(q1[len-1-i]->right);
            }
        }
        else
        {
            for (int i=0;i<len;i++)
            {
                cur.push_back(q1[i]->val);
                if (q1[i]->left)
                    q2.push_back(q1[i]->left);
                if (q1[i]->right)
                    q2.push_back(q1[i]->right);
            }
        }
        q1 = q2;
        re.push_back(cur);
        k++;cout<<k<<endl;
        cur.clear();
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
    vector<vector<int> > re;
    re = zigzagLevelOrder(t);
    for (int i=0;i<re.size();i++)
    {for (int j=0;j<re[i].size();j++)
            cout<<re[i][j];
            cout<<endl;}
            return 0;
}
