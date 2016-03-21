#include "pack.h"

int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    if (len < 2)
        return 0;
    int buys[len];
    int sells[len];
    sells[0]=0;sells[1]=max(0, prices[1] - prices[0]);
    buys[0]= -prices[0];buys[1]=max(-prices[0], -prices[1]);

    for (int i = 2 ; i < len ; i++)
    {
        sells[i] = max(sells[i-1], buys[i-1] + prices[i]);
        buys[i] = max(buys[i-1], sells[i-2] - prices[i]);
    }
    return sells[len-1];
}
