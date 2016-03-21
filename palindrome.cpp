#include<iostream>
#include<cstring>
using namespace std;

string longestPalindrome(string s) {
    int len=s.size();
    int relen=0;
    string re="";
    if (len==1)
    return s;

    for (int i=1;i<len;i++)
    {
        if (s[i]==s[i-1])
        {
            int j=i;
            while (2*i-1-j>=0 && j<len)
            {
                if (s[j]!=s[2*i-1-j])
                    break;
                j++;
            }
            if ((j-i)*2>relen)
            {
                re.assign(s,2*i-j,(j-i)*2);
                relen=(j-i)*2;
            }
        }

            if (s[i-1]==s[i+1])
            {
                int j=i+1;
                while (j<len && 2*i-j>0)
                {
                    if (s[j]!=s[2*i-j])
                        break;
                    j++;cout<<j;
                }
                if ((j-i)*2-1>relen)
                {
                    re.assign(s,2*i-j+1,(j-i)*2-1);
                    relen=(j-i)*2-1;
                }
            }

    }
    return re;
    }

int main()
{
    string s="aaa";
    string re=longestPalindrome(s);
    cout<<re;
    return 0;
}
