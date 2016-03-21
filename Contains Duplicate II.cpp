#include<iostream>
#include<map>
#include<hashtable.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()<2)
            return 0;
        map<int,int> nummap;
        for (int i=0;i<nums.size();i++)
        {
            if(nummap.count(nums[i]))
            {
                map<int,int>::iterator lit=nummap.find(nums[i]);
                int j=lit->second;
                if (i-j<=k)
                    return true;
                else
                    nummap.erase(lit);
            }
            nummap.insert(pair<int,int>(nums[i],i));
        }
        return false;
    }

int main()
{
    map<int,int> nummap;
    nummap.insert(pair<int,int>(5,1));
    nummap.insert(pair<int,int>(4,2));
    nummap.insert(pair<int,int>(5,3));
    nummap.insert(pair<int,int>(5,4));
    nummap.insert(pair<int,int>(4,5));

    map<int,int>::iterator lit=nummap.find(5);
    cout<<nummap[0];
    return 0;
}
