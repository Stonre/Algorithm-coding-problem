#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;

        if (head==NULL)
            return NULL;

        int step=0;
        while (fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow)
                break;
        }
        if (fast->next==NULL)
            return NULL;
        while (true)
        {
            slow=slow->next;
            head=head->next;
            if (slow==head)
                return slow;
        }
    }

int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    detectCycle(head);
    return 0;
}
