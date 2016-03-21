#include<iostream>
#include<cstring>
using namespace std;

string addBinary(string a, string b) {
        int lena=a.size();
        int lenb=b.size();

        int re[max(lena,lenb)+1];
        re[0]=0;

        int i=0;
        for (i=0;i<min(lena,lenb);i++)
        {
            re[max(lena,lenb)-i]=a[lena-1-i]-'0'+b[lenb-1-i]-'0';
        }
        i--;
        while (i<lenb-1){
            i++;
            re[max(lena,lenb)-i]=b[lenb-1-i]-'0';
        }
        while (i<lena-1){
            i++;
            re[max(lena,lenb)-i]=a[lena-1-i]-'0';
        }

        for (int j=max(lena,lenb);j>0;j--)
        {
            if (re[j]>1)
            {
                re[j-1]+=re[j]/2;
                re[j]=re[j]%2;
            }
        }

        string res;
        for (int k=max(lena,lenb);k>=0;k--)
        {
            res.push_back('0'+re[max(lena,lenb)-k]);
        }
        if (re[0]==0)
        {
            res=res.substr(1);
        }
        return res;
    }


int main()
{
    string a="0",b="1";
    string c=addBinary(a,b);
    cout<<c;
    return 0;
}
