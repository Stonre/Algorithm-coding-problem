#include<iostream>
#include<cmath>
using namespace std;

    int numSquares(int n) {
        int sq[n+1];
        for (int i=0;i<n;i++)
            sq[i]=0;
        for (int i=1;i*i<=n;i++)
            sq[i*i]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j*j+i<=n;j++)
            {
                if (!sq[i+j*j]||sq[i+j*j]>sq[i]+1)
                    sq[i+j*j]=sq[i]+1;
                for (int i=0;i<n;i++)
                    cout<<sq[i]<<" ";
                cout<<endl;
            }
    return sq[n];
    }

int main()
{
    int s=numSquares(8);
    cout<<s;
    return 0;
}
