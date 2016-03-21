#include<iostream>
using namespace std;

struct ListNode {
      int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseList(ListNode* head) {
        if (head==NULL)
            return head;
        if (head->next==NULL)
            return head;
        ListNode* tmp=reverseList(head->next);
        ListNode* tmpt=tmp;
        while (tmpt->next!=NULL)
        {
            tmpt=tmpt->next;
        }
        tmpt->next=head;
        head->next=NULL;
        return tmp;
    }

    int main()
    {
        ListNode* head=new ListNode(1);
        head->next=new ListNode(2);
        head->next->next=new ListNode(3);
        head->next->next->next=new ListNode(4);
        ListNode* h=reverseList(head);
        cout<<h->val<<endl<<h->next->val<<endl<<h->next->next->val<<endl<<h->next->next->next->val;
        return 0;
    }
