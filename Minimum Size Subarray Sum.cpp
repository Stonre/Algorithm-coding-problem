#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
    int len=nums.size();
    int p1=0,p2=1;
    int re;
    if(len==0)
        return 0;
    if (nums[1]>=s)
        return 1;

    int sum=nums[p1]+nums[p2];
    if (sum>=s)
        re=2;
    else
        re=len;
    int cont=2;
    while (p2<=len-1)
    {
        if (sum<s)
        {
            if (cont==len)
                {return 0;}
            p2++;
            cont++;
            sum+=nums[p2];
            continue;
        }
        else
        {
            int tmps=sum-nums[p1];
            if (tmps>=s)
            {
                sum-=nums[p1];
                p1++;
                cont--;
                if (cont<=re)
                    re=cont;
            }
            else
            {
                p1++;
                p2++;
                if(p2<=len-1)
                    sum=sum-nums[p1-1]+nums[p2];
            }
        }
    }
    return re;
}

int main()
{
    vector<int> n;
//    n.push_back(2);
//    n.push_back(3);
//    n.push_back(1);
    n.push_back(1);
    n.push_back(1);
//    n.push_back(3);
    int a=minSubArrayLen(3,n);
    cout<<a;
    return 0;
}
