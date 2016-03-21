#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

void sumc(vector<vector<int> >& re,vector<int> candidates,vector<int>& cur_re,int target,int sum,int index)
    {
        if (sum>target)
            return;
        if (sum==target){
            re.push_back(cur_re);
            return;
        }
        if (index>=candidates.size())
            return;
        for (int i=index;i<candidates.size();)
        {
            cur_re.push_back(candidates[i]);
            sumc(re,candidates,cur_re,target,sum+candidates[i],i+1);
            cur_re.pop_back();
            if (i<candidates.size()-1)
                while (candidates[i+1]==candidates[i])
                    i++;
            i++;
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > re;
        vector<int> cur_re;
        sort(candidates.begin(),candidates.end());
        sumc(re,candidates,cur_re,target,0,0);
        return re;
    }

int main()
{
    vector<vector<int> > re;
    vector<int> candidates;
    ifstream fin("incombination sum.txt");
    while(!fin.eof())
    {
        int a;
        fin>>a;
        candidates.push_back(a);
    }
    re=combinationSum2(candidates,2);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
