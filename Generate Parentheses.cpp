#include<iostream>
#include<vector>
using namespace std;

void cur(vector<string>& re,string& cur_re,int leftn,int rightn)
    {
        if (leftn==0&&rightn==0)
        {
            re.push_back(cur_re);
            return;
        }
        else
        {
            if (leftn>rightn)
                return;
            if (leftn!=0)
            {
                cur_re.push_back('(');
                cur(re,cur_re,leftn-1,rightn);
                cur_re.erase(cur_re.end()-1);
            }
            cur_re.push_back(')');
            cur(re,cur_re,leftn,rightn-1);
            cur_re.erase(cur_re.end()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        string cur_re;
        cur(re,cur_re,n,n);
        return re;
    }
int main()
{
    vector<string> re;
    re=generateParenthesis(3);
    for (int i=0;i<re.size();i++)
        cout<<re[i]<<endl;
    return 0;
}
