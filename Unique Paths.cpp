#include<iostream>
using namespace std;

int uniquePaths(int m, int n) {
        double C=1;
        for (int i=0;i<m-1;i++)
            {C*=m+n-2-i;C/=(i+1);}
        int b;
        if (C>int(C))
            b=int(C)+1;
        else
            b=int(C);
        return b;
    }

int main()
{
    int re=uniquePaths(56,5);
    cout<<re;
    return 0;
}
