
/*

Implement a getMin using stack with pop() method with O(1) time and O(1) space

https://www.youtube.com/watch?v=QMlDCR9xyd8

algorithm:
----------

Initialize a stack.
push() // push to the top of the stack
    Use a local int variable (min) to hold the min value in the stack
    For 1st push, add element to stack and also set min to it.
    if the new element added is less than min variable
        instead of inserting new element calculate new min using formula (2 * element - min)
        update min with the element passed in
    if new element added is greater/equal than min variable
        add the element at the top of the stack.

pop()   // pop will pop from the top of the stack
    if empty stack: return underflow
    if current (top of stack) >= min: return current (top of stack)
    if current (top of stack) < min: min = (2*min - current), return min; pop()


getMin()
    return min
*/

#include <iostream>
#include <stack>


using namespace std;

class mystack {
    stack<int> mystack;
    int min;
    public:
    int getMin() {return min;};

    void push(int number) {
        if (mystack.size() == 0) {
            min = number;
            mystack.push(number);
        } else if (number < min) {
            mystack.push(2 * number - min);
            min = number;
        } else if (number >= min) {
            mystack.push(number);
        }
        
    }

    int pop() {
        int tmp;
        if (mystack.empty()) {
            cout << "underflow" << endl;
            return 0;
        } else if (mystack.top() >= min) {
            tmp = mystack.top();
            mystack.pop();
        } else if (mystack.top() < min) {
            min = 2 * min - mystack.top();
            pop();
            tmp = min;
        }
        return tmp;
    }
};


int main() {
    class mystack st;

    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(10);

    cout << st.getMin() << endl;

    st.pop();
    //cout << st.getMin() << endl;

    return 0;
}

