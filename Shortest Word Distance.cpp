#include "pack.h"

int shortestDistance(vector<string>& words, string word1, string word2) {
    int loca1=-1;
    int loca2=-1;
    int dis = words.size()-1;

    for (int i=0;i<words.size();i++)
    {
        if (words[i]==word1)
        {
            loca1 = i;
            if (i - loca2 < dis && loca2>=0)
                dis = loca1 - loca2;
        }
        if (words[i]==word2)
        {
            loca2 = i;
            if (i - loca1 < dis&& loca1>=0)
                dis = loca2 - loca1;
        }
        cout<<loca1<<" "<<loca2<<endl;
    }
    return dis;
}

int main()
{
    vector<string> words;
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("d");
    words.push_back("d");
    int dis = shortestDistance(words,"a","d");
    cout<<dis;
    return 0;
}
