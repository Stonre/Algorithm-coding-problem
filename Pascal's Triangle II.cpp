#include<vector>
#include<iostream>
using namespace std;

vector<int> getRow(int rowIndex) {
        vector<int> re(rowIndex+1,0);
        vector<int> t(rowIndex+1,0);
        t[0]=1;
        for (int i=1;i<rowIndex+1;i++)
        {cout<<9;
            re[0]=1;
            re[i]=1;
            for (int j=1;j<i;j++)
            {
                re[j]=t[j-1]+t[j];
            }
            t=re;
        }
        return re;
    }

int main()
{
    vector<int> re=getRow(0);
    for (int i=0;i<re.size();i++)
        cout<<re[i];
    return 0;
}
