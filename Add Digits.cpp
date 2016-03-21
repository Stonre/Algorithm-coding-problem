#include<iostream>
using namespace std;

int addDigits(int num) {
        while (num/10!=0)
        {
            int sum=0;
            int tmp=num;
            while (tmp!=0)
            {
                sum+=tmp%10;
                tmp/=10;
            }
            num=sum;
        }
        return num;
    }

    int main()
    {
        int a=347;
        int c=addDigits(a);
        cout<<c;
        return 0;
    }
