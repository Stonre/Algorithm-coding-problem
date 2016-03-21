#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string pre;
        pre=strs[0];

        for (int i=1;i<strs.size();i++)
        {
            for (int j=0;j<pre.size();j++)
            {
                if (pre[j]==strs[i][j])
                    continue;
                else
                {
                    pre=pre.substr(0,j);
                    break;
                }
            }
        }
    return pre;
}

int main()
{

    return 0;
}
