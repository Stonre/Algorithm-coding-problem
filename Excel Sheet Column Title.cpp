#include<iostream>
#include<math.h>
using namespace std;

string convertToTitle(int n)
{
    int level=1;
    string re;
    while(n!=0)
    {
        if (n%26==0)
        {
            re.push_back('Z');
            n=n/26-1;
        }
        else
        {
            re.push_back('A'+n%26-1);
            n=n/26;
        }
    }
    int high=re.size()-1,low=0;
    while (low<=high)
    {
        char tmp=re[low];
        re[low]=re[high];
        re[high]=tmp;
        low++;
        high--;
    }
    return re;
}
int main()
{
    string a;
    a=convertToTitle(1);
    cout<<a;
    return 0;
}
