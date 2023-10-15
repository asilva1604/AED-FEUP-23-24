# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//=============================================================================
// Exercise 3: StackExt class
//=============================================================================
//TODO
template <class T>
bool StackExt<T>::empty() const {
    return values.empty() && minimums.empty();
}

//TODO
template <class T>
T& StackExt<T>::top() {
    if (values.empty()) throw std::runtime_error("Stack is empty");;
    return values.top();
}

//TODO
template <class T>
void StackExt<T>::pop() {
    if (values.empty()) return;
    if (values.top() == minimums.top()) {
        minimums.pop();
        values.pop();
        return;
    }
    values.pop();
}

//TODO
template <class T>
void StackExt<T>::push(const T& val) {
    values.push(val);
    if (val <= minimums.top()) minimums.push(val);
}

//TODO
template <class T>
T& StackExt<T>::findMin() {
    if (minimums.empty()) throw std::runtime_error("Stack is empty");;
    return minimums.top();
}
