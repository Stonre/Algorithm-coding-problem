#include "pack.h"

void reverseWords(string &s)
{
    int len = s.size();
    vector<int> pos;
    pos.push_back(-1);

    for (int i=0;i<len;i++)
        if (s[i]==' ')
            pos.push_back(i);
    pos.push_back(len);

    for (int i=0;i<pos.size()-1;i++)
        reverse(s.begin()+pos[i]+1,s.begin()+pos[i+1]);
    reverse(s.begin(),s.end());
}

int main()
{
    string s = "len inu loppps";
    reverseWords(s);
    cout<<s;
    return 0;
}
