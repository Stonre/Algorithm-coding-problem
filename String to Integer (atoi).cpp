#include "pack.h"
#include <limits.h>

    int myAtoi(string str) {
        int len = str.size();
        if (len==0) return 0;
        long long ans = 0;
        int sign = 1;
        int l = 0;
        while (str[l]==' ') l++;
        if (str[l]=='-') sign=-1,l++;
        else if (str[l]=='+') l++;
        for (int i=l;i<len;i++){
            if (str[i]-'0'>=0&&str[i]-'0'<=9)
                ans = ans*10 + (str[i] - '0');
            else
                break;
        }
        ans = ans*sign;
        if (ans>INT_MAX)
            return INT_MAX;
        if (ans<INT_MIN)
            return INT_MIN;
        return ans;
    }

    int main()
    {
        string str = "   123*(99868";
        cout<<myAtoi(str);
        return 0;
    }
