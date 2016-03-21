#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void sxun(vector<string> &out, string digits, int arr[], int loca)
{
    vector<string> p;
    int pn[8]={3,3,3,3,3,4,3,4};
    p.push_back("abc");
    p.push_back("def");
    p.push_back("ghi");
    p.push_back("jkl");
    p.push_back("mno");
    p.push_back("pqrs");
    p.push_back("tuv");
    p.push_back("wxyz");
    int len=array.size();
    char* s;
    if (loca==len-1)
    {
        for (int j=0;j<arr[i];j++)
        {
            for (int i=0;i<len;i++)
            {
                s[i]=p[digits[i]-50][j];
            }
            out.push_back(s);
        }
    }

    for (int j=0;j<arr[i];j++)
    {
        sxun(out,digits,arr,loca+1);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> p;
    vector<string> out;
    int len=digits.size();
    int nums[len];

    int pn[8]={3,3,3,3,3,4,3,4};
    p.push_back("abc");
    p.push_back("def");
    p.push_back("ghi");
    p.push_back("jkl");
    p.push_back("mno");
    p.push_back("pqrs");
    p.push_back("tuv");
    p.push_back("wxyz");

    for (int i=0;i<len;i++)
    {
        nums[i]=pn[digits[i]-50];
    }

    for (int j=0;j<nums[0];j++)
    {
        sxun(out,digits,nums,0,1);
    }
    return out;
}

int main()
{
    return 0;
}
