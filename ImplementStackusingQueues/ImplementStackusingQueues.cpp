#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
	queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
    	int len = q.size();
    	for (int i=0;i<len-1;i++){
    		q.push(q.front());
    		q.pop();
    	}
    	q.pop();
    }

    // Get the top element.
    int top() {
    	int len = q.size();
    	for (int i=0;i<len-1;i++){
    		q.push(q.front());
    		q.pop();
    	}
    	int out = q.front();
    	q.push(out);
    	q.pop();
    	return out;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

int main(){
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.pop();
	int re = stk.top();
	cout<<re;

	return 0;
}