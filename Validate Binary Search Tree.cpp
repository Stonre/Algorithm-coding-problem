#include"tree.h"
#include"limits.h"
int findmax(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int maxvalue = root->val;
    while(!q.empty())
    {
        TreeNode* tmp = q.front();
        if (tmp->val>maxvalue) maxvalue = tmp->val;
        if (tmp->left!=NULL) q.push(tmp->left);
        if (tmp->right!=NULL) q.push(tmp->right);
        q.pop();
    }
    return maxvalue;
}

int findmin(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int minvalue = root->val;
    while(!q.empty())
    {
        TreeNode* tmp = q.front();
        if (tmp->val<minvalue) minvalue = tmp->val;
        if (tmp->left!=NULL) q.push(tmp->left);
        if (tmp->right!=NULL) q.push(tmp->right);
        q.pop();
    }
    return minvalue;
}

/*bool isValidBST(TreeNode* root)
{
    if (root==NULL) return true;
    int leftmax,rightmin;
    if (root->left!=NULL)
    {
        leftmax = findmax(root->left);
        if (leftmax>=root->val)
            return false;
    }
    if (root->right!=NULL)
    {
        rightmin = findmin(root->right);
        if (rightmin<=root->val)
            return false;
    }
    if (!isValidBST(root->left))
        return false;
    if (!isValidBST(root->right))
        return false;
    return true;
}*/
bool check(TreeNode *node, int leftVal, int rightVal)
     {
         if (node == NULL)
             return true;

         return leftVal < node->val && node->val < rightVal && check(node->left, leftVal, node->val) &&
             check(node->right, node->val, rightVal);
     }

     bool isValidBST(TreeNode *root) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         return check(root, INT_MIN, INT_MAX);
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
    bool out = isValidBST(t);
    cout<<out<<endl;
    return 0;
}
