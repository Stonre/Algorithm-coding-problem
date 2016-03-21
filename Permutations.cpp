#include<iostream>
#include<vector>
using namespace std;

void cur(vector<vector<int> >& re,vector<int>& cur_re,vector<int>& left,int dep)
{
    if (dep==0)
    {
        re.push_back(cur_re);
        return;
    }
    for (int i=0;i<left.size();i++)
    {
        cur_re.push_back(left[i]);
        int tmp=left[i];
        left.erase(left.begin()+i);
        cur(re,cur_re,left,dep-1);
        cur_re.pop_back();
        left.insert(left.begin()+i,tmp);
    }
}

vector<vector<int> > permute(vector<int>& nums)
{
    vector<vector<int> > re;
    vector<int> cur_re;
    if (nums.size()==0)
        return re;
    cur(re,cur_re,nums,nums.size());
    return re;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > re;
    re=permute(nums);
    for (int i=0;i<re.size();i++)
    {
        for (int j=0;j<re[i].size();j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
