#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> >& re,int dep,int num,vector<int>& cur_re,int k,int n)
    {
        if (dep==k)
        {
            re.push_back(cur_re);
            return;
        }
        for (int i=num;i<=n-k+dep+1;i++)
        {
            cur_re.push_back(i);
            dfs(re,dep+1,i+1,cur_re,k,n);
            cur_re.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > re;
        vector<int> cur_re;

        dfs(re,0,1,cur_re,k,n);
        return re;
    }

int main()
{
    vector<vector<int> > re;
    re=combine(4,2);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j];
        cout<<endl;
    }
    return 0;
}
