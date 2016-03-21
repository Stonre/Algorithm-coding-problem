#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        if (nums.size()<3) return result;
        int target=0;
        sort(nums.begin(),nums.end());
        for (int head=0;head<nums.size();head++)
        {
            while(head!=0&&nums[head]==nums[head-1]) head++;
            target=0;
            vector<int> one;
            one.push_back(nums[head]);
            target=target-nums[head];
            map <int,int> nummap;
            int flag=nums[nums.size()-1]+1;
            for (int i=head+1;i<nums.size();i++)
            {
                if (nummap.count(target-nums[i])&&nums[i]!=flag)
                {
                    flag=nums[i];
                    one.push_back(nums[nummap[target-nums[i]]]);
                    one.push_back(nums[i]);
                    result.push_back(one);
                    one.pop_back();
                    one.pop_back();
                }
                if (!nummap.count(nums[i]))
                {
                    nummap.insert(pair<int,int>(nums[i],i));
                }
            }
        }
        return result;
    }

int main()
{
    ifstream fin("in.txt");
    vector <int> nums;
    int num_tmp;
    while(!fin.eof())
    {
        fin>>num_tmp;
        nums.push_back(num_tmp);
    }
//    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    vector<vector<int> > result=threeSum(nums);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++) cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
