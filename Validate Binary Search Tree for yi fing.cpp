#include"tree.h"
bool valid=true;

void inorder(TreeNode* p,TreeNode* pre){
    if(p==NULL) return;
    inorder(p->left,pre);
    if(pre!=NULL){
        if (pre->val>=p->val){
        valid=false;
        return;}}
    pre=p;
    inorder(p->right,pre);
}

    bool isValidBST(TreeNode* root) {
        valid=true;
        TreeNode* pre=NULL;
        inorder(root,pre);
        return valid;
    }

int main()
{
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(1);
    bool a = isValidBST(t);
    cout<<a;
    return 0;
}
