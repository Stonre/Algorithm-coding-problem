#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;

string inttostring(int num)
{
    stringstream ss;
    string s;
    ss<<num;
    ss>>s;
    return s;
}

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> re;
    int len = nums.size();
    string s;
    int k = 0;

    if (len==0)
        return re;
    if (len==1)
    {
        s = inttostring(nums[0]);
        re.push_back(s);
        return re;
    }
    s = inttostring(nums[k]);
    while (k<len-1)
    {
        int cont = 0;
        while (nums[k] == nums[k+1]-1)
        {
            k++;
            cont++;
        }
        if (cont>0)
            s = s + "->" + inttostring(nums[k]);
        k++;
        re.push_back(s);
        if (k == len)
            return re;
        s = inttostring(nums[k]);
        if (k == len-1)
        {
            re.push_back(s);
            return re;
        }
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);nums.push_back(2);nums.push_back(4);nums.push_back(7);
    vector<string> re = summaryRanges(nums);
    for (int i=0;i<re.size();i++)
        cout<<re[i]<<endl;
    return 0;
}
