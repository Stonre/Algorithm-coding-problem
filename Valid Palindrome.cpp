#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
        int len=s.size();
        for (int i=0;i<len;)
        {
            if ((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
                i++;
            else
            {
                s.erase(s.begin()+i);
                len--;
            }
        }
        if (s.size()==0)
            return true;

        int p1=0,p2=s.size()-1;
        while (p1<=p2)
        {
            if (s[p1]==s[p2] || (s[p1]-'a')==(s[p2]-'A') || (s[p1]-'A')==(s[p2]-'a'))
            {
                p1++;
                p2--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

int main()
{
    string a="Bab";
    bool b=isPalindrome(a);
    cout<<b;
    return 0;
}
