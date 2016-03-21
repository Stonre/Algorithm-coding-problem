#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
        ListNode* h=new ListNode(0);
        h->next=head;
        ListNode* tmp1=h;
        ListNode* tmp2=head;
        int k=0;

        if (head->next==NULL || head==NULL)
            return head;

        while (tmp2->next!=NULL)
        {
            int flag=0;
            k++;
            for (int i=0;i<k;i++)
            {
                if (tmp1->next->val>tmp2->next->val)
                {
                    if (i==0)
                    {
                        ListNode* tttt=tmp2->next->next;
                        tmp2->next->next=head;
                        head=tmp2->next;
                        tmp2->next=tttt;
                        flag=1;
                        break;
                    }
                    else
                    {
                        ListNode* tt=tmp2->next->next;
                        tmp2->next->next=tmp1->next;
                        tmp1->next=tmp2->next;
                        tmp2->next=tt;
                        flag=1;
                        break;
                    }
                }
                tmp1=tmp1->next;
            }
            if (flag==0)
            {
                tmp2=tmp2->next;
            }
            h->next=head;
            tmp1=h;
        }
        return head;
    }

int main()
{
    ListNode* head=new ListNode(2);
    head->next=new ListNode(4);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(5);
    head->next->next->next->next=new ListNode(1);
    head->next->next->next->next->next=new ListNode(0);
    ListNode* p=insertionSortList(head);
    while (p!=NULL)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
return 0;
}
