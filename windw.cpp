#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        vector<int> win;

        if (nums.size()==0)
            return win;

        int tmpmax=nums[0];
        int loca;

        for (int i=0;i<k;i++)
        {
            win.push_back(nums[i]);
            if (nums[i]>tmpmax)
            {
                tmpmax=nums[i];
                loca=i;
            }
        }

        out.push_back(tmpmax);

        for (int i=1;i<nums.size()-k+1;i++)
        {
            if (nums[i+k-1]>tmpmax)
            {
                tmpmax=nums[i+k-1];
                loca=i+k-1;
                out.push_back(tmpmax);
                continue;
            }
            else if (nums[i+k-1]<tmpmax)
            {
                if (tmpmax==nums[i-1])
                {
                    tmpmax=nums[i];
                    for (int j=0;j<k;j++)
                    {
                        if (nums[i+j]>tmpmax)
                        {
                            tmpmax=nums[i+j];
                            loca=i+j;
                        }
                    }
                    out.push_back(tmpmax);
                }
                else
                {
                    out.push_back(tmpmax);
                }
            }
        }
        return out;
    }

int main()
{
    vector<int> a;
    maxSlidingWindow(a,0);
    return 0;
}
