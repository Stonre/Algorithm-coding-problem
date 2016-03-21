#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    if (len == 0)
        return 0;
    int low = prices[0];
    int high;
    int sum=0;
    for (int i = 1; i < len; i++)
        if (prices[i]>prices[i-1])
            if (i == len-1)
                sum += prices[i] - low;
            else
                continue;
        else
        {
            high = prices[i-1];
            sum = high - low + sum;
            low = prices[i];
        }
    return sum;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    cout<<maxProfit(nums);
    return 0;
}
