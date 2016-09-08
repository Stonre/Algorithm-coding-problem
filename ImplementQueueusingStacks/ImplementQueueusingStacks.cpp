#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
	stack<int> stk1;
	stack<int> stk2;

public:
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
    	int len = stk1.size();
        if (stk2.empty())
        	for (int i=0;i<len;i++){
        		stk2.push(stk1.top());
        		stk1.pop();
        	}
        stk2.pop();
    }

    // Get the front element.
    int peek(void) {
    	int len = stk1.size();
        if (stk2.empty())
        	for (int i=0;i<len;i++){
        		stk2.push(stk1.top());
        		stk1.pop();
        	}
        return stk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty()&&stk2.empty();
    }
};

int main(){
	Queue* q = new Queue();
	q->push(1);
	q->push(2);
	int tm = q->peek();
	cout<<tm;

	return 0;
}