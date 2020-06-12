/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/
#include <iostream>
#include <stack>


using namespace std;

void printStack(stack<string> s) {
	if (s.empty()) return;
	stack<string> t;
	cout << s.top() << ' ';
	t.push(s.top());
	s.pop();size;
	printStack(s);
	while (!t.empty()) {
	s.push(t.top());
	t.pop();
	}
} // brute-force version
void printStack_fromBottom(stack<string> s) {
	if(s.empty()) return;
	string x = s.top();
	s.pop();
	printStack_fromBottom(s);
	cout << x << " ";
	s.push(x);
}

int main () { // stack initialization using range-based for
// int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
string list[] = {"to", "be", "or", "not", "to", "-", "be", \
"-", "-", "that", "-", "-", "-", "is"};
stack<string> s;
for (auto item : list) { // to be not that or be (5 6 4 7 3 2)
if (item != "-") // type specific
s.push(item);
else {
cout << s.top() << ' ';
s.pop();
}
}
cout << "\nsize: " << s.size(); // 2
cout << "\ntop : " << s.top(); // is (8)
cout << "\nstack T: "; printStack(s); // is to (8 1)
cout << "\nstack B: "; printStack_fromBottom(s); // to is (1 8)
cout << "\nHappy Coding";
}
