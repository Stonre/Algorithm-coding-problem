#include<vector>
#include<iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> re;
        if (len==2)
        {
            re.push_back(nums[1]);
            re.push_back(nums[0]);
            return re;
        }
        re.push_back(1);
        int p=1;

        for (int i=1;i<len;i++)
        {
            p*=nums[i-1];
            re.push_back(p);
        }

        p=1;
        for (int i=len-2;i>=0;i--)
        {
            p*=nums[i+1];
            re[i]*=p;
        }
        return re;
    }

int main()
{
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(0);
    nums.push_back(-2);
    vector<int> re;
    re=productExceptSelf(nums);
    for (int i=0;i<re.size();i++)
        cout<<re[i]<<" ";
    return 0;
}
