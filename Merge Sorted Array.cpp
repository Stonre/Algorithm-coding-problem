#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a;
    a.push_back(6);
    a.push_back(5);
    a.erase(a.begin());
    cout<<a[0];
    return 0;
}
