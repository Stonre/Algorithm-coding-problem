#include<iostream>
using namespace std;

int main()
{
    bool re;
    int n=9;
    re=!(n&(n-1));
    cout<<re;
    return 0;
}
