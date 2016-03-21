#include "tree.h"

string serialize(TreeNode* root)
{
    queue<TreeNode*> q;
    stringstream ss;
    q.push(root);
    string s;

    if (root==NULL)
        return s;

    while (!q.empty())
    {
        TreeNode* tmpnode = q.front();
        string tmpstring;
        if (tmpnode != NULL)
        {
            tmpstring = inttostring(tmpnode->val);
            s = s + tmpstring + " ";
        }
        else
        {
            s = s + "# ";
        }
        q.pop();
        if (tmpnode!=NULL)
        {
            q.push(tmpnode->left);
            q.push(tmpnode->right);
        }
    }
    s.erase(s.end()-1);
    while (s[s.size()-1]=='#')
    {
        s.erase(s.end()-1);
        s.erase(s.end()-1);
    }
    return s;
}

TreeNode* deserialize(string data)
{
    if (data.size()==0)
        return NULL;
    queue<TreeNode*> q;
    istringstream ss(data);
    vector<string> sv;

    int tmp;
    do
    {
        string s;
        ss>>s;
        sv.push_back(s);
    } while(ss);
    TreeNode* root = new TreeNode(stringtoint(sv[0]));
    q.push(root);
    int k=0;
    while (k<sv.size()-2)
    {
        TreeNode* tm = q.front();
        q.pop();
        if (sv[++k]!="#")
        {
            tmp = stringtoint(sv[k]);
            tm->left = new TreeNode(tmp);
            q.push(tm->left);
        }
        if (k+1<sv.size()-1)
            if (sv[++k]!="#")
            {
                tmp = stringtoint(sv[k]);
                tm->right = new TreeNode(tmp);
                q.push(tm->right);
            }

    }
    return root;
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
    string sss = serialize(t);
    //cout<<sss<<endl;
    TreeNode* tt = deserialize(sss);
    //printtree(tt);
    return 0;
}
