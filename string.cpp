#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int elem;
    int loca;
    Node* next;
    Node(int e,int l):elem(e),loca(l),next(NULL){}
};

int lengthOfLongestSubstring(string s)
{
    Node* ele[26];
    Node* p[26];
    Node* temp[26];
    int len=s.size();

    for (int i=0;i<26;i++)
    {
        ele[i]=new Node(i+97,0);
        p[i]=ele[i]->next;
        temp[i]=ele[i]->next;
    }

    for (int i=0;i<len;i++)
    {
        p[int(s[i])-97]=new Node(int(s[i]),i);
        p[int(s[i])-97]=p[int(s[i])-97]->next;
    }

    int dif=len;
    for (int i=0;i<26;i++)
    {
        while (temp[i]->next!=NULL)
        {
            int tmp=temp[i+1]->loca-temp[i]->loca;
            if (tmp<dif)
            {
                dif=tmp;
            }
            temp[i]=temp[i]->next;
        }
    }
    return dif;

}

int main()
{
    string s="abcabcbb";
    int p=lengthOfLongestSubstring(s);
    cout<<p;
    return 0;
}
