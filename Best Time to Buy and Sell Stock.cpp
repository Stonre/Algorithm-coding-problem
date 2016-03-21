#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    if (len == 0)
        return 0;
    int out[len];
    out[0] = 0;
    int minele = prices[0];

    for (int i = 1; i < len ; i++)
    {
        if (prices[i]-minele > out[i-1])
        {
            out[i] = prices[i]-minele;
            minele = min(prices[i],minele);
        }
        else
        {
            out[i] = out[i-1];
            minele = min(prices[i],minele);
        }
    }
    return out[len-1];
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);
    int re = maxProfit(nums);
    cout<<re;
    return 0;
}
