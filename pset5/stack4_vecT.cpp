/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/
#include <iostream>
#include <string>
#include <vector>

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

using namespace std;

template<typename T>
struct Stack {
	vector<T> item;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
void free(stack<T> s) {
delete s;
}
template<typename T>
int size(stack<T> s) { return s->item.size(); }

template<typename T>
bool empty(stack<T> s) { return s->item.empty(); }

template<typename T>
void pop(stack<T> s) { s->item.pop_back(); }

template<typename T>
T top(stack<T> s) {
return s->item.back();
}

template<typename T>
void push(stack<T> s, T item) {
s->item.push_back(item);
DPRINT(cout << "\n" << "[DPRINT]capa =" <<s->item.capacity()<< " size =" << s->item.size() <<endl;);

}

template<typename T>
void printStack(stack<T> s) {
	if (empty(s)) return;
	stack<T> t = new Stack<T>;
	cout << top(s) << ' ';
	push(t, top(s));
	pop(s);
	printStack(s);
	while (!empty(t)) {
	push(s, top(t));
	pop(t);
	}
} // brute-force version

template<typename T>
void printStack_fromBottom(stack<T> s) {
	if(empty(s)) return;
	T x = top(s);
	pop(s);
	printStack_fromBottom(s);
	cout << x << " ";
	push(s, x);
}

int main () { // stack initialization using range-based for
// int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
string list[] = {"to", "be", "or", "not", "to", "-", "be", \
"-", "-", "that", "-", "-", "-", "is"};
stack<string> v = new Stack<string>;
for (auto item : list) { // to be not that or be (5 6 4 7 3 2)
if (item != "-") { // type specific
push(v, item);
}else {
cout << top(v) << ' ';
pop(v);
}
}
cout << "\nsize: " << size(v); // 2
cout << "\ntop : " << top(v); // is (8)
cout << "\nstack T: "; printStack(v); // is to (8 1)
cout << "\nstack B: "; printStack_fromBottom(v); // to is (1 8)
cout << "\nHappy Coding";
free(v);
}
