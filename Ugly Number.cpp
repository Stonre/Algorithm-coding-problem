#include<iostream>
using namespace std;

 bool isUgly(int num) {
        if (num==1)
            return true;
        if (num==0)
            return false;
        while (num%2==0)
        {
            num/=2;
        }
        while (num%3==0)
        {
            num/=3;
        }
        while (num%5==0)
        {
            num/=5;
        }
        if (num==1)
            return true;
        else
            return false;
    }

int main()
{
    int a=17;
    bool b=isUgly(a);
    cout<<b;
    return 0;
}
