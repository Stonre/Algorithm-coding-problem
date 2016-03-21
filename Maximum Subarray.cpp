#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int len=nums.size();
    vector<int> cont(len,0);
    cont[0]=nums[0];
    for (int i=1;i<len;i++)
    {
        if (nums[i]<=0)
            cont[i]=cont[i-1];
        else
        {
            int sum=nums[i];
            cont[i]=cont[i-1];
            for (int j=i-1;j>=0;j--)
            {
                cout<<sum<<endl;
                if (sum>cont[i])
                    cont[i]=sum;
                sum+=nums[j];
            }
            if (sum>cont[i])
                cont[i]=sum;
            cout<<endl;
        }
    }
    return cont[len-1];
}

int main()
{
    vector<int> nums;
    nums.push_back(-2);
        nums.push_back(1);
            nums.push_back(-3);
                nums.push_back(4);
                    nums.push_back(-1);
                        nums.push_back(2);
                            nums.push_back(1);
                                nums.push_back(-5);
                                    nums.push_back(4);
    int re=maxSubArray(nums);
    cout<<re;
    return 0;
}
