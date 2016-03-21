#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;



static bool cmp(const string a, const string b)
    {
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int> &num) {
        int len=num.size();
        vector<string> vec;

        if (len==0)
            return NULL;

        int zeroc=0;
        for (int i=0;i<len;i++)
        {
            if (num[i]==0)
                zeroc++;
            char str[0];
            sprintf(str,"%d",num[i]);
            vec.push_back(str);
        }
        if (len==1)
            return vec[0];
        sort(vec.begin(),vec.end(),cmp);
        string result;
        for (int i=0;i<len;i++)
        {
            result+=vec[i];
        }
        return result;
    }

int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);

    sort(a);

    return 0;
}
