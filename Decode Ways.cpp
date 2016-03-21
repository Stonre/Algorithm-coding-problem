#include "pack.h"

int stringtoint(string s)
{
    stringstream ss;
    int tmp;
    ss<<s;
    ss>>tmp;
    return tmp;
}

int numDecodings(string s)
{
    int len = s.size();
    if (len==0)
        return 0;
    int cont[len];
    if (stringtoint(s.substr(0,1))>=1)
        cont[0]=1;
    else
        cont[0]=0;
    if (len==1)
        return cont[0];
    if (cont[0]==0&&len!=1)
        return 0;
    int tmp = stringtoint(s.substr(0,2));
    if(tmp>=1&&tmp<=26)
        if (stringtoint(s.substr(1,1))!=0)
            cont[1]=2;
        else
            cont[1]=1;
    else
        if (stringtoint(s.substr(1,1))!=0)
            cont[1]=1;
        else
            return 0;
    for (int i=2;i<len;i++)
    {
        int tmp = stringtoint(s.substr(i-1,2));
        if (tmp>=1&&tmp<=26)
            if (stringtoint(s.substr(i,1))!=0&&stringtoint(s.substr(i-1,1))!=0)
                cont[i]=cont[i-1]+cont[i-2];
            else
                cont[i]=cont[i-2];
        else
            if (stringtoint(s.substr(i,1))==0)
                return 0;
            else
                cont[i]=cont[i-1];
    }
    return cont[len-1];
}

int main()
{
    string s = "301";
    int re = numDecodings(s);
    cout<<re;
    return 0;
}
