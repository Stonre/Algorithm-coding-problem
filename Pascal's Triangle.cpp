#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
        vector<vector<int> > re;
        vector<int> v(1,1);
        re.push_back(v);
        for (int i=1;i<numRows;i++)
        {
            vector<int> u(i+1,0);
            u[0]=1;
            u[i]=1;
            for (int j=1;j<i;j++)
            {
                u[j]=v[j-1]+v[j];
            }
            re.push_back(u);
            v=u;
            u.clear();
        }
        return re;
    }

int main()
{
    vector<vector<int> > re;
    re=generate(5);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j];
        cout<<endl;
    }
    return 0;
}
