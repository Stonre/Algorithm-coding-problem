#include<iostream>
using namespace std;

bool isPalindrome(int x) {
        if (x<0)
            return false;
        int num=1;
        while (x/num>=10)
        {
            num*=10;
        }
        int numl=1;
        while (num>=numl)
        {
            int h=x/num;
            int l=x%10;
            if (h==l)
            {
                x-=x/num*num;
                x/=10;
                num/=100;
            }
            else
            {
                return false;
            }
        }

        return true;
     }

int main()
{
    int a=10;
    bool c=isPalindrome(a);
    cout<<c;
    return 0;
}
