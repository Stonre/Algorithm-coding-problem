#include "pack.h"
#include "tree.h"

int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.size();
        map <char,int> maplist;
        if (len==0 || len==1)
            return len;
        int left = 0, right = 1, maxlen=1, lentmp = 1;
        maplist.insert(pair<char,int> (s[left],1));
        while (right <= len-1){
            if (maplist.size() > 2){
                maplist[s[left]]--;
                lentmp--;
                cout<<maplist[s[left]]<<" ";
                if (maplist[s[left]]==0)
                    maplist.erase(maplist.find(s[left]));
                left++;
                continue;
            }
            if (maplist.count(s[right])){
                maplist[s[right]]++;
                lentmp++;
                maxlen = max(maxlen,lentmp);
                right++;
            }
            else{
                maplist.insert(pair<char,int> (s[right],1));
                right++;
                lentmp++;
                if (maplist.size()<=2)
                    maxlen = max(maxlen,lentmp);
            }
        }
        return maxlen;
    }

int main()
{
    TreeNode *t;
    if (t && t->left)
        return 3;
    return 0;
}
