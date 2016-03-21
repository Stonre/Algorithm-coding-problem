#include "pack.h"

class ValidWordAbbr
{
public:
    map<string,string> maplist;
    ValidWordAbbr(vector<String> &dictionary)
    {
        int len = dictionary.size();
        for (int i=0;i<len;i++)
        {
            string tmp = generateabbr(dictionary[i]);
            if (maplist.count(tmp)!=0)
                map.insert(pair<string,string>(tmp,dictionary[i]));
        }
    }
    string generateabbr(string s)
    {
        int len = s.size();
        string re;
        if (len <= 2)
            return s;
        re.push_back(s[0]);
        re = re + to_String(len-2);
        re.push_back(s[len-1]);
        return re;
    }
    bool isUnique(string word)
    {
        string tmp = generateabbr(word);
        if (map.count(tmp))

            return 0;
        else
            return 1;
    }
};

int main()
{

}
