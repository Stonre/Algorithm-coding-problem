#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int len=nums.size();

        if (len==0)
            return 0;
        if (len==1)
        {
            if (nums[0]==val)
                return 0;
            else
                return 1;
        }

        int high=len-1,low=0,mid=(high+low)/2;
        while (low<high)
        {
            if (nums[mid]>val)
            {
                high=mid-1;
                mid=(low+high)/2;

            }
            else if (nums[mid]<val)
            {
                low=mid+1;
                mid=(high+low)/2;

            }
            else
            {
                break;
            }
        }

        int p1=mid,p2=mid+1;
        if (p2>len-1)
            p2=len-1;
        while (true)
        {
            if (p1>=0)
            {
                if (nums[p1]==val)
                {
                    nums.erase(nums.begin()+p1);
                    if (p1-1>=0)
                        p1--;
                    if (p2-1>=0)
                        p2--;
                    len--;
                    if (len==0)
                        break;
                }
            }
            if (p2<len)
            {
                if (nums[p2]==val)
                {
                    cout<<0;
                    nums.erase(nums.begin()+p2);
                    len--;
                    if (len==0)
                        break;
                    if (p2>=len)
                        p2=len-1;
                }
            }
            if (nums[p1]!=val&&nums[p2]!=val)
                break;
        }

        return nums.size();
    }

int main()
{
    vector<int> num;
    num.push_back(4);
    num.push_back(5);
    num.push_back(5);
    int i=removeElement(num,5);
    cout<<i;
    return 0;
}
