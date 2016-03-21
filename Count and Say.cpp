#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n)
{
    if (n==0)
        return "";
    string re="1";
    string cont;
    for (int i=0;i<n-1;i++)
    {
        int num=1;
        for (int j=0;j<re.size();)
        {
            while (re[j]==re[j+1]) {j++;num++;}
            cont.push_back('0'+num);
            cont.push_back(re[j]);
            j++;
            num=1;
        }
        re.assign(cont);
        cout<<re<<endl;
        cont.clear();
    }
    return re;
}

//string countAndSay(int n) {
//     string temp, result;
//     result.push_back('1');
//
//     char currentChar;
//     int count;
//
//     for(int i = 1; i < n; i++) {
//         temp = result;
//         result.clear();
//         currentChar = temp[0];
//         count = 1;
//         for(int j = 1; j < temp.size(); j++) {
//             if(temp[j] == currentChar) {
//                 count++;
//             }
//             else {
//                 result.push_back('0' + count);
//                 result.push_back(currentChar);
//                 currentChar = temp[j];
//                 count = 1;
//             }
//         }
//         result.push_back('0' + count);
//         result.push_back(currentChar);
//     }
//     return result;
// }
int main()
{
    string c=countAndSay(6);
    cout<<c;
    return 0;
}
