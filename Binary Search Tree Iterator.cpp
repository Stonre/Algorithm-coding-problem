#include "tree.h"

class BSTIterator
{
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

    bool hasNext()
    {
        return !stk.empty();
    }

    int next()
    {
        TreeNode* tmp = stk.top();
        int res = tmp->val;
        stk.pop();
        tmp = tmp->right;
        while(tmp)
        {
            stk.push(tmp);
            tmp = tmp->left;
        }
        return res;
    }
};
