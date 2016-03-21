#include<iostream>
#include<math.h>
using namespace std;

int titleToNumber(string s) {
        int len=s.size();
        int re=0;
        for (int i=0;i<len;i++)
        {
            re=(s[i]-'A'+1)*pow(26,len-i-1)+re;
            cout<<(s[i]-'A'+1)*pow(26,len-i-1)<<endl;
        }
        return re;
    }

int main()
{
    string a="AB";
    int re;
    re=titleToNumber(a);
    cout<<re;
    return 0;
}
