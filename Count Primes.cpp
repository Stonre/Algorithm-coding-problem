#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//int countPrimes(int n) {
//        vector<bool> num(n - 1, true);
//        num[0] = false;
//        int res = 0, limit = sqrt(n);
//        for (int i = 2; i <= limit; ++i) {
//            if (num[i - 1]) {
//                for (int j = i * i; j < n; j += i) {
//                    num[j - 1] = false;
//                }
//            }
//        }
//        for (int j = 0; j < n - 1; ++j) {
//            if (num[j]) ++res;
//        }
//        return res;
//    }

int countPrimes(int n) {
        int cont=0;
        bool isP[n-1];
        for (int i=0;i<n-1;i++)
            isP[i]=false;
        isP[0]=true;
        for (int i=2;i<=sqrt(n);i++)
        {
            if (isP[i-1])
            {
                for (int j=i*i;j<n;j+=i)
                {
                    isP[j-1]=true;
                }
            }
        }
        for (int i=1;i<n;i++)
            if (!isP[i-1])
                cont++;
        return cont;
    }
    int main()
{
    int n=7;
    int cont=countPrimes(n);
    cout<<cont;
    return 0;
}
