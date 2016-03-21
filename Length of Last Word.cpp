#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string s) {
        int len=s.size();
        if (len==0)
            return 0;
        int cont=0;
        for (int i=len-1;i>=0;i--)
        {
            if (s[i]!=' ')
                cont++;
            else
                break;

        }
        return cont;
    }

int main()
{
    string s="a";
    int len=lengthOfLastWord(s);
    cout<<len;
    return 0;
}
