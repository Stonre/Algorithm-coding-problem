#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h=new ListNode(0);
        h->next=head;
        ListNode* front=head;
        ListNode* back=h;

        for (int i=0;i<n-1;i++)
        {
            front=front->next;
        }
        while (front->next!=NULL)
        {
            front=front->next;
            back=back->next;
        }

        if (back->next->next==NULL)
        {
            if (head==back->next)
                head=head->next;
            back->next=NULL;
            return head;
        }
        if (back->next==head)
        {
            head=head->next;
            return head;
        }
        ListNode* tmp=back->next;
        back->next=back->next->next;
        delete tmp;
        return head;
    }

int main()
{
    ListNode* head=new ListNode(1);

    ListNode* h=removeNthFromEnd(head,1);
    if(h==NULL)
        cout<<99;
    return 0;
}
