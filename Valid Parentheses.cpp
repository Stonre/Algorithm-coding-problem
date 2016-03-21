#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isValid(string s) {
        vector<char> judg;
        judg.push_back(s[0]);

        for (int i=1;i<s.size();i++)
        {
            char tmp=judg[judg.size()-1];
            if ((tmp==char(s[i]-1)||tmp==char(s[i]-2)))
            {
                judg.pop_back();
            }
            else
            {
                judg.push_back(s[i]);
            }
        }
        if (judg.size()==0)
            return true;
        else
            return false;
    }

int main()
{
    vector<char> j;
    string s="{[]}(}}";
    bool c=isValid(s);
    cout<<c;
    return 0;
}
