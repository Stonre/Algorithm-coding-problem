/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
	vector<int> vc;
	int index;
public:
    void parse(vector<NestedInteger> &nl){
        int len = nl.size();
        for (int i=0;i<len;i++){
            NestedInteger tmp = nl[i];
            if (tmp.isInteger()){
                vc.push_back(tmp.getInteger());
            }
            else{
                parse(tmp.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        parse(nestedList);
        index = -1;
    }

    int next() {
        return vc[++index];
    }

    bool hasNext() {
        return (index+1)<vc.size();
    }
};