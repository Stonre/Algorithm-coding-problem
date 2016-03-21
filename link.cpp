#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;

        if (p1==NULL && p2==NULL)
        {
            return NULL;
        }
        else if (p1==NULL && p2!=NULL)
        {
            return p2;
        }
        else if (p1!=NULL && p2==NULL)
        {
            return p1;
        }

        if (p2->val<p1->val)
        {
            ListNode* tt=p2->next;
            p2->next=p1;
            p1=p2;
            p2=tt;
        }
        l1=p1;

        while (p2!=NULL)
        {
            if (p1->next==NULL)
            {
                p1->next=p2;
                return l1;
            }
            if (p1->val<=p2->val && p1->next->val>p2->val)
            {
                ListNode* tmp=p2->next;
                p2->next=p1->next;
                p1->next=p2;
                p2=tmp;
            }
            p1=p1->next;
        }
        return l1;
    }

    int main()
    {
        ListNode* l1=new ListNode(5);
        ListNode* l2=new ListNode(1);
        l2->next=new ListNode(2);
        l2->next->next=new ListNode(4);
        ListNode* l=mergeTwoLists(l1,l2);
        while (l!=NULL){
        cout<<l->val<<endl;
        l=l->next;}
        return 0;
    }
