#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp;
        ListNode* re=head;
        if (head==NULL)
            return head;
        while (head->next!=NULL)
        {
            if (head->val==head->next->val)
            {
                tmp=head->next;
                head->next=head->next->next;
                delete tmp;
            }
            else
            {
                head=head->next;
            }
        }
        return re;
    }

int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(1);
    ListNode* re=deleteDuplicates(head);
    cout<<99;
    while (re!=NULL)
    {
        cout<<re->val<<endl;
        re=re->next;
    }
    return 0;
}
