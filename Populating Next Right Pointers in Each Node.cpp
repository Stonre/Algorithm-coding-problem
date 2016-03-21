#include"tree.h"

void connect(TreeLinkNode* root)
{
    if (root==NULL)
        return;
    queue<TreeLinkNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int len = q.size();
        TreeLinkNode* t1;
        TreeLinkNode* t2;

        for (int i=0;i<len;i++)
        {
            t1 = q.front();
            q.pop();
            if (i!=len-1)
            {
                t2 = q.front();
                t1->next = t2;
            }
            if (t1->left!=NULL)
                q.push(t1->left);
            if (t1->right!=NULL)
                q.push(t1->right);
        }
        t1->next = NULL;
    }
}

