#include<iostream>
#include<map>
#include<math.h>
using namespace std;

int caqsum(int num){
        int sum=0;
        while (num!=0){
            sum+=pow(num%10,2);
            num/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum=caqsum(n);
        map<int,int> nummap;
        int k=1;
        while (sum!=1)
        {
            sum=caqsum(sum);
            if (nummap.count(sum))
            {cout<<sum<<endl;
                return false;
            }
            nummap.insert(pair<int,int>(sum,k));
            k++;
        }
        return true;
    }

    int main()
    {
        int a=7;
        bool b=isHappy(a);
        cout<<b;
        return 0;
    }
