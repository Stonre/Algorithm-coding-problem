#include<iostream>
#include<cstring>
using namespace std;

//string multiply(string num1, string num2) {
//        int len1=num1.size();
//        int len2=num2.size();
//
//        int len=len1+len2;
//        int s[len];
//
//        for (int i=0;i<len;i++)
//            s[i]=0;
//        for (int m=0;m<len1;m++)
//            for (int n=0;n<len2;n++)
//            {
//                int tmp=(num1[len1-1-m]-'0')*(num2[len2-1-n]-'0');
//                if (tmp>=10)
//                {
//                    int k=m+n+1;
//                    int tm=tmp-tmp/10*10;
//                    int tm2=tmp/10;
//                    if (s[m+n]+tm>=10)
//                    {
//                        s[m+n]=s[m+n]+tm-10;
//                        tm2++;
//                    }
//                    else
//                    {
//                        s[m+n]+=tm;
//                    }
//                    if (s[m+n+1]+tm2>=10)
//                    {
//
//                        s[m+n+1]=s[m+n+1]+tm2-10;
//                        while (s[k+1]==9 && k+1<len)
//                        {
//                            s[k+1]=0;
//                            k++;
//                        }
//                        s[k+1]++;
//                    }
//                    else
//                    {
//                        s[m+n+1]+=tm2;
//                    }
//                }
//                else
//                {
//                    if (s[m+n]+tmp>=10)
//                    {
//                        int k=m+n;
//                        s[m+n]=s[m+n]+tmp-10;
//                        while (s[k+1]==9 && k+1<len)
//                        {
//                            s[k+1]=0;
//                            k++;
//                        }
//                        s[k+1]++;
//                    }
//                    else
//                    {
//                        s[m+n]+=tmp;
//                    }
//                }
//            }
//        int relen;
//        if (s[len-1]==0)
//        {
//            relen=len-1;
//        }
//        else
//        {
//            relen=len;
//        }
//        string re;
//        for (int i=0;i<relen;i++)
//            re.push_back('0'+s[relen-1-i]);
//        return re;
//    }
string addTwoString(string num1, string num2)
    {
        int len1 = num1.size()-1;
        int len2 = num2.size()-1;
        bool carry = false;
        string res = "";
        while(len1 >=0 && len2 >=0)
        {
            int a = num1[len1]-'0';
            int b = num2[len2]-'0';
            int c = a+b;
            if(carry)
            {
                c+=1;
                carry=false;
            }
            if(c>9)
            {
                carry=true;
                c -= 10;
            }
            char tmp = '0'+c;
            res = tmp + res;
            len1--;
            len2--;
        }
        string pre="";
        if(len1>=0)
            pre=num1.substr(0,len1+1);
        else if(len2>=0)
            pre=num2.substr(0,len2+1);
        if(carry){
            int sz=pre.size()-1;
            while(sz>=0 && pre[sz]=='9')
            {
                pre[sz]='0';
                sz--;
            }
            if(sz<0)
                pre='1'+pre;
            else
                pre[sz]+=1;
        }
        res = pre+res;
        return res;
    }
    string multiplyOneBit(string num1, int num2)
    {
        int len = num1.size();
        int* res = new int[len+1];
        memset(res,0,sizeof(int)*(len+1));

        for(int i=len;i>0;i--)
        {
            res[i] += (num1[i-1]-'0')*num2;
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }
        string ss="";
        for(int i=0; i<=len; i++)
            ss += char('0' + res[i]);
        return ss;
    }
    string multiply(string num1, string num2) {
        // Note: The Solution object is instantiated only once.
        if(num1=="0" || num2=="0") return "0";
        int l1 = num1.length(), l2 = num2.length();
        string res="";
        for(int i =0; i< l2;i++)
        {
            res+='0';
            string tmp = multiplyOneBit(num1,num2[i]-'0');
            res = addTwoString(res,tmp);
        }
        res = res[0]=='0'? res.substr(1):res;
        return res;
    }

int main()
{

    string s1="7950730684116360645035469888615500796";
    string s2="841979251126152713721537069775651940998000937338602066982";
    string s=multiply(s1,s2);
    cout<<"a"+'b';
    return 0;
}
