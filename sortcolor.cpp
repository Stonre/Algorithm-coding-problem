#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums) {
        int len=nums.size();

        for (int i=0;i<len,i++)
        {
            if (nums[i]!=0)
                continue;
            else
            {
                int k=i-1;
                while (k>0 && nums[k]!=0)
                {
                    k--;
                }
                int tmp=nums[k+1];
                nums[k+1]=nums[i];
                nums[i]=tmp;
            }
        }
    }

int main()
{
    vector<int> a;
    a.push_back(9);
    a[0]=8;
    cout<<a[0];
    return 0;
}
