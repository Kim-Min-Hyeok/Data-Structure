/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/
#include <iostream>
#include <string>

using namespace std;

struct Stack {
string *item;
int N;
int capacity;
};

using stack = Stack *;

stack newStack(int capacity) {
stack s = new Stack;
s->item = new string[capacity];
s->N = 0;
s->capacity = capacity;
return s;
}
void free(stack s) {
delete[] s->item;
delete s;
}
int size(stack s) { return s->N; }
bool empty(stack s) { return s->N == 0; }
void pop(stack s) { s->N--; }
string top(stack s) {
return s->item[s->N - 1];
}
void push(stack s, string item) {
s->item[s->N++] = item;
}
void printStack(stack s) {
	if (empty(s)) return;
	stack t = newStack(size(s));
	cout << top(s) << ' ';
	push(t, top(s));
	pop(s);
	printStack(s);
	while (!empty(t)) {
	push(s, top(t));
	pop(t);
	}
} // brute-force version
void printStack_fromBottom(stack s) {
	if(empty(s)) return;
	string x = top(s);
	pop(s);
	printStack_fromBottom(s);
	cout << x << " ";
	push(s, x);
}

int main () { // stack initialization using range-based for
// int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
string list[] = {"to", "be", "or", "not", "to", "-", "be", \
"-", "-", "that", "-", "-", "-", "is"};
stack s = newStack(sizeof(list)/sizeof(string));
for (auto item : list) { // to be not that or be (5 6 4 7 3 2)
if (item != "-") // type specific
push(s, item);
else {
cout << top(s) << ' ';
pop(s);
}
}
cout << "\nsize: " << size(s); // 2
cout << "\ntop : " << top(s); // is (8)
cout << "\nstack T: "; printStack(s); // is to (8 1)
cout << "\nstack B: "; printStack_fromBottom(s); // to is (1 8)
cout << "\nHappy Coding";
}
