#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cont1=0,cont2=0;
        ListNode* tmp1=headA;
        ListNode* tmp2=headB;
        if (headA==NULL||headB==NULL)
            return NULL;
        while (tmp1!=NULL)
        {
            cont1++;
            tmp1=tmp1->next;
        }
        while (tmp2!=NULL)
        {
            cont2++;
            tmp2=tmp2->next;
        }
        if (cont1<cont2)
        {
            int cont=cont1;
            cont1=cont2;
            cont2=cont;
            tmp1=headB;
            tmp2=headA;
        }
        else
        {
            tmp1=headA;
            tmp2=headB;
        }
        for (int i=0;i<cont1-cont2;i++)
        {
            tmp1=tmp1->next;
        }
        for (int i=0;i<cont2;i++)
        {
            if (tmp1==tmp2)
                return tmp1;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return NULL;
    }

int main()
{
    ListNode* headA=new ListNode(1);
    headA->next=new ListNode(2);
    headA->next->next=new ListNode(3);
    ListNode* headB=new ListNode(4);
    headB->next=new ListNode(5);
    headB->next->next=new ListNode(6);
    headB->next->next->next=headA->next->next;
    headA->next->next->next=new ListNode(7);cout<<9;
    headA->next->next->next->next=new ListNode(8);

    ListNode* tmp=getIntersectionNode(headA,headB);
    cout<<tmp->val;
    return 0;
}
