#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
        int len=haystack.size();
        int lenn=needle.size();
        int pointh=0,pointn=0;

        if(lenn==0)
            return 0;
        for (int i=0;i<len;i++)
        {
            if (i+lenn-1<len)
            {
                pointh=i;
                if (haystack[pointh]==needle[pointn])
                {
                    int flag=0;
                    for (int j=1;j<lenn;j++)
                    {
                        if (haystack[++pointh]==needle[j])
                            continue;
                        else
                        {
                            flag=1;
                            break;
                        }
                    }
                    if (flag==0)
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }

int main()
{
    string a="";
    string b="";
    int c=strStr(a,b);
    cout<<c;
    return 0;
}
