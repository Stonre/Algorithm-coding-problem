#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

void cur(vector<vector<int> >& re,vector<int> cur_re,int k,int dep,int index,int sum,int target)
{
    if (dep==k)
    {
        if (sum==target)
        {
            re.push_back(cur_re);
            return;
        }
        else
            return;
    }
    if (sum>target)
        return;
    for (int i=index;i<10;i++)
    {
        cur_re.push_back(i);
        cur(re,cur_re,k,dep+1,i+1,sum+i,target);
        cur_re.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k,int n)
{
    vector<vector<int> > re;
    vector<int> cur_re;
    cur(re,cur_re,k,0,1,0,n);
    return re;
}

int main()
{
    vector<vector<int> > re;
    vector<int> candidates;
    re=combinationSum3(3,9);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
