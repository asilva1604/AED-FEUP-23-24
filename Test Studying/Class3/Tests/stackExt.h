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
    return values.empty();
}

//TODO
template <class T>
T& StackExt<T>::top() {
    T* x = new T();
    if (!values.empty()) {
        *x = values.top();
    }
    return *x;
}

//TODO
template <class T>
void StackExt<T>::pop() {
    if (!values.empty()) {
        if (!minimums.empty() && minimums.top() == values.top()) {
            minimums.pop();
        }
        values.pop();
    }
}

//TODO
template <class T>
void StackExt<T>::push(const T& val) {
    if (minimums.empty() || minimums.top() >= val) minimums.push(val);
    values.push(val);
}

//TODO
template <class T>
T& StackExt<T>::findMin() {
    T* x = new T();
    if (minimums.empty()) return *x;
    *x = minimums.top();
    return *x;
}
