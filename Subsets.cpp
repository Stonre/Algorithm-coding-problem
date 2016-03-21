#include<iostream>
#include<vector>
using namespace std;

void cur(vector<vector<int> >& re,vector<int>& cur_re,vector<int> nums,int left,int ss)
{
    if (left==0)
    {
        re.push_back(cur_re);
        return;
    }
    for (int i=ss;i<=nums.size()-left;i++)
    {
        cur_re.push_back(nums[i]);
        cur(re,cur_re,nums,left-1,i+1);
        cur_re.pop_back();
        while (nums[i]==nums[i+1]) {i++;}
    }
}
vector<vector<int> > subsets(vector<int>& nums)
{
    vector<int> cur_re;
    vector<vector<int> > re;
    re.push_back(cur_re);
    if (nums.size()==0)
        return re;

    for (int i=0;i<nums.size();i++)
    {
        cur(re,cur_re,nums,i+1,0);
    }
    return re;
}

int main()
{
    vector<vector<int> > re;
    vector<int> cur_re;
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    re=subsets(num);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
