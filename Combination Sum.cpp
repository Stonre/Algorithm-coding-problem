#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

void sumc(vector<vector<int> >& re,vector<int> candidates,vector<int>& cur_re,int target,int sum,int index)
    {
        if (sum>target)
            return;
        if (sum==target){
            re.push_back(cur_re);
            return;
        }
        for (int i=index;i<candidates.size();i++)
        {
            cur_re.push_back(candidates[i]);
            sumc(re,candidates,cur_re,target,sum+candidates[i],i);
            cur_re.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > re;
        vector<int> cur_re;
        sort(candidates.begin(),candidates.end());
        sumc(re,candidates,cur_re,target,0,0);
        return re;
    }
void comb(vector<int> candidates, int index, int sum, int target, vector<vector<int> > &res, vector<int> &path)
    {
        if(sum>target)return;
        if(sum==target){res.push_back(path);return;}
        for(int i= index; i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            comb(candidates,i,sum+candidates[i],target,res,path);
            path.pop_back();
        }
    }
//    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once.
//        sort(candidates.begin(),candidates.end());
//        vector<vector<int> > res;
//        vector<int> path;
//        comb(candidates,0,0,target,res,path);
//        return res;
//    }
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
    re=combinationSum(candidates,310);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
